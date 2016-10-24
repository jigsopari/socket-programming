#include <fcntl.h>
#include <stdio.h>

main()
{
  int fd,fd1,fd2,fd3;
  fd=open("filename1",O_WRONLY|O_CREAT,0644);
  printf("fd=%d ",fd);
  fd1=dup(fd);
  fd2=dup(fd);
  fd3=dup(fd);
  printf("fd1=%d ",fd1);
  printf("fd2=%d ",fd2);
  printf("fd3=%d ",fd3);
  write(fd,"durga",5);
  write(fd1,"\nhello",6);
  write(fd2,"\ndurgapathi",11);
  write(fd3,"\nramana",7);
  close(fd2);
  //write(fd2,"\nreddyramana",12);
  
} 
