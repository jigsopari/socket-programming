#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
int glob=6;
char buf[]="a write to  stdout\n";
main()
{
  int fd;
  int var;
  pid_t pid;
  var=88;
  
  if(write(1,buf,sizeof(buf)-1) !=sizeof(buf)-1 )
    printf("write error\n");
    
  printf("before fork\n");
  
  pid=fork();
  
  if(pid<0)
    printf("fork error");
    
  else if(pid==0)
  {
    glob++;
    var++;
  }
  
  else
  sleep(2);
  
  printf("pid=%d, glob=%d, var=%d \n",getpid(),glob,var);
  exit(0);
}  
