#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
//#define MAXLINE 80
int main()
{
  //char buf[MAXLINE];
  pid_t pid;
  int status;

 // printf("%% ",);
  //while(fgets()) 
  pid=fork();
  if(pid==0)
  {
    execlp("ls","ls",0);
    //execlp("/home/durga/linux/process/practice/ramana","ramana",0);
  }
  else
  {
    wait(&status);
    printf("i am parent");
    exit(status);
  }  
}  
