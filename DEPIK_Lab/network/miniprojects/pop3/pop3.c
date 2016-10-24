#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <termios.h>
#include <fcntl.h>

#define SRV_TCP_PORT 110
#define MAX_LEN      1024

void errExit(char *str)
{
  puts(str);
  exit(0);
}

int getpassWd(char *passwd)
{
  int ii=0;
  struct termios cuset,newset;
  char ch;

  /***Disable echo and canonical mode of processing***/
  tcgetattr(0,&cuset);
  newset=cuset;
  newset.c_lflag &= ~ICANON;
  newset.c_lflag &= ~ECHO;
  tcsetattr(0,TCSANOW,&newset);
 
  setbuf(stdin,NULL);
  setbuf(stdout,NULL);

  while((ch=getchar())!='\n')
  {
    passwd[ii++]=ch;
    putchar('*');
  } 
  passwd[ii++]=0;
  putchar('\n');
  tcsetattr(0,TCSANOW,&cuset);
}
void menu()
{
  printf("\n1.STAT\n");
  printf("2.LIST\n");
  printf("3.RETR\n");
  printf("4.DELE\n");
  printf("5.RESET\n");
  printf("6.QUIT\n");
  printf("7.EXIT\n");
}  

int main()
{
  int sockFd;
  int len;
  int rlen;
  int choice;
  int msgNo;
  char msg[20];
  char rxMsg[MAX_LEN];
  char txMsg[MAX_LEN];
  struct sockaddr_in srvAdr;

  if( (sockFd = socket(AF_INET,SOCK_STREAM,0)) < 0)
    errExit("Can't open stream socket\n");

  srvAdr.sin_family = AF_INET;
  printf("Enter Server Ip address:");
  scanf("%s",msg);
  srvAdr.sin_addr.s_addr = inet_addr(msg);
  srvAdr.sin_port = htons(SRV_TCP_PORT);

  len = connect(sockFd,(struct sockaddr *)&srvAdr,sizeof(srvAdr));
  if(len == -1)
    errExit("Can't connet to Server\n");

  rlen = recv(sockFd,rxMsg,MAX_LEN,0);
  rxMsg[rlen] = 0;
  puts(rxMsg);
  do
  {
    printf("Enter User Name:");
    __fpurge(stdin);
    fgets(msg,20,stdin);
    len = strlen(msg);
    if(msg[len-1] == '\n')
      msg[len-1] = 0;

    sprintf(txMsg,"%s %s%s","USER",msg,"\r\n");
    len = strlen(txMsg);
    if(send(sockFd,txMsg,len,0) != len)
      errExit("send Error");
  
    rlen = recv(sockFd,rxMsg,MAX_LEN,0);
    rxMsg[rlen] = 0;
    puts(rxMsg);

    
    if(strncmp(rxMsg,"+OK",3) == 0)
    {
      printf("Enter Pass Word:");
      //__fpurge(stdin);
      //fgets(msg,20,stdin);
      getpassWd(msg);
      /*len = strlen(msg);
      if(msg[len-1] == '\n')
        msg[len-1] = 0;*/
      sprintf(txMsg,"%s %s%s","PASS",msg,"\r\n");
      len = strlen(txMsg);
    
      if(send(sockFd,txMsg,len,0) != len)
        errExit("send Error\n");
      rlen = recv(sockFd,rxMsg,MAX_LEN,0);
      rxMsg[rlen] = 0;
      puts(rxMsg);
      if(strncmp(rxMsg,"+OK",3) != 0)
        printf("Incorrect Pass Word\n");
    }
    else
    {
      printf("The Entered Name is not a previalised user\n");
      continue;
    }
  }while(strncmp(rxMsg,"+OK",3));


  while(1)
  {
    menu();
    printf("\nEnter choice:");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:
           sprintf(txMsg,"%s%s","STAT","\r\n");
           len = strlen(txMsg);
    
           if(send(sockFd,txMsg,len,0) != len)
             errExit("send Error\n");
           
           rlen = recv(sockFd,rxMsg,MAX_LEN,0);
           rxMsg[rlen] = 0;
           puts(rxMsg);
           break;
    case 2:
           printf("Enter Message No:");
	   //scanf("%d",&msgNo);
           sprintf(txMsg,"%s%s","LIST","\r\n");
           len = strlen(txMsg);
    
           if(send(sockFd,txMsg,len,0) != len)
             errExit("send Error\n");
           
           rlen = recv(sockFd,rxMsg,MAX_LEN,0);
           rxMsg[rlen] = 0;
           puts(rxMsg);
           break;
    case 3:
           printf("Enter Message No:");
	   scanf("%d",&msgNo);
           sprintf(txMsg,"%s %d%s","RETR",msgNo,"\r\n");
           len = strlen(txMsg);
    
           if(send(sockFd,txMsg,len,0) != len)
             errExit("send Error\n");
           
           rlen = recv(sockFd,rxMsg,MAX_LEN,0);
           rxMsg[rlen] = 0;
           puts(rxMsg);
           break;
     case 4:      
           printf("Enter Message No:");
	   scanf("%d",&msgNo);
           sprintf(txMsg,"%s %d%s","DELE",msgNo,"\r\n");
           len = strlen(txMsg);
    
           if(send(sockFd,txMsg,len,0) != len)
             errExit("send Error\n");
           
           rlen = recv(sockFd,rxMsg,MAX_LEN,0);
           rxMsg[rlen] = 0;
           puts(rxMsg);
           break;
      case 5:
           sprintf(txMsg,"%s%s","RSET","\r\n");
           len = strlen(txMsg);
    
           if(send(sockFd,txMsg,len,0) != len)
             errExit("send Error\n");
           
           rlen = recv(sockFd,rxMsg,MAX_LEN,0);
           rxMsg[rlen] = 0;
           puts(rxMsg);
           break;
      case 6:
           sprintf(txMsg,"%s%s","QUIT","\r\n");
           len = strlen(txMsg);
    
           if(send(sockFd,txMsg,len,0) != len)
             errExit("send Error\n");
           
           rlen = recv(sockFd,rxMsg,MAX_LEN,0);
           rxMsg[rlen] = 0;
           puts(rxMsg);
           break;
    case 7:	   
           exit(0);
  }
 }
}
