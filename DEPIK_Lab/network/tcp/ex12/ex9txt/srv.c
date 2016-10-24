
#include "tcp.h"

void extract(char *buf,empRec_t *rec);
void format(char *buf,empRec_t *rec);

void errExit(char *str)
{
  puts(str);
  exit(0);
}
int daemonInit(void)
{
  pid_t pid;
  
  if( (pid = fork()) < 0)
    return(-1);
  else if(pid != 0) 
    exit(0);  /* parent exits */
    /** child continues **/
  setsid();
  chdir("/");
  close(0);
  close(1);
  close(2);
  umask(0);
  return(0);
}
 main()
{
  int Id,indx;
  int response,port;
  int sockFd,newSockFd;
  int cliLen,len;
  pthread_t srvThread;
  
  /****************** socket creation ****************/
  if( (sockFd = socket(AF_INET,SOCK_STREAM,0)) < 0 )
    errExit("Can't open datagram socket\n");

  printf("Enter the server port number:");
  scanf("%d",&port);

  memset((struct sockaddr *)&srvAdr,0,sizeof(srvAdr));
  srvAdr.sin_family = PF_INET;
  srvAdr.sin_addr.s_addr = htonl(INADDR_ANY);
  srvAdr.sin_port = htons(port);
  printf("port:%d",srvAdr.sin_port);
  
  if(bind(sockFd,(struct sockaddr *)&srvAdr,sizeof(srvAdr)) < 0)
    errExit("Can't bind local address\n");

  listen(sockFd,5);
  
	
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


  daemonInit();

  while(1)
  {
    printf("Server : Waiting for message\n");
    newSockFd = accept(sockFd,(struct sockaddr *)&cliAdr,&cliLen);
    if(newSockFd < 0)
      errExit("accept error\n");
    printf("connected to client: %s\n",inet_ntoa(cliAdr.sin_addr));
    pthread_create(&srvThread,NULL,srvClient,(void *)newSockFd);
  }
}  

void * srvClient(void *arg)
{
  int len,cmd,response,Id;
  int sockFd = (int) arg;
  char rxmsg[MSG_LEN],txmsg[MSG_LEN];
  empRec_t *sRec;
  sRec=malloc(sizeof(empRec_t));

  pthread_detach(pthread_self());
  while(1) 
  {
    len = recv(sockFd, rxmsg, MSG_LEN,0);

    if(len)
    {
       sscanf(rxmsg,"%d",&cmd);
       printf("Received message\n");
       switch(cmd)
       {
         case 1:
	      format(rxmsg,sRec);
	      bzero(&response,4);
	      response=addNewStudentRec(fileFd,sRec);
	     __fpurge(txmsg); 
	      sprintf(txmsg,"%d",response);
	      send(sockFd, txmsg, 2, 0);
	      printf("Response was sent to client\n");
	      break;
	  case 2:
               sscanf(rxmsg,"%d|%d|",&cmd,&Id);
               response=deleteStudentRec(fileFd,Id);
	       bzero(&txmsg,MSG_LEN);
	       sprintf(txmsg,"%d",response);
	       send(sockFd, txmsg, 2, 0);
	       printf("Response was sent to client\n");
	       break;
	 case 3:
               sscanf(rxmsg,"%d|%d|",&cmd,&Id);
	      bzero(&response,4);
               response=getEmpDetails(fileFd,Id,sRec);
	       
	     __fpurge(txmsg); 
	         if(response==0)
	         {
	           sprintf(txmsg,"%d|%d|%s|%d|%d",response,sRec->Id,sRec->name,sRec->salary,sRec->phNum);
		   len = strlen(txmsg);
	           send(sockFd, txmsg, len, 0);
	           printf("Response was sent to client\n");
	         }
	         else
	         {
	  	   sprintf(txmsg,"%d",response);
	           send(sockFd, txmsg, 2, 0);
	           printf("Sending response to client\n");
	         }
               		
	      break;
	  case 4:
	      format(rxmsg,sRec);
	      bzero(&response,4);
               response=modifyEmpDetails(fileFd,sRec);
	       
	     __fpurge(txmsg); 
		sprintf(txmsg,"%d",response);
		send(sockFd, txmsg, 2, 0);
	        printf("Response was sent to client\n");
	       
	      break;
        }
     }
   }
   close(sockFd);
   //while(cnt);
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

void format(char *buf,empRec_t *rec)
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
   
}   
