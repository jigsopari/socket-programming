#include<errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "fifo.h"

void strip_newline(char *name);
void format(char *buf,empRec_t *rec);

main()
{
  int cmd,response,Id;
  char wrbuf[512],rdbuf[512];
  empRec_t *rec;
  int srvFd,cliFd;       
  rec= malloc(sizeof(empRec_t));

  /********************* opening of server fifo ****************/
  
           srvFd=open("srvfifo",O_WRONLY); 
           if(srvFd<0)
             printf("Error in opening the server fifo\n");
           else
	     printf("Connected to server\n");

  /**************** Creation of client fifo ***************/	   
   
           
            if( (mkfifo("clififo1",0666) < 0) && (errno != EEXIST))
	      printf("Error in client fifo creation\n");
    	      
  
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
	 	   
	   sprintf(wrbuf,"%d|%d|%s|%d|%d|%s",cmd,rec->Id,rec->name,rec->salary,rec->phNum,"clififo1");
           write(srvFd,wrbuf,strlen(wrbuf)+1);
	   
           cliFd=open("clififo1",O_RDONLY);
           if(cliFd<0)
           {
              printf("Error in opening the client fifo");
           }

	   read(cliFd,rdbuf,512);
	   sscanf(rdbuf,"%d",&response);
	   if(response==0)
	     printf("\t\tRECORD ADDED SUCCESSFULLY");
	   else
	     printf("\t\tDATA BASE FULL ERROR");
	   close(cliFd);  
           break;
     case 2:
          printf("Enter employee Id:");
	  scanf("%d",&Id);
	  sprintf(wrbuf,"%d|%d|%s",cmd,Id,"clififo1");
	  write(srvFd,wrbuf,strlen(wrbuf)+1);
           
	   cliFd=open("clififo1",O_RDONLY);
           if(cliFd<0)
           {
              printf("Error in opening the client fifo1\n");
           }

	  read(cliFd,rdbuf,512);
	  sscanf(rdbuf,"%d",&response);
	   if(response==0)
	     printf("\t\tRECORD DELETED SUCCESSFULLY\n");
	   else
	     printf("\t\tRECORD NOT FOUND\n");
	   close(cliFd);  
           break;
     case 3:
          printf("Enter employee Id:");
	  scanf("%d",&Id);
	  sprintf(wrbuf,"%d|%d|%s",cmd,Id,"clififo1");
	  write(srvFd,wrbuf,strlen(wrbuf)+1);
           
	   cliFd=open("clififo1",O_RDONLY);
           if(cliFd<0)
           {
              printf("Error in opening the client fifo1\n");
           }

	  read(cliFd,rdbuf,512);
	  sscanf(rdbuf,"%d",&response);
	  if(response==0)
	  {
             format(rdbuf,rec);
	     printf("Id:%d | Name:%s | Salary:%d | phNum:%d\n",rec->Id,rec->name,rec->salary,rec->phNum);
	  }   
	  else
	     printf("\t\tRECORD NOT FOUND\n");
	  close(cliFd);  
          break;
     case 4:
	   fillRec(rec);
	 	   
	   sprintf(wrbuf,"%d|%d|%s|%d|%d|%s",cmd,rec->Id,rec->name,rec->salary,rec->phNum,"clififo1");
           write(srvFd,wrbuf,strlen(wrbuf)+1);
	   
           cliFd=open("clififo1",O_RDONLY);
           if(cliFd<0)
           {
              printf("Error in opening the client fifo\n");
           }

	   read(cliFd,rdbuf,512);
	   sscanf(rdbuf,"%d",&response);
	   if(response==0)
	     printf("\t\tRECORD MODIFIED SUCCESSFULLY\n");
	   else
	     printf("\t\tDATA BASE EMPTY ERROR OR NOT FOUND ERROR\n");
	   close(cliFd);  
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
