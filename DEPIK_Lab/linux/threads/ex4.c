#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

char message[100];
sem_t sem;

void *threadfun1(void *msg)
{
   while(1)
   {
      sem_wait(&sem);
     if(strncmp(message,"exit",4)==0)
       exit(0);
      printf("\nThread 1:"); 
      puts(message);
   }
}

void *threadfun2(void *msg)
{
   while(1)
   {
      sem_wait(&sem);
     if(strncmp(message,"exit",4)==0)
       exit(0);
      printf("\nThread 2:"); 
      puts(message);
   }
}
void *threadfun3(void *msg)
{
   while(1)
   {
      sem_wait(&sem);
     if(strncmp(message,"exit",4)==0)
       exit(0);
      printf("\nThread 3:"); 
      puts(message);
   }
}
void *threadfun4(void *msg)
{
   while(1)
   {
      sem_wait(&sem);
      if(strncmp(message,"exit",4)==0)
      exit(0);
      printf("\nThread 4:"); 
      puts(message);
   }
}

main()
{
  int len;
  pthread_t handler1;
  pthread_t handler2;
  pthread_t handler3;
  pthread_t handler4;

  sem_init(&sem,0,0);
  pthread_create(&handler2,NULL,threadfun2,message);
  pthread_create(&handler1,NULL,threadfun1,message);
  pthread_create(&handler4,NULL,threadfun4,message);
  pthread_create(&handler3,NULL,threadfun3,message);
  while(1)
  {
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

