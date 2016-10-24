#include "sharemem.h"

void prepareMsg(char *msg,empRec_t *rec1,int cmd);
void strip_newline(char *name);

main()
{
   int semId,shmId;
   int cmd,Id,response,indx;
   char *pshm;
   struct sembuf smop;
   empRec_t *rec;
   rec = malloc(sizeof(empRec_t));

   semId = semget(MY_KEY, 2, 0660);
   if(semId < 0)
   {
      perror("could not create semaphore\n");
      return(1);
   }
   else
      printf("Opened a semaphore with Id:%d\n",semId);
       
   shmId = shmget(MY_KEY, SHM_SIZE, 0);
   if(shmId < 0)
   {
      printf("Could not create shared memory segment\n");
      return(2);
   }
   pshm = shmat(shmId, NULL, 0);
   if(!pshm)
   {
      printf("Could not attach shared memory segment\n");
      return(3);
   }

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
	   prepareMsg(pshm,rec,cmd);

	   smop.sem_num = 0;
	   smop.sem_op  = 1;/*sending token to semaphore*/
	   smop.sem_flg = 0;
	   semop(semId,&smop,1);
	   //msgsnd(mqId,txmsg,len,0);
	   
           printf("waiting for response\n");
	   smop.sem_num = 1;
	   smop.sem_op  = -1;/*taking token from semaphore*/
	   smop.sem_flg = 0;
	   semop(semId,&smop,1);
	   memcpy(&response,pshm,4);
	   
	   if(response==0)
	     printf("\t\tRECORD ADDED SUCCESSFULLY\n");
	   else
	     printf("\t\tDATA BASE FULL ERROR\n");
           break;
     case 2:
          printf("Enter employee Id:");
	  scanf("%d",&Id);
	  memcpy(pshm, &cmd,    4);
	  memcpy(pshm, &Id,     4);

	   smop.sem_num = 0;
	   smop.sem_op  = 1;/*sending token to semaphore*/
	   smop.sem_flg = 0;
	   semop(semId,&smop,1);
	  
          printf("waiting for response\n");
	   smop.sem_num = 1;
	   smop.sem_op  = -1;/*taking token from semaphore*/
	   smop.sem_flg = 0;
	   semop(semId,&smop,1);
	   memcpy(&response,pshm,4);
	  
	  if(response==0)
	     printf("\t\tRECORD DELETED SUCCESSFULLY\n");
	  else   
	     printf("\t\tRECORD NOT FOUND\n");
          break;
     case 3:
          printf("Enter employee Id:");
	  scanf("%d",&Id);
	  memcpy(pshm,     &cmd,    4);
	  memcpy(&pshm[4], &Id,     4);

	   smop.sem_num = 0;
	   smop.sem_op  = 1;/*sending token to semaphore*/
	   smop.sem_flg = 0;
	   semop(semId,&smop,1);
	  
          printf("waiting for response\n");
	   smop.sem_num = 1;
	   smop.sem_op  = -1;/*taking token from semaphore*/
	   smop.sem_flg = 0;
	   semop(semId,&smop,1);
	  
	  memcpy(&response,pshm,4);
	  if(response==0)
	  {
	     indx=4;
	     memcpy(&rec->Id,&pshm[indx],4);
	     indx+=4;
	     strcpy(rec->name,&pshm[indx]);
	     indx = indx + strlen(rec->name)+1;
	     memcpy(&rec->salary,&pshm[indx],4);
	     indx+=4;
	     memcpy(&rec->phNum,&pshm[indx],4);
	     printf("Id:%d | Name:%s | Salary:%d | phNum:%d\n",rec->Id,rec->name,rec->salary,rec->phNum);
	  }   
	  else
	     printf("\t\tRECORD NOT FOUND\n");
          break;
     case 4:
	   fillRec(rec);
	   prepareMsg(pshm,rec,cmd);
	   
	   smop.sem_num = 0;
	   smop.sem_op  = 1;/*sending token to semaphore*/
	   smop.sem_flg = 0;
	   semop(semId,&smop,1);
           printf("waiting for response\n");
	   smop.sem_num = 1;
	   smop.sem_op  = -1;/*taking token from semaphore*/
	   smop.sem_flg = 0;
	   semop(semId,&smop,1);
	   memcpy(&response,pshm,4);
	   
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
   
void prepareMsg(char *msg,empRec_t *rec1,int cmd)
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
}  
  
