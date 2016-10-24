#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
 
main()
{
  int fd[2];
  char wrbuf[]="hello world";
  char rdbuf[sizeof(wrbuf)];
  pid_t pid;
  if(pipe(fd)<0)
    printf("pipe error");
  if( ( pid=fork() ) <0 )
    printf("fork error");
  if(pid>0)
  {
    close(fd[0]);
    write(fd[1],wrbuf,sizeof(wrbuf));
  }
  else 
  {
    close(fd[1]);
    read(fd[0],rdbuf,sizeof(wrbuf));
    write(1,rdbuf,sizeof(wrbuf));
  }
}  
