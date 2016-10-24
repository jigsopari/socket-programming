//#include <sys/ipc.h
//#include <sys/msg.h>
#include "udp.h"

void extract(char *buf,empRec_t *rec);

void errExit(char *str)
{
  puts(str);
  exit(0);
}
 main()
{
  int cmd,Id,indx;
  int response,port;
  int sockFd,fileFd;
  int cliLen,len;
  char rxmsg[MSG_LEN],txmsg[MSG_LEN];
  struct sockaddr_in srvAdr,cliAdr;
  empRec_t *sRec;
  sRec=malloc(sizeof(empRec_t));
  
  /****************** socket creation ****************/
  if( (sockFd = socket(AF_INET,SOCK_DGRAM,0)) < 0 )
    errExit("Can't open datagram socket\n");

  printf("Enter the server port number:");
  scanf("%d",&port);

  memset((struct sockaddr *)&srvAdr,0,sizeof(srvAdr));
  srvAdr.sin_family = AF_INET;
  srvAdr.sin_addr.s_addr = htonl(INADDR_ANY);
  srvAdr.sin_port = htons(port);
  printf("port:%d",srvAdr.sin_port);
  if(bind(sockFd,(struct sockaddr *)&srvAdr,sizeof(srvAdr)) < 0)
    errExit("Can't bind local address\n");

	
  /**********************file creation*************************/
  
       fileFd = open("file",O_RDWR);
       if(fileFd < 0)
       {
         printf("creating file ....\n");
	 
         fileFd = open("file",O_CREAT|O_RDWR,0666); 
         if(fileFd < 0)
	 {
	    printf("could not create file\n");
	    exit(1);
	 }
       }	 


  //printf("server waiting for message\n");
  //while(1)
  do
  {
    printf("Server : Waiting for message\n");
    cliLen = sizeof(cliAdr);
    len = recvfrom(sockFd, rxmsg, MSG_LEN,0,(struct sockaddr *)&cliAdr,&cliLen);
    if(len)
    {
       memcpy(&cmd,&rxmsg[0],4);
       printf("Received message\n");
       switch(cmd)
       {
         case 1:
	      extract(rxmsg,sRec);
	      response=addNewStudentRec(fileFd,sRec);
	      printf("connected to client: %s\n",inet_ntoa(cliAdr.sin_addr));
	      
	      memcpy(&txmsg[0],&response,4);
              if(sendto(sockFd,txmsg,4,0,(struct sockaddr *)&cliAdr,cliLen) != 4)
	      printf("sendto error\n");
	      else
	        printf("Response was sent to client\n");
	      break;
	  case 2:
	       memcpy(&Id,&rxmsg[4],4);
               response=deleteStudentRec(fileFd,Id);
	      printf("connected to client: %s\n",inet_ntoa(cliAdr.sin_addr));
	       
	      memcpy(&txmsg[0],&response,4);
              if(sendto(sockFd,txmsg,4,0,(struct sockaddr *)&cliAdr,cliLen) != 4)
	        printf("sendto error\n");
	      else
	        printf("Response was sent to client\n");
	       	 
	      break;
	  case 3:
	       memcpy(&Id,&rxmsg[4],4);
               response=getEmpDetails(fileFd,Id,sRec);
	       
	      printf("connected to client: %s\n",inet_ntoa(cliAdr.sin_addr));
	         if(response==0)
	         {
                    int indx=0;
	            memcpy(&txmsg[indx],&response,4);
                    indx+=4;
                    memcpy(&txmsg[indx],&sRec->Id,4); 
                    indx+=4;
                    strcpy(&txmsg[indx],sRec->name); 
                    indx=indx+strlen(sRec->name)+1;
                    memcpy(&txmsg[indx],&sRec->salary,4); 
                    indx+=4;
                    memcpy(&txmsg[indx],&sRec->phNum,4); 
                    indx+=4;
		   
                    if(sendto(sockFd,txmsg,indx,0,(struct sockaddr *)&cliAdr,cliLen) != indx)
	               printf("sendto error\n");
	            else
	               printf("Response was sent to client\n");
	         }
	         else
	         {
	            memcpy(&txmsg[0],&response,4);
		    indx+=4;
                    if(sendto(sockFd,txmsg,4,0,(struct sockaddr *)&cliAdr,cliLen) != 4)
	               printf("sendto error\n");
	            else
	               printf("Response was sent to client\n");
	         }
               		
	      break;
	  case 4:
	      extract(rxmsg,sRec);
               response=modifyEmpDetails(fileFd,sRec);
	      printf("connected to client: %s\n",inet_ntoa(cliAdr.sin_addr));
	       
	      memcpy(&txmsg[0],&response,4);
              if(sendto(sockFd,txmsg,4,0,(struct sockaddr *)&cliAdr,cliLen) != 4)
	         printf("sendto error\n");
	      else
	         printf("Response was sent to client\n");
	       
	      break;
        }
     }
   }
   while(len);
   //close(srvFd);
}   

int addNewStudentRec(int fd,empRec_t *ps)
{
    int len;
    empRec_t trec;
    lseek(fd,0,SEEK_SET);

    while(1)
    {
      len=read(fd,&trec,REC_SIZE);
      if(len!=REC_SIZE)
      {	      
        write(fd,ps,REC_SIZE);
        return SUCCESS;
      }
      else 
      {
       if(trec.Id==-1)
       {
    	 lseek(fd,-1*REC_SIZE,SEEK_CUR);
	 write(fd,ps,REC_SIZE);
	 return SUCCESS;
        }
        continue;
       } 
    }
 }  
int deleteStudentRec(int fd,int empId)
{
   int len;
   empRec_t rec;
   
   lseek(fd,0,SEEK_SET);
   len=read(fd,&rec,REC_SIZE);
   
   while(len==REC_SIZE)
   {
	//if(len!=REC_SIZE)
	  //return NOT_FOUND;
	//break;
	if(rec.Id==empId)
	{
	  rec.Id = -1;
	  lseek(fd,REC_SIZE*-1,SEEK_CUR);
	  write(fd,&rec,REC_SIZE);
	  return SUCCESS;
        }
	else
        len=read(fd,&rec,REC_SIZE);
   }
   return NOT_FOUND;
}	
int getEmpDetails(int fd,int empId,empRec_t *temp)
{
   int len;
   lseek(fd,0,SEEK_SET);
   len=read(fd,temp,REC_SIZE);
   
   while(len==REC_SIZE)
   {
      if(temp->Id==empId)
        return SUCCESS;
      else
      {
        len=read(fd,temp,REC_SIZE);
        continue;
      }
   }
   return NOT_FOUND;
}
int modifyEmpDetails(int fd,empRec_t *emp)
{
   int len;
   empRec_t *temp;
   temp=malloc(sizeof(empRec_t));
   lseek(fd,0,SEEK_SET);
   len=read(fd,temp,REC_SIZE);
   
   while(len==REC_SIZE)
   {
      if(temp->Id==emp->Id)
      {
        lseek(fd,-1*REC_SIZE,SEEK_CUR);
	write(fd,emp,REC_SIZE);
	 return SUCCESS;
      }	 
      else
      {
         len=read(fd,temp,REC_SIZE);
	 continue;
      }
    }
    return NOT_FOUND;
}   

void extract(char *buf,empRec_t *rec)
{
   int indx=4;
   memcpy(&rec->Id,&buf[indx],4); 
   indx+=4;
   strcpy(rec->name,&buf[indx]); 
   indx=indx+strlen(rec->name)+1;
   memcpy(&rec->salary,&buf[indx],4); 
   indx+=4;
   memcpy(&rec->phNum,&buf[indx],4); 
   indx+=4;
}  

