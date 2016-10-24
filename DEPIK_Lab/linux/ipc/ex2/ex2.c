#include <stdio.h>
//#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

int fd1[2];
int fd2[2];

main()
{
  int ret,ii,n;
  pid_t pid;
  char buf1[80];
  char buf2[80];
  
  if( (pipe(fd1)) < 0)
    printf("pipe fd1 error\n");
  if((pipe(fd2)) < 0)
    printf("pipe fd2 error\n");
  
  if( (pid=fork()) <0)
    printf("fork error\n");
  if(pid==0)
  {
    close(fd1[1]);
    close(fd2[0]);
    dup2(fd1[0],0);
    dup2(fd2[1],1);
    execl("./togglecase","togglecase",0);
    //wait();
  }
  else
  { 
    close(fd1[0]);
    close(fd2[1]);
    printf("Enter sting\n");
    __fpurge(stdin);
    fgets(buf1,80,stdin);
    /*while(1)
    {
      read(0,buf1,1);
      if(&buf[ii]=='\n')
        break;
    }*/	
    ret=write(fd1[1],buf1,80);
    n=read(fd2[0],buf2,ret);
    buf2[n] =0;
    puts(buf2);
  }  
}    
