#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>

main()
{
  int fd;
  char a[0];

  fd=open("/dev/ttyS0",O_RDWR);
  write(fd,"Hello world*********\n",23);

  lseek(fd,0,SEEK_SET);
  while(1)
  {
    read(fd,a[0],1);
    write(1,a[0],1);
    if(a[0]=='0')
    break;	    
  //printf("%c",a[0]);
  }

}
