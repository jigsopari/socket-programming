#include <stdio.h>
#include <signal.h>
char array[4];

void mySigHandler(int signo)
{
  if(signo==SIGUSR1) 
  {
    printf("I caught the SIGUSR1 signal\n");// \n should be mandatory
    array[0]=1;  // otherwise it will not printed on terminal
  }   
  else if(signo==SIGUSR2)
  {
    printf("I caught the SIGUSR2 signal\n");
    array[1]=1;
  }  
  else if(signo==SIGQUIT)
  {
    printf("I caught the SIGQUIT signal\n");
    array[2]=1;
  }  
  else if(signo==SIGINT)  
  {
    printf("I caught the SIGINT signal\n");
    array[3]=1;
  }  
  else
    printf("I caught signal: %d\n",signo);
  
//  return;  
}

main()
{
  signal(SIGUSR1,mySigHandler);
  signal(SIGUSR2,mySigHandler);
  signal(SIGQUIT,mySigHandler);
  signal(SIGINT,mySigHandler);
  while(1)
  {
    pause();
    if(array[0]==1 & array[1]==1 & array[2]==1 & array[3]==1)
      exit(0);
  }    
}  
