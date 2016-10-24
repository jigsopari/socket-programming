#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
main()
{
  pid_t pid;
  int status;
  pid=fork();
  if(pid==0)
   { //execl("/bin/ls","ls",0);
   printf("hello");
   exit(4);
   }
  else 
  { waitpid(pid,&status,0);
   printf("status:%d\n",WEXITSTATUS(status));
    printf("I am main\n");
  }    
}
