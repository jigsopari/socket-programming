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
  printf("ret=%d",ret);
  while(1)
  {
    sleep(5);
    printf("I slept for 5 seconds\n");
  }
}  
