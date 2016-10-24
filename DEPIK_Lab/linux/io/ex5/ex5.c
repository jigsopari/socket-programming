#include <stdio.h>
#include <fcntl.h>
main()
{
  int fd;
  fd=open("filename",O_WRONLY|O_CREAT,0644);
  dup2(fd,1);
  printf("\ndurga");
  printf("\ndurgapathi");
  dup2(fd,4);
  write(4,"ramana",6);
}  
