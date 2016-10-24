#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

//#define SRV_UDP_PORT 7000
#define MAX_MSG 100
//void toggleCase(char *buf);

void errExit(char *str)
{
  puts(str);
  exit(0);
}

int main()
{
  int sockFd,port;
  struct sockaddr_in srvAdr,cliAdr;
  int cliLen,n;
  char mesg[MAX_MSG];

  if( (sockFd = socket(AF_INET,SOCK_DGRAM,0)) < 0 )
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

  printf("server waiting for message\n");
  while(1)
  {
    printf("Enter u want to read from socket\n");
    scanf("%d",&cliLen);
    read(sockFd,mesg,cliLen);
    /*//cliLen = sizeof(cliAdr);
    //n = recvfrom(sockFd,mesg,MAX_MSG, 0,(struct sockaddr *) &cliAdr, &cliLen);
    //if(n < 0)
      //errExit("receive from error\n");
  
    //toggleCase(mesg);
    if(sendto(sockFd,mesg,n,0,(struct sockaddr *)&cliAdr,cliLen) != n) 
      errExit("sendto error\n");*/

    printf("Received following message from client %s\n%s\n",inet_ntoa(cliAdr.sin_addr),mesg);  
  }
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
