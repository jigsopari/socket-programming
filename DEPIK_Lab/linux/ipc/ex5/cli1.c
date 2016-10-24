
#include <sys/ipc.h>
#include <sys/msg.h>
#include "msgq.h"


void prepareMsg(char *msg,empRec_t *rec,int *len,int cmd);
void strip_newline(char *name);

main()
{
  int cmd,Id,len,cliId,srvtype,indx;
  char txmsg[MSG_LEN],rxmsg[MSG_LEN];
  int *msgHdr=(int *)txmsg;
  empRec_t *rec;
  int mqId,response;       
  rec= malloc(sizeof(empRec_t));
  cliId=getpid();
  srvtype=SRV_MSG_TYPE;
  printf("cliend pid : %d\n",cliId);
  
  /********************* opening of Message Queue ****************/
  
           mqId=msgget(MY_KEY,0); 
           if(mqId < 0)
	   {
             printf("Error in opening the  message queue\n");
	     return(1);
	   }  
           else
	     printf("opened  message queue\n");

  
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
	   msgsnd(mqId,txmsg,len,0);
	   
           printf("waiting for response\n");
	   msgrcv(mqId,rxmsg,MSG_LEN,cliId,0);
	   memcpy(&response,&rxmsg[4],4);
	   
	   if(response==0)
	     printf("\t\tRECORD ADDED SUCCESSFULLY\n");
	   else
	     printf("\t\tDATA BASE FULL ERROR\n");
           break;
     case 2:
          printf("Enter employee Id:");
	  scanf("%d",&Id);
	  memcpy(txmsg,     &srvtype,4);
	  memcpy(&txmsg[4], &cmd,    4);
	  memcpy(&txmsg[8], &Id,     4);
	  memcpy(&txmsg[12],&cliId,  4);

	  msgsnd(mqId,txmsg,16,0);
	  
          printf("waiting for response\n");
	  msgrcv(mqId,rxmsg,MSG_LEN,cliId,0);
	  
	  memcpy(&response,&rxmsg[4],4);
	  if(response==0)
	     printf("\t\tRECORD DELETED SUCCESSFULLY\n");
	  else
	     printf("\t\tRECORD NOT FOUND\n");
          break;
     case 3:
          printf("Enter employee Id:");
	  scanf("%d",&Id);
	  memcpy(txmsg,     &srvtype,4);
	  memcpy(&txmsg[4], &cmd,    4);
	  memcpy(&txmsg[8], &Id,     4);
	  memcpy(&txmsg[12],&cliId,  4);

	  msgsnd(mqId,txmsg,16,0);
	  
          printf("waiting for response\n");
	  msgrcv(mqId,rxmsg,MSG_LEN,cliId,0);
	  
	  memcpy(&response,&rxmsg[4],4);
	  if(response==0)
	  {
	     indx=8;
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
	   msgsnd(mqId,txmsg,len,0);
	   
           printf("waiting for response\n");
	  msgrcv(mqId,rxmsg,MSG_LEN,cliId,0);
	  
	  memcpy(&response,&rxmsg[4],4);
	 	   
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
   
void prepareMsg(char *msg,empRec_t *rec1,int *len,int cmd)
{
  int cliId;
  int indx=8;
  cliId=getpid();
  int *msgHdr=(int *)msg;
  msgHdr[0]=SRV_MSG_TYPE;
  msgHdr[1]=cmd;
  memcpy(&msg[indx],&rec1->Id,4);
  indx+=4;
  strcpy(&msg[indx],rec1->name);
  indx=indx+strlen(rec1->name)+1;
  memcpy(&msg[indx],&rec1->salary,4);
  indx+=4;
  memcpy(&msg[indx],&rec1->phNum,4);
  indx+=4;
  msgHdr =(int *)(msg +indx);
  *msgHdr = cliId;
  //msg[indx]=cliId;
  //memcpy(&msg[indx],getpid(),4);
  indx+=4;
  *len=indx;
}  
  
  
