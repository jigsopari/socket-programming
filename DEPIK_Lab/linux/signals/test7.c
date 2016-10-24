#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

main()
{
  int signo,ch;
  pid_t pid;
  while(1)
  {
    printf("1. send a signal");
    printf("2. Exit");
    printf("Enter option:");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:
           printf("Enter process Id:");
           scanf("%d",&pid);
           printf("Enter signal number:");
           scanf("%d",&signo);
           kill(pid,signo);
	   break;
     case 2:
           exit(1);
    }
  }    
}  
