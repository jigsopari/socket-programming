#include<errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "fifo.h"

void format(char *buf,empRec_t *rec,char *cliName);

main()
{
  int cmd,Id,n;
  int response;
  int srvFd,fileFd,cliFd;
  int cnt;
  char rdbuf[512],wrbuf[512];
  char cliName[20];
  empRec_t *sRec;
  sRec=malloc(sizeof(empRec_t));
  
  /******************server fifo creation****************/
  
  if( (mkfifo("srvfifo",0666) < 0) && (errno != EEXIST))
    printf("Error in server fifo creation\n");

        srvFd=open("srvfifo",O_RDONLY);
	if(srvFd<0)
	{
	  printf("Error in opening server fifo\n");
	}
	
  /**********************file creation*************************/
  
       fileFd=open("file",O_RDWR);
       if(fileFd<0)
       {
         printf("creating file ....\n");
	 
         fileFd=open("file",O_CREAT|O_RDWR,0666); 
         if(fileFd<0)
	 {
	    printf("could not create file\n");
	    exit(1);
	 }
       }	 


  do
  {
    cnt = read(srvFd,rdbuf,512);
    if(cnt)
    {
       sscanf(rdbuf,"%d",&cmd);
       printf("Received message\n");
       switch(cmd)
       {
         case 1:
	      format(rdbuf,sRec,cliName);
	      response=addNewStudentRec(fileFd,sRec);
	      printf("cliName : %s\n",cliName);
	      cliFd=open(cliName,O_WRONLY);
	      if(cliFd < 0)
	        perror("Error in opening the client fifo");
              else
	      {
		sprintf(wrbuf,"%d",response);
	        write(cliFd,wrbuf,512);
	        printf("Response was sent to client\n");
	      }
	      break;
	  case 2:
               sscanf(rdbuf,"%d|%d|%s",&cmd,&Id,cliName);
               response=deleteStudentRec(fileFd,Id);
	       printf("cliName : %s\n",cliName);
	       cliFd=open(cliName,O_WRONLY);
	       if(cliFd<0)
	         printf("Error in opening the client fifo\n");
               else
	       {
		 sprintf(wrbuf,"%d",response);
	         write(cliFd,wrbuf,512);
	         printf("Response was sent to client\n");
	       }	 
	      break;
	  case 3:
               sscanf(rdbuf,"%d|%d|%s",&cmd,&Id,cliName);
               response=getEmpDetails(fileFd,Id,sRec);
	       
	       printf("cliName : %s\n",cliName);
	       cliFd=open(cliName,O_WRONLY);
	       if(cliFd<0)
	         printf("Error in opening the client fifo\n");
               else
	       {
	         if(response==0)
	         {
	           sprintf(wrbuf,"%d|%d|%s|%d|%d",response,sRec->Id,sRec->name,sRec->salary,sRec->phNum);
		   write(cliFd,wrbuf,REC_SIZE);
	           printf("Sending response to client\n");
	         }
	         else
	         {
	  	   sprintf(wrbuf,"%d",response);
	           write(cliFd,wrbuf,512);
	           printf("Sending response to client\n");
	         }
               }		
	      break;
	  case 4:
	      format(rdbuf,sRec,cliName);
               response=modifyEmpDetails(fileFd,sRec);
	       
	       printf("cliName : %s\n",cliName);
	       cliFd=open(cliName,O_WRONLY);
	       if(cliFd<0)
	         printf("Error in opening the client fifo\n");
               else
	       {
		sprintf(wrbuf,"%d",response);
	        write(cliFd,wrbuf,512);
	        printf("Response was sent to client\n");
	       }
	      break;
        }
     }
   }
   while(cnt);
  close(srvFd);
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

void format(char *buf,empRec_t *rec,char *cliName)
{
   int cmd;
   char *temp;
   
   temp=(char*)malloc(20);

   temp=strtok(buf,"|");
   cmd=atoi(temp);

   temp=strtok(NULL,"|");
   rec->Id=atoi(temp);
   
   temp=strtok(NULL,"|");
   strcpy(rec->name,temp);
   
   temp=strtok(NULL,"|");
   rec->salary=atoi(temp);
   
   temp=strtok(NULL,"|");
   rec->phNum=atoi(temp);
   
   temp=strtok(NULL,"|");
   
   strcpy(cliName,temp);
}   
