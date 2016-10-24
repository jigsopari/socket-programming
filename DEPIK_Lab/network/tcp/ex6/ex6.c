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
   int    sockFd,newSockFd;
   struct sockaddr_in srvAdr,cliAdr;
   int    cliLen,n,pid,ret;
   char   mesg[MAX_MSG];

   if((sockFd=socket(AF_INET,SOCK_STREAM,0)) < 0)
     errExit("can't open stream socket\n");
   printf("sock fd:%d",sockFd);
   memset((struct sockaddr *)&srvAdr,0,sizeof(srvAdr));
   srvAdr.sin_family = AF_INET;
   srvAdr.sin_port = htons(SRV_TCP_PORT);
   srvAdr.sin_addr.s_addr = htonl(INADDR_ANY);
 
   if( bind(sockFd,(struct sockaddr *)&srvAdr,sizeof(srvAdr)) < 0)
     errExit("can't bind local address\n");

   ret = listen(sockFd,2);
   printf("%d\n",ret);
   

   while(1)
   {
     printf("Server waiting for new connection\n");
     newSockFd = accept(sockFd,(struct sockaddr *)&cliAdr,&cliLen);
     if(newSockFd < 0)
       errExit("accept error\n");
     printf("Connected to client: %s\n",inet_ntoa(cliAdr.sin_addr));

     pid = fork();
     if(pid == 0)
     {
       while(1)
       {
          n = recv(newSockFd, mesg, MAX_MSG, 0);
	  if(n < 0)
	    errExit("recv error\n");
	  if(n == 0)
	  {
	     close(newSockFd);
	     break;
	  } 
	  mesg[n] = 0;

          toggleCase(mesg);
	  
	  if(send(newSockFd,mesg,n,0) != n)
             errExit("send error\n");

	  printf("Received and sent following message:\n%s\n",mesg);
       }
       exit(0);
     }
     else  /*** parent process ***/
       close(newSockFd);
   }  
}       
 
     
   
