
#include "tcp.h"


void prepareMsg(char *msg,empRec_t *rec,int *len,int cmd);
void strip_newline(char *name);
void format(char *buf,empRec_t *rec);

void errExit(char *str)
{
  puts(str);
  exit(0);
}  

main()
{
  int cmd,Id,len,srvport,indx;
  char ipaddr[20];
  char txmsg[MSG_LEN],rxmsg[MSG_LEN];
  int sockFd,response,cliLen;      
  empRec_t *rec;
  rec= malloc(sizeof(empRec_t));
  
  /********************* opening of server socket ****************/

  if( (sockFd = socket(AF_INET,SOCK_STREAM,0)) < 0 )
      errExit("Can't open datagram socket\n");

    printf("Enter server port number:");
    scanf("%d",&srvport);
    printf("Enter server ip address:");
    scanf("%s",ipaddr);
  
    memset(&srvAdr,0,sizeof(srvAdr));
    srvAdr.sin_family = AF_INET;
    srvAdr.sin_addr.s_addr = inet_addr(ipaddr);
    srvAdr.sin_port = htons(srvport);
    
    if(connect(sockFd,(struct sockaddr *)&srvAdr,sizeof(srvAdr)) < 0)
       errExit("Can't connect to server\n");
    
  
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
	   sprintf(txmsg,"%d|%d|%s|%d|%d|",cmd,rec->Id,rec->name,rec->salary,rec->phNum);
	   len = strlen(txmsg);
           send(sockFd,txmsg,len,0);
	   
           printf("waiting for response\n");
	   recv(sockFd,rxmsg,4,0);
	   sscanf(rxmsg,"%d",&response);
	   
	   if(response==0)
	     printf("\t\tRECORD ADDED SUCCESSFULLY\n");
	   else
	     printf("\t\tDATA BASE FULL ERROR\n");
           break;

	 	   
     case 2:
          printf("Enter employee Id:");
	  scanf("%d",&Id);
	  sprintf(txmsg,"%d|%d|",cmd,Id);
	  len = strlen(txmsg);
	  
           send(sockFd,txmsg,len,0); 
           printf("waiting for response\n");
	   
	   recv(sockFd,rxmsg,4,0);
	   sscanf(rxmsg,"%d",&response);
	   
	   if(response==0)
	     printf("\t\tRECORD DELETED SUCCESSFULLY\n");
	   else
	     printf("\t\tNOT FOUND ERROR OR DATA BASE FULL ERROR\n");
           break;
     case 3:
          printf("Enter employee Id:");
	  scanf("%d",&Id);
	  sprintf(txmsg,"%d|%d|",cmd,Id);
	  len = strlen(txmsg);
	  
          send(sockFd,txmsg,len,0); 
          printf("waiting for response\n");
	   
	  recv(sockFd,rxmsg,MSG_LEN,0);
	  sscanf(rxmsg,"%d",&response);
	  if(response==0)
	  {
             format(rxmsg,rec);
	     printf("Id:%d | Name:%s | Salary:%d | phNum:%d\n",rec->Id,rec->name,rec->salary,rec->phNum);
	  }   
	  else
	     printf("\t\tRECORD NOT FOUND\n");
          break;
     case 4:
	   fillRec(rec);
	 	   
	   sprintf(txmsg,"%d|%d|%s|%d|%d|",cmd,rec->Id,rec->name,rec->salary,rec->phNum);
	   len = strlen(txmsg);
	   send(sockFd, txmsg, len, 0);
           printf("waiting for response\n");

           recv(sockFd, rxmsg, 4, 0);      
	   sscanf(rxmsg,"%d",&response);
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
    int n;
    char *name;
    name=malloc(20);
    printf("\nEnter Id:");
    scanf("%d",&(rec1->Id));
    printf("Enter Name:");
    __fpurge(stdin);
    fgets(rec1->name,20,stdin);
    strip_newline(rec1->name);
    //scanf("%s",rec->name);
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
   
void format(char *buf,empRec_t *rec)
{
   int response;
   char *temp;
   temp=malloc(20);
   temp=(char *)strtok(buf,"|");
   response=atoi(temp);

   temp=(char *)strtok(NULL,"|");
   rec->Id=atoi(temp);
   
   temp=(char *)strtok(NULL,"|");
   strcpy(rec->name,temp);
   
   temp=(char *)strtok(NULL,"|");
   rec->salary=atoi(temp);
   
   temp=(char *)strtok(NULL,"|");
   rec->phNum=atoi(temp);
   
}   
