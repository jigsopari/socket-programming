#include <sys/ipc.h>
#include <sys/msg.h>
#include "msgq.h"

void extract(char *buf,empRec_t *rec,int *proId);

 main()
{
  int cmd,Id,indx;
  int response;
  int mqId,fileFd;
  int msgLen;
  char rxmsg[MSG_LEN],txmsg[MSG_LEN];
  int proId;
  empRec_t *sRec;
  sRec=malloc(sizeof(empRec_t));
  
  /******************server fifo creation****************/
   mqId=msgget(MY_KEY,0660|IPC_CREAT); 
   if(mqId<0)
   {
     printf("Could not create message queue\n");
     return(1);
   }
   else
     printf("Opened message queue.Id : %d\n",mqId);
	
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


  do
  {
    printf("Server : Waiting for message\n");
    msgLen = msgrcv(mqId, rxmsg, MSG_LEN, SRV_MSG_TYPE, 0);
    if(msgLen)
    {
       memcpy(&cmd,&rxmsg[4],4);
       printf("Received message\n");
       switch(cmd)
       {
         case 1:
	      extract(rxmsg,sRec,&proId);
	      response=addNewStudentRec(fileFd,sRec);
	      printf("process Id: %d\n",proId);
	      
	      memcpy(&txmsg[0],&proId,4);
	      memcpy(&txmsg[4],&response,4);
		msgsnd(mqId,txmsg,8,0);
	        printf("Response was sent to client\n");
	      break;
	  case 2:
	       memcpy(&Id,&rxmsg[8],4);
	       memcpy(&proId,&rxmsg[12],4);
               response=deleteStudentRec(fileFd,Id);
	       printf("client process Id : %d\n",proId);
	       
	      memcpy(&txmsg[0],&proId,4);
	      memcpy(&txmsg[4],&response,4);
	      msgsnd(mqId,txmsg,8,0);
	      printf("Response was sent to client\n");
	       	 
	      break;
	  case 3:
	       memcpy(&Id,&rxmsg[8],4);
	       memcpy(&proId,&rxmsg[12],4);
               response=getEmpDetails(fileFd,Id,sRec);
	       
	       printf("client process Id: %d\n",proId);
	         if(response==0)
	         {
                    int indx=0;
	            memcpy(&txmsg[indx],&proId,4);
                    indx+=4;
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
		   
	            msgsnd(mqId,txmsg,indx,0);
	           printf("response was sent to client\n");
	         }
	         else
	         {
	            memcpy(&txmsg[0],&proId,4);
	            memcpy(&txmsg[4],&response,4);
		    indx+=4;
	            msgsnd(mqId,txmsg,8,0);
	            printf("Response was sent to client\n");
	         }
               		
	      break;
	  case 4:
	      extract(rxmsg,sRec,&proId);
               response=modifyEmpDetails(fileFd,sRec);
	       printf("client process Id : %d\n",proId);
	       
	      memcpy(&txmsg[0],&proId,4);
	      memcpy(&txmsg[4],&response,4);
	      msgsnd(mqId,txmsg,8,0);
	      printf("Response was sent to client\n");
	       
	      break;
        }
     }
   }
   while(msgLen);
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

void extract(char *buf,empRec_t *rec,int *proId)
{
   int indx=8;
   memcpy(&rec->Id,&buf[indx],4); 
   indx+=4;
   strcpy(rec->name,&buf[indx]); 
   indx=indx+strlen(rec->name)+1;
   memcpy(&rec->salary,&buf[indx],4); 
   indx+=4;
   memcpy(&rec->phNum,&buf[indx],4); 
   indx+=4;
   memcpy(proId,&buf[indx],4); 
   indx+=4;
}  

