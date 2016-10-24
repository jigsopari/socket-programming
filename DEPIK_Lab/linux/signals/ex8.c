#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sig_fun(int signo)
{
  printf("I caught the alarm signal\n");
  exit(0);
}

main()
{
  unsigned int nsec;
  struct sigaction val;
  val.sa_handler=sig_fun;
  sigaction(SIGALRM,&val,0);
  printf("Enter seconds:");
  scanf("%d",&nsec);
  alarm(nsec);
  pause();
}  
