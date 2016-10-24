#include "sharemem.h"

void extract(char *buf,empRec_t *rec);

int main()
{
   int shmId,semId,fileFd;
   int cmd,response,Id,indx;
   char *pshm;
   struct sembuf smop;
   empRec_t *sRec;
   sRec=malloc(sizeof(empRec_t));

    /****Create a semaphore set, containing two semaphores****/
    
   semId=semget(MY_KEY, 2, 0660 | IPC_CREAT);
   if(semId < 0)
   {
      perror("could not create semaphore\n");
      return(1);
   }
   else
   {
      printf("Opened a semaphore with Id: %d\n",semId);
   }
   
  /**** Set initial token count of both semaphores to zeros ****/
  
   semctl(semId,0,SETVAL,0);
   semctl(semId,1,SETVAL,0);
   
  /**** Create Shared Memory segment **************************/   
  
   shmId = shmget(MY_KEY, SHM_SIZE, 0666 | IPC_CREAT);
   if(shmId<0)
   {
      printf("Could not create shared memory segment\n");
      return(2);
   }
   /**** Attach shared memory segment to process address space ****/
   
   pshm = shmat(shmId, NULL, 0);
   if(!pshm)
   {
      printf("Could not attach shared memory segment\n");
      return(3);
   }
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


   while(1)
   {
      printf("Waiting for a token from semaphore 0\n");
      smop.sem_num = 0;
      smop.sem_op = -1;
      smop.sem_flg = 0;
      semop(semId, &smop, 1);
      
      /**** process the message available in shared memory ****/
      
      printf("Got the semaphore\n");
      
       memcpy(&cmd,pshm,4);
       printf("Received message\n");
       switch(cmd)
       {
         case 1:
	      extract(pshm,sRec);
	      response=addNewStudentRec(fileFd,sRec);
	      
	      memcpy(pshm,&response,4);
	      smop.sem_num = 1;
	      smop.sem_op = 1;/*a positive number for sending*/
	      smop.sem_flg = 0;
	      semop(semId,&smop,1);
	        printf("token was sent to semaphore 1\n");
	      break;
	  case 2:
	       memcpy(&Id,&pshm[4],4);
               response=deleteStudentRec(fileFd,Id);
	       
	       memcpy(pshm,&response,4);
	       smop.sem_num = 1;
	       smop.sem_op = 1;
	       smop.sem_flg = 0;
	       semop(semId,&smop,1);
	        printf("token was sent to semaphore 1\n");
	       	 
	      break;
	  case 3:
	       memcpy(&Id,&pshm[4],4);
               response=getEmpDetails(fileFd,Id,sRec);
	       
	         if(response==0)
	         {
		    indx=4;
	            memcpy(pshm,&response,4);
                    memcpy(&pshm[indx],&sRec->Id,4); 
                    indx+=4;
                    strcpy(&pshm[indx],sRec->name); 
                    indx=indx+strlen(sRec->name)+1;
                    memcpy(&pshm[indx],&sRec->salary,4); 
                    indx+=4;
                    memcpy(&pshm[indx],&sRec->phNum,4); 
		   
	            smop.sem_num = 1;
	            smop.sem_op = 1;
	            smop.sem_flg = 0;
	            semop(semId,&smop,1);
	            printf("token was sent to semaphore 1\n");
	         }
	         else
	         {
	            memcpy(pshm,&response,4);
	            smop.sem_num = 1;
	            smop.sem_op = 1;
	            smop.sem_flg = 0;
	            semop(semId,&smop,1);
	            printf("Response was sent to client\n");
	         }
               		
	      break;
	  case 4:
	      extract(pshm,sRec);
               response=modifyEmpDetails(fileFd,sRec);
	       
	      memcpy(pshm,&response,4);
	      smop.sem_num = 1;
	      smop.sem_op = 1;/*a positive number for sending*/
	      smop.sem_flg = 0;
	      semop(semId,&smop,1);
	        printf("token was sent to semaphore 1\n");
	       
	      break;
        }
     }
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
   
      
   
