#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define SRV_TCP_PORT 8000
#define MAX_MSG      100

void * servClient(void *arg); 

void errExit(char *str)
{
  puts(str);
  exit(0);
}

void toggleCase(char *buf)
{
    int ii=0;
    while(1)
    {
      
      if(buf[ii]=='\n')
        break;
      if((buf[ii] >= 'A') && (buf[ii] <='Z'))
        buf[ii] += 0x20;
      else if((buf[ii] >= 'a') && (buf[ii] <='z'))
        buf[ii] -= 0x20;
      ii++;
    }
}

main()
{
   int    sockFd,newSockFd;
   struct sockaddr_in srvAdr,cliAdr;
   int    cliLen,n;
   char   mesg[MAX_MSG];
   pthread_t srvThread;

   if((sockFd=socket(AF_INET,SOCK_STREAM,0)) < 0)
     errExit("can't open stream socket\n");
   printf("sock fd:%d",sockFd);
   memset((struct sockaddr *)&srvAdr,0,sizeof(srvAdr));
   srvAdr.sin_family = AF_INET;
   srvAdr.sin_port = htons(SRV_TCP_PORT);
   srvAdr.sin_addr.s_addr = htonl(INADDR_ANY);
 
   if( bind(sockFd,(struct sockaddr *)&srvAdr,sizeof(srvAdr)) < 0)
     errExit("can't bind local address\n");

   listen(sockFd,2);

   while(1)
   {
     printf("Server waiting for new connection\n");
     newSockFd = accept(sockFd,(struct sockaddr *)&cliAdr,&cliLen);
     if(newSockFd < 0)
       errExit("accept error\n");
     printf("Connected to client: %s\n",inet_ntoa(cliAdr.sin_addr));
     pthread_create(&srvThread,NULL,servClient,(void *)newSockFd);
   }
}

void * servClient(void *arg) 
{
  int n;
  int sockfd = (int) arg;
  char mesg[MAX_MSG];

  pthread_detach(pthread_self());
  while(1)
  {
    n = recv(sockfd, mesg, MAX_MSG, 0);
    if(n < 0)
      return;
    else if(n == 0)
      break;
    else 
    {
      mesg[n] = 0;
      toggleCase(mesg);
      if(send(sockfd,mesg,n,0) != n)
         errExit("send error\n");
      printf("Received and sent following message:\n%s\n",mesg);
    }
  }  
  close(sockfd);
}       
 
     
   
