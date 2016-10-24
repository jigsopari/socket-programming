#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SRV_TCP_PORT 8000
#define MAX_MSG      100

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
   int    srvsockFd,newsockFd,fd;
   struct sockaddr_in srvAdr,cliAdr;
   int    n;
   char   mesg[MAX_MSG];
   int    stat;
   fd_set readfds,testfds;

   if((srvsockFd=socket(AF_INET,SOCK_STREAM,0)) < 0)
     errExit("can't open stream socket\n");
   printf("sock fd:%d",srvsockFd);
   memset((struct sockaddr *)&srvAdr,0,sizeof(srvAdr));
   srvAdr.sin_family = AF_INET;
   srvAdr.sin_port = htons(SRV_TCP_PORT);
   srvAdr.sin_addr.s_addr = htonl(INADDR_ANY);
 
   if( bind(srvsockFd,(struct sockaddr *)&srvAdr,sizeof(srvAdr)) < 0)
     errExit("can't bind local address\n");

   listen(srvsockFd,5);

   FD_ZERO(&readfds);
   FD_SET(srvsockFd,&readfds);

   printf("Server waiting for new connection\n");
   while(1)
   {
     testfds = readfds;
     stat = select(FD_SETSIZE,&testfds,(fd_set *)0,(fd_set *)0,(struct timeval *)0);
     if(stat < 1)
       errExit("select error\n");

     for(fd=0; fd<FD_SETSIZE; fd++) 
     {
       if(FD_ISSET(fd,&testfds))
       {
         if(fd == srvsockFd)
         {
           newsockFd = accept(fd,(struct sockaddr *)0,NULL);
	   FD_SET(newsockFd,&readfds);
	   printf("Adding client fd: %d to readFd set\n",newsockFd);
         }
         else 
         {
           n = recv(fd, mesg, MAX_MSG, 0);
	   if(n < 0)
	     errExit("recv error\n");
	   else if(n == 0)
	   {
	     close(fd);
	     FD_CLR(fd, &readfds);
	     printf("Removing client fd: %d from readFd set\n",fd);
	   }
	   else
	   {
             toggleCase(mesg);
	     if(send(fd,mesg,n,0) != n)
	       errExit("send error\n");
	   }
	 } 
       }	 
     }
   }
 }  
     
 
     
   
