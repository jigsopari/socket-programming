#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>


main()
{
  int ch;
  int fd1,fd2,fd3,fd4,n;
  char buf[80];
  char buf1[80];
  
    mkfifo("FIFO",0777);
  while(1)
  {
    printf("\n1.open in blocking read\n");
    printf("2.open in blocking write\n");
    printf("3.open in unblocking read\n");
    printf("4.open in unblocking write\n");
    printf("5.exit\n\n");
    printf("Enter option:");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:
           fd1=open("FIFO",O_RDONLY);
	   printf("fd1: %d\n",fd1);
	   while(1)
	   {
	     read(fd1,buf,80);
	     if(strncmp(buf,"exit",4)==0)
	       exit(0);
	     else  
	       printf("%s",buf);
	   }
	     break;
     case 2:
          fd2=open("FIFO",O_WRONLY);
	   printf("fd2: %d\n",fd2);
	  while(1)
	  {
	    printf("Enter string\n");
	    
	  __fpurge(stdin);
	    fgets(buf1,80,stdin);
	    write(fd2,buf1,strlen(buf1));
	    if(strncmp(buf1,"exit",4)==0)
	      exit(0);
	  }    
            break;
     case 3:
          fd3=open("FIFO",O_RDONLY|O_NONBLOCK);
	  

	  {
	    printf("i return zero due to empty fifo\n");
	    exit(0);
	  }  
	  break;
    case 4:
         fd4=open("FIFO",O_WRONLY|O_NONBLOCK);
	 while(1)
	 {
	   printf("Enter string\n");
	   __fpurge(stdin);
	   fgets(buf1,80,stdin);
	   if(write(fd4,buf1,strlen(buf1)+1) <0 )
	     printf("write error\n");
	   if(strncmp(buf1,"exit",4)==0)
	      exit(0);
	}     
	   break;  
     case 5:
          exit(0);
    }
  }
}
