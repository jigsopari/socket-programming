#include <stdio.h>
#include <signal.h>
#include <fcntl.h>

void mySignalHandler(int signo)
{
  printf("I caught user1 signal\n");
}  
main()
{
  struct sigaction act;
  act.sa_handler=mySignalHandler;
  sigaction(SIGUSR1,&act,0);
  while(1)
  pause();
}

