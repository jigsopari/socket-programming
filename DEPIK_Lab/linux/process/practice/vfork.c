#include <sys/types.h>//vfork() is combination of fork() and exec() 
#include <sys/stat.h>//vfork guarentees that child will execute first
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
int glob=6;
char buf[]="a write to  stdout\n";
main()
{
  int fd;
  int var;
  pid_t pid;
  var=88;
  //fd=open("temp.out",O_RDWR|O_CREAT|O_TRUNC);
  //dup2(fd,0);
  if(write(1,buf,sizeof(buf)-1) !=sizeof(buf)-1 )
    printf("write error\n");
  printf("before vfork\n");
  pid=vfork();
  if(pid<0)
  //if(pid=fork()<0)
    printf("vfork error\n");
  else if(pid==0)
  {
    glob++;
    var++;
    _exit(1);
  }
  //else
  //sleep(2);
  printf("pid=%d, glob=%d, var=%d \n",getpid(),glob,var);
  exit(1);
}  
