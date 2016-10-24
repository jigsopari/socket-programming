#include "file.h"
void pipeCreate(int cirBufSize)
{
  xpipe.buf=malloc(cirBufSize);
  xpipe.maxBufSize=cirBufSize;
}  

int min(int len)
{
  if(len < xpipe.noOfChars)
    return(len);
  if(xpipe.noOfChars < len)
    return(xpipe.noOfChars);
}    
int pipeRead(char *buf,int len)
{
  int i,rlen;
  while(1)
  {
    if(xpipe.noOfChars)
    {
      //len = xpipe.noOfChars;
      rlen = min(len);
      for(i=0;i<rlen;i++)
      {  
        buf[i]=xpipe.buf[xpipe.readIndex++];
        xpipe.noOfChars--;
      }
      buf[i]=0;
      if(xpipe.readIndex == xpipe.maxBufSize)
        xpipe.readIndex=0;
      return(rlen);  
    }
    else
    {
      xpipe.waitFlag=1;
      sem_wait(&xpipe.semaphore);
    }
  }
}
int pipewrite(char *buf,int len)
{
  int i;
  if((xpipe.maxBufSize-xpipe.noOfChars) > len)
  {
    for(i=0;i<len;i++)
    {
      xpipe.buf[xpipe.writeIndex++]=buf[i];
      xpipe.noOfChars++;
    }
  } 
  else
  {
    len=xpipe.maxBufSize-xpipe.noOfChars;
    for(i=0;i<len;i++)
    {
      xpipe.buf[xpipe.writeIndex++]=buf[i];
      xpipe.noOfChars++;
    }
  }
  if(xpipe.writeIndex == xpipe.maxBufSize)
     xpipe.writeIndex = 0;
  if(xpipe.waitFlag == 1)
  {
    sem_post(&xpipe.semaphore);
    xpipe.waitFlag = 0;
  }
  return(len);
}  
 
void *mythread(void *arg)
{
  int len,rlen;
  char rdbuf[xpipe.maxBufSize];
  while(1)
  {
     sem_wait(&semaphore);
     printf("Enter length you want to read from pipe\n");
     scanf("%d",&len);
     rlen = pipeRead(rdbuf,len);
     printf("buffer read %d no of characters\n",rlen);
     //printf("%s\n",rdbuf);
     puts(rdbuf);
     sem_post(&semaphore);
     sleep(1);
  }  
}  

main()
{
  int maxLen,len,ch;
  pthread_t handler;
  
  printf("\nEnter Maximum length of the pipe that u want to create:");
  scanf("%d",&maxLen);
  
  wrBuf=malloc(2*maxLen);
  pipeCreate(maxLen);  
  pthread_create(&handler,NULL,mythread,(void *)0);
  sem_init(&xpipe.semaphore,0,0);/*for read and write */
  sem_init(&semaphore,0,1);/* for synchronisation */
  while(1)
  {
     sem_wait(&semaphore);
     printf("1.Write\n");
     printf("2.exit\n");
     printf("Enter choice:");
     scanf("%d",&ch);
     switch(ch)
     {
        case 1:
             printf("Enter length you want to write into pipe:");
             scanf("%d",&len);
             printf("Enter string\n");
             __fpurge(stdin);
             fgets(wrBuf,2*maxLen,stdin);
             //len = strlen(wrBuf)+1; 
             pipewrite(wrBuf,len);
             sem_post(&semaphore);
             sleep(1);
	     break;
        case 2:
             exit(0);
     }
   }  
}

  
