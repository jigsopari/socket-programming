#include <sys/types.h>
#include <sys/wait.h>
//#include <sys/types.h>
//#include <sys/types.h>
int main()
{
  pid_t pid;
  int status;
  int status1;
  printf("i am parent and my pid:%d\n",getpid());
  pid= fork();
  printf("pid=%d",pid);
  
 if(pid<0)
  printf("fork error\n");
  else if(pid>0)
  {
    //waitpid(pid,&status,0);
    status1=wait(&status);//wait return child ID
 printf("i am parent after child is executed and my pid:%d\n",getpid());
    printf("status:%d\n",status);
    printf("status1:%d\n",status1);
   exit(status);
   }  
else
    printf("i am child and my pid:%d\n",getpid());
    printf("i am child and my parent pid:%d\n",getppid());
}    
    
  
