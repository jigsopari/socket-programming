#include <stdio.h>
#include <signal.h>

void mysigHandler(int signo)
{
  printf("I caught the signal %d\n",signo);
}

int main()
{
  int ret; 
  signal(SIGINT,mysigHandler);
  for(; ;)
  {
    ret=pause();
    printf("ret=%d",ret);
   // sleep(5);
   // printf("I slept for 5 seconds\n");
  }
}  
