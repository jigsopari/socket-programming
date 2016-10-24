/***************************** Header Functions ***********************/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
/******************************* Main Function ************************/
main()
{
  int max,i,j,rd,x,first,newNoInt,inLen=0,len,fd,buf[100],*rdBuf;
  
  printf("\nEnter how many integers u would like to store in a file:");
  scanf("%d",&max);
  
  printf("Enter the first integer:");
  scanf("%d",&first);
  
  buf[0]=first;
/****************************** opening file ************************/  

  fd = open("file.int",O_RDWR);
  if(fd < 0)
  { printf("\nCreating file ...");
    fd=open("file.int",O_RDWR | O_CREAT,0644);
    
    if(fd<0)
    { printf("\nCould not create file");
      exit(1);
    }
  }
/*************************** writing on to file ********************/  

newNoInt=max;
  i=first;
  for(j=0;j<newNoInt;i++,j++)
  {
    buf[j]=i;
    if(j==100)
    { j=0;
      newNoInt=newNoInt-100;
      x = write(fd,buf,4*100); 
	if(x!=400)  printf("write error");
      inLen=inLen+x;  /*Inlen=Intermediate length*/

    } 
  }
  len=write(fd,buf,newNoInt*4);

   if(len!=newNoInt*4)    printf("write error");
/****************************** reading file ************************/  

  lseek(fd,0,0);
  rdBuf=(int *)malloc(inLen+len);
  rd=read(fd,rdBuf,inLen+len);
  
  if(rd < 0)  printf("\nread error\n");
    
  printf("\nrd=%d\n",rd/4);
   
  for(i=0;i<rd/4;i++)    printf(" %d ",rdBuf[i]);
}  
