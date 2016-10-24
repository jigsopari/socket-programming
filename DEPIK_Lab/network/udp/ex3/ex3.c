
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

//#define SRV_IP_ADRS "127.0.0.1"
//#define SRV_IP_ADRS "192.168.0.31"
//#define SRV_UDP_PORT 7000
#define MAX_MSG 100

void errExit(char *str)
{
  puts(str);
  exit(0);
}

int main()
{
  int sockFd,srvport,retval;
  char ipaddr[12];
  struct sockaddr_in srvAdr;
  int n;
  char txmsg[MAX_MSG];
  char rxmsg[MAX_MSG];
  fd_set rfds;
  struct timeval tv;
  if( (sockFd = socket(AF_INET,SOCK_DGRAM,0)) < 0 )
    errExit("Can't open datagram socket\n");

  printf("Enter server port number:");
  scanf("%d",&srvport);
  printf("Enter server ip address:");
  scanf("%s",ipaddr);
  
  memset(&srvAdr,0,sizeof(srvAdr));
  srvAdr.sin_family = AF_INET;
  srvAdr.sin_addr.s_addr = inet_addr(ipaddr);
  srvAdr.sin_port = htons(srvport);
  FD_ZERO(&rfds);
  FD_SET(sockFd,&rfds);
  while(1)
  {
  
    printf("Enter message to send:\n");
    __fpurge(stdin);
    fgets(txmsg,MAX_MSG,stdin);

    n = strlen(txmsg)+1;
    txmsg[n]=0;
    
    if(sendto(sockFd,txmsg,n,0,(struct sockaddr *)&srvAdr,sizeof(srvAdr)) != n)
      errExit("sendto error\n");
      
    tv.tv_sec = 5;
    tv.tv_usec = 0;
    
    retval = select(1024,&rfds,NULL,NULL,&tv);
    if(retval < 0)
    {
      printf("No fd to read\n");
      continue;
    }  
    else  
    {
      n = recv(sockFd, rxmsg, MAX_MSG, 0);
      if(n<0)
        errExit("recv error\n");
    }
  
    printf("Received following message:\n%s\n",rxmsg);
  }  
}       
  
