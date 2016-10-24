#include <stdio.h>
main()
{
  printf("process id:%d\n",getpid());
  printf("parent process id:%d\n",getppid());
  printf("user id:%d\n",getuid());
  printf("group id:%d\n",getgid());
  printf("Effective user id:%d\n",geteuid());
  printf("Effective group id:%d\n",getegid());
}  
