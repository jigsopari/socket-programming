#include <stdio.h>
#include <signal.h>
#include <unistd.h>
//static void sig_alarm(int signo);

static void sig_alarm(int signo)
{
  printf("I caught alarm signal\n");
}  
unsigned int mysleep(unsigned int nsecs)
{
  if(signal(SIGALRM,sig_alarm)==SIG_ERR)
    return(nsecs);
  alarm(nsecs);
  pause();
  return(alarm(0));
}  
main()
{
  mysleep(1);
}  

