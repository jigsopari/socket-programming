#include <sys/types.h>
#include <unistd.h>
main(int argc,char *argv[])
{
  pid_t pid;
  int status;
  int status1;
  printf("i am in main");
  pid=fork();
  if(pid==0)
  {
    execv("/bin/cp",argv+1);
    exit(4);
  }  
  else
  {
    status1=wait(&status);
    printf("status:%d",status);




  }  
}  
