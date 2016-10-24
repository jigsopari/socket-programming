#include <stdio.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>

#define SRV_PORT_NUM 69
#define SRV_IP_ADDR  "192.168.0.13"
#define MAX_LEN      516

void  errExit(char *str)
  {
    puts(str);
    exit(0);
  }  

int main()
{
  int                choice;
  int                sockFd;
  int                fileFd;
  int                indx;
  int                len;  
  int                srvLen;  
  short              opcode;  
  short              newopcode; 
  short              errorCode;
  short              block; 
  struct sockaddr_in srvAdr;
  struct sockaddr_in cliAdr;
  char               fileName[20];
  char               mode[] = "octet";
  char               rxmsg[MAX_LEN];
  char               txmsg[MAX_LEN];
  

/******************* Client Socket opening ******************/

  sockFd = socket(AF_INET, SOCK_DGRAM, 0);
  if(sockFd < 0)
    errExit("Socket Open Error\n");

  memset(&srvAdr, 0, sizeof(srvAdr));
  srvAdr.sin_family      = AF_INET;
  srvAdr.sin_addr.s_addr = inet_addr(SRV_IP_ADDR);
  srvAdr.sin_port        = htons(SRV_PORT_NUM);
  
  /***************** File opening ***************************/

  srvLen = sizeof(srvAdr);
  while(1)
  {
    printf("\n1.Get");
    printf("  2.Put");
    printf("  3.Exit");
    printf("\nEnter choice:");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:
	     indx      =0;
	     opcode    = 1;
	     newopcode = htons(opcode);
	     memcpy(txmsg,&newopcode,2);
	     indx     += 2;
	     printf("Enter File Name:");
	     scanf("%s",fileName);
	     strcpy(&txmsg[2],fileName);
	     indx     += strlen(fileName)+1;
	     memcpy(&txmsg[indx],mode,6);
	     indx     += 6;
             
	     len = sendto(sockFd,txmsg,indx,0,(struct sockaddr *)&srvAdr,sizeof(srvAdr));
	     if(len != indx)
	       errExit("sendto request error\n");
	     
             len = recvfrom(sockFd, rxmsg, MAX_LEN, 0, (struct sockaddr *)&srvAdr, &srvLen);
             if(len == -1)
	       perror("recvfrom error\n");
	     memcpy(&opcode,rxmsg,2);
	     opcode = ntohs(opcode);
	     
	     if(opcode == 5)
	     {
	       memcpy(&errorCode,&rxmsg[2],2);
	       printf("Error Code:%hd",errorCode);
	       puts(&rxmsg[4]);
	     }
	     
	     else if(opcode == 3)
	     {
               fileFd = open(fileName,O_CREAT|O_WRONLY,0666);
	       while(1)
	       {
	         memcpy(&block,&rxmsg[2],2);
 
		 write(fileFd,&rxmsg[4],len-4);
	         if(len-4 != 512)
	           break;
 
	         opcode = 4;
	         opcode = htons(opcode);
	         memcpy(txmsg,&opcode,2);
	         memcpy(&txmsg[2],&block,2);
	         len = sendto(sockFd,txmsg,4,0,(struct sockaddr *)&srvAdr,sizeof(srvAdr));
	         if(len != 4)
	           errExit("sendto Error\n");
	         len = recv(sockFd,rxmsg,MAX_LEN,0);	 
	      }
	      printf("file received SUCCESSFULLY\n");
	    }
	  
	  break;
	  case 2:
	     indx =0;
	     opcode = 2;
	     newopcode = htons(opcode);
	     memcpy(txmsg,&newopcode,2);
	     indx += 2;
	     
	     printf("Enter File Name:");
	     scanf("%s",fileName);
	     strcpy(&txmsg[2],fileName);
	     indx += strlen(fileName)+1;
	     
	     memcpy(&txmsg[indx],mode,6);
	     indx += 6;
	     
	     len = sendto(sockFd,txmsg,indx,0,(struct sockaddr *)&srvAdr,sizeof(srvAdr));
	     if(len != indx)
	       errExit("sendto request error\n");
	     
	     len = recvfrom(sockFd,rxmsg,MAX_LEN,0,(struct sockaddr *)&srvAdr, &srvLen);
             if(len == -1)
	       perror("recvfrom error\n");
	     memcpy(&opcode,rxmsg,2);
	     opcode = ntohs(opcode);
	     if(opcode == 5)
	     {
	       memcpy(&errorCode,&rxmsg[2],2);
	       printf("Error Code:%hd",errorCode);
	       puts(&rxmsg[4]);
	     }
	     else if(opcode == 4)
	     {
               fileFd = open(fileName,O_RDONLY);
	       while(1)
	       {
	         memcpy(&block,&rxmsg[2],2);
		 block = ntohs(block);
		 printf("Block No:%hd\n",block);
 
	         opcode = 3;
	         opcode = htons(opcode);
	         memcpy(txmsg,&opcode,2);
		 block += 1;
		 block = htons(block);
	         memcpy(&txmsg[2],&block,2);
	         indx = read(fileFd,&txmsg[4],512);
	len = sendto(sockFd,txmsg,indx+4,0,(struct sockaddr *)&srvAdr,sizeof(srvAdr));
	         if(len != indx+4)
	           errExit("sendto Error\n");
	         if(indx != 512)
	            break;
	         recv(sockFd,rxmsg,MAX_LEN,0);	 
	      }
	      printf("file sent SUCCESSFULLY\n");
	    }
	  
	          
	       break;
	  case 3:
	       exit(0);
	}
      }
    }  
