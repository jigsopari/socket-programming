#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
main()
{
  int fd;
  fd=open("filename",O_WRONLY|O_CREAT|O_APPEND,0644);
  write(fd,"durgapathi",11);
  lseek(fd,0,0);
  write(fd,"Hi",3);
} 
  
