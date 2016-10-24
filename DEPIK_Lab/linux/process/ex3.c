#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
//#include <sys/types.h>
//#include <sys/types.h>
int main()
{
  pid_t pid;
  int status;
  int status1;
  //status=malloc(sizeof(int));
  printf("i am parent and my pid:%d\n",getpid());
  pid= fork();
  if(pid < 0)
  printf("fork error\n");
  else if(pid > 0)
  {
     status1=waitpid(pid,&status,0);//waitpid returns child ID 
     //wait(&status);
 printf("i am parent after child is executed and my pid:%d\n",getpid());
   printf("status:%d\n",WEXITSTATUS(status));
   printf("status1:%d\n",status1);
   exit(status);
   }  
   else
   {
      printf("**i am child and my pid:%d\n",getpid());
      execl("/bin/ls","ls",0);
      printf("i am child and my parent pid:%d\n",getppid());
      exit(000); 
   }    
    
}  
