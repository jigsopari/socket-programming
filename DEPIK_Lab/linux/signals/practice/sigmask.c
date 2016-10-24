#include <stdio.h>
#include <signal.h>

void sig_fun(int signo)
{
  printf("i caught the sigint signal");
}



main()
{
  sigaction act;
  sigset_t newmask,oldmask;
  act=sig_fun;
  sigaction(SIGINT,&act,NULL);
  sigemptyset(&newmask);
  sigaddset(&newmask,SIGINT);
  if(sigprocmask(SIG_BLOCK,&newmask,NULL)<0)
    printf("SIG_BLOCK error");
    
  for(; ;);
  pause();
}    

