#include <stdio.h>
#include <signal.h>

void sig_fun(int signo)
{
  if(signo==SIGINT) printf("RECEIVED SIGINT\n");
  else if(signo==SIGQUIT) printf("RECEIVED SIGQUIT\n");
  else if(signo==SIGUSR1) printf("RECEIVED SIGUSR1\n");
  else if(signo==SIGUSR2) printf("RECEIVED SIGUSR2\n");
  else printf("I received signal number:%d\n",signo);
}  
main()
{
  int ch;
  sigset_t newmask,oldmask;
  struct sigaction act;
  while(1)
  {
    printf("\n1.mask signal\n");
    printf("2.unmask signal\n");
    printf("3.pending signal display\n");
    printf("4.exit\n");
    printf("\nEnter option:");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:
           act.sa_handler=sig_fun;
	   sigaction(SIGINT,&act,NULL);
	   sigaction(SIGQUIT,&act,NULL);
	   sigaction(SIGUSR1,&act,NULL);
	   sigaction(SIGUSR2,&act,NULL);
	   sigemptyset(&newmask);
	   sigaddset(&newmask,SIGINT);
	   sigaddset(&newmask,SIGQUIT);
	   sigaddset(&newmask,SIGUSR1);
	   sigaddset(&newmask,SIGUSR2);
	   if(sigprocmask(SIG_BLOCK,&newmask,NULL)<0)
	     printf("SIG_BLOCK error\n");
	   break;
      case 2:
           if(sigprocmask(SIG_SETMASK,&oldmask,NULL)<0)
	     printf("SIG_SETMASK error\n");
	   break;
      case 3:
           if(sigprocmask(0,NULL,&newmask)<0)
	     printf("Reading error\n");
	   if(sigismember(&newmask,SIGINT)) printf("SIGINT\n"); 
	   if(sigismember(&newmask,SIGQUIT)) printf("SIGQUIT\n"); 
	   if(sigismember(&newmask,SIGUSR1)) printf("SIGUSR1\n"); 
	   if(sigismember(&newmask,SIGUSR2)) printf("SIGUSR2\n"); 
	   break;
      case 4:
           exit(0);
    }
  }
}   
    
