#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

char message[100];
sem_t sem,semsyn;

void *threadfun1(void *msg)
{
   while(1)
   {
      sem_wait(&sem);
     if(strncmp(message,"exit",4)==0)
       exit(0);
      printf("\nThread 1(Enter exit to terminate):"); 
      puts(message);
      sem_post(&semsyn);
   }
}


main()
{
  int len;
  pthread_t handler1;

  sem_init(&sem,0,0);
  sem_init(&semsyn,0,1);
  pthread_create(&handler1,NULL,threadfun1,message);
  while(1)
  {
     sem_wait(&semsyn);
     printf("Enter string:");
     __fpurge(stdin);
     fgets(message,100,stdin);
     len = strlen(message);
     if(message[len-1] == '\n')
        message[len-1] = 0;
     sem_post(&sem);
     if(strncmp(message,"exit",4)==0)
       exit(0);
  } 
  
}  

