
#include "udp.h"


void prepareMsg(char *msg,empRec_t *rec,int *len,int cmd);
void strip_newline(char *name);

void errExit(char *str)
{
  puts(str);
  exit(0);
}  

main()
{
  int cmd,Id,len,srvport,indx;
  char ipaddr[14];
  char txmsg[MSG_LEN],rxmsg[MSG_LEN];
  int sockFd,response,cliLen;      
  struct sockaddr_in srvAdr,cliAdr;
  empRec_t *rec;
  rec= malloc(sizeof(empRec_t));
  
  /********************* opening of server socket ****************/

  if( (sockFd = socket(AF_INET,SOCK_DGRAM,0)) < 0 )
      errExit("Can't open datagram socket\n");

    printf("Enter server port number:");
    scanf("%d",&srvport);
    printf("Enter server ip address:");
    scanf("%s",ipaddr);
  
    memset(&srvAdr,0,sizeof(srvAdr));
    srvAdr.sin_family = AF_INET;
    srvAdr.sin_addr.s_addr = inet_addr(ipaddr);
    srvAdr.sin_port = htons(srvport);
  /*while(1)
  {
  
  printf("Enter message to send:\n");*/
  
  while(1)
  {
    printf("\t\tEmployee Details Database program ver 1\n\n");
    printf("\n\t\t1.add a  employee record");
    printf("\n\t\t2.delete a  employee record");
    printf("\n\t\t3.get a  employee details");
    printf("\n\t\t4.modify a  employee details");
    printf("\n\t\t5.exit\n\n");
    printf("\t\tEnter choice:");
    scanf("%d",&cmd);
    switch(cmd)
    {
      case 1:
	   fillRec(rec);
	   prepareMsg(txmsg,rec,&len,cmd);
         sendto(sockFd,txmsg,len,0,(struct sockaddr *)&srvAdr,sizeof(srvAdr));
	   
           printf("waiting for response\n");
	   recv(sockFd,rxmsg,4,0);
	   memcpy(&response,&rxmsg[0],4);
	   
	   if(response==0)
	     printf("\t\tRECORD ADDED SUCCESSFULLY\n");
	   else
	     printf("\t\tDATA BASE FULL ERROR\n");
           break;
     case 2:
          printf("Enter employee Id:");
	  scanf("%d",&Id);
	  memcpy(&txmsg[0], &cmd,    4);
	  memcpy(&txmsg[4], &Id,     4);

         sendto(sockFd,txmsg,8,0,(struct sockaddr *)&srvAdr,sizeof(srvAdr));
	  
          printf("waiting for response\n");
	   recv(sockFd,rxmsg,4,0);
	   
	  memcpy(&response,&rxmsg[0],4);
	  if(response==0)
	     printf("\t\tRECORD DELETED SUCCESSFULLY\n");
	  else
	     printf("\t\tRECORD NOT FOUND\n");
          break;
     case 3:
          printf("Enter employee Id:");
	  scanf("%d",&Id);
	  memcpy(&txmsg[0], &cmd,    4);
	  memcpy(&txmsg[4], &Id,     4);

         sendto(sockFd,txmsg,8,0,(struct sockaddr *)&srvAdr,sizeof(srvAdr));
	  
          printf("waiting for response\n");
	   recv(sockFd,rxmsg,MSG_LEN,0);
	  
	  memcpy(&response,&rxmsg[0],4);
	  if(response==0)
	  {
	     indx=4;
	     memcpy(&rec->Id,&rxmsg[indx],4);
	     indx+=4;
	     strcpy(rec->name,&rxmsg[indx]);
	     indx = indx + strlen(rec->name)+1;
	     memcpy(&rec->salary,&rxmsg[indx],4);
	     indx+=4;
	     memcpy(&rec->phNum,&rxmsg[indx],4);
	     indx+=4;
	     printf("Id:%d | Name:%s | Salary:%d | phNum:%d\n",rec->Id,rec->name,rec->salary,rec->phNum);
	   }  
	  else
	     printf("\t\tRECORD NOT FOUND\n");
          break;
     case 4:
	   fillRec(rec);
	   prepareMsg(txmsg,rec,&len,cmd);
         sendto(sockFd,txmsg,len,0,(struct sockaddr *)&srvAdr,sizeof(srvAdr));
	   
           printf("waiting for response\n");
	   recv(sockFd,rxmsg,4,0);
	  
	  memcpy(&response,&rxmsg[0],4); 
	   if(response==0)
	     printf("\t\tRECORD MODIFIED SUCCESSFULLY\n");
	   else
	     printf("\t\tDATA BASE EMPTY ERROR OR NOT FOUND ERROR\n");
           break;
           
     case 5:
          exit(0);
    }
  }
}  



void fillRec(empRec_t *rec1)
  {
    char *name;
    name=malloc(20);
    
    printf("\nEnter Id:");
    scanf("%d",&(rec1->Id));
    
    printf("Enter Name:");
    __fpurge(stdin);
    fgets(rec1->name,20,stdin);
    strip_newline(rec1->name);
    
    printf("Enter Salary:");
    scanf("%d",&(rec1->salary));
    
    printf("Enter phone Number:");
    scanf("%d",&(rec1->phNum));
  } 
  
void strip_newline(char *name)
  {
    int len;
    len=strlen(name);
    if(name[len-1]=='\n')
      name[len-1]=0;
   }  
   
void prepareMsg(char *msg,empRec_t *rec1,int *len,int cmd)
{
  int indx=4;
  int *msgHdr=(int *)msg;
  msgHdr[0]=cmd;
  memcpy(&msg[indx],&rec1->Id,4);
  indx+=4;
  strcpy(&msg[indx],rec1->name);
  indx=indx+strlen(rec1->name)+1;
  memcpy(&msg[indx],&rec1->salary,4);
  indx+=4;
  memcpy(&msg[indx],&rec1->phNum,4);
  indx+=4;
  *len=indx;
}  
  

