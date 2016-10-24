#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

char message[100];
sem_t sem;

void *threadfun1(void *msg)
{
   int len;
   while(1)
   {
      sem_wait(&sem);
     printf("I am in Thread 1:\n");
     printf("Enter line 1:");
     __fpurge(stdin);
     fgets(message,80,stdin);
     len = strlen(message);
     printf("Enter line 2:");
     __fpurge(stdin);
     fgets(message+len,80,stdin);
      puts(message);
     printf("Enter exit to terminate\n");
     if(strncmp(message,"exit",4)==0)
       exit(0);
     sem_post(&sem);
     sleep(1);
   }
}

void *threadfun2(void *msg)
{
   int len;
   while(1)
   {
      sem_wait(&sem);
     printf("I am in Thread 2:\n");
     printf("Enter line 1:");
     __fpurge(stdin);
     fgets(message,80,stdin);
     len = strlen(message);
     printf("Enter line 2:");
     __fpurge(stdin);
     fgets(message+len,80,stdin);
      puts(message);
     printf("Enter exit to terminate\n");
     if(strncmp(message,"exit",4)==0)
       exit(0);
     sem_post(&sem);
     sleep(1); 
   }
}
void *threadfun3(void *msg)
{
   int len;
   while(1)
   {
      sem_wait(&sem);
     printf("I am in Thread 3:\n");
     printf("Enter line 1:");
     __fpurge(stdin);
     fgets(message,80,stdin);
     len = strlen(message);
     printf("Enter line 2:");
     __fpurge(stdin);
     fgets(message+len,80,stdin);
      puts(message);
     printf("Enter exit to terminate\n");
     if(strncmp(message,"exit",4)==0)
       exit(0);
     sem_post(&sem);
     sleep(1);
   }
}

main()
{
  int len;
  pthread_t handler1;
  pthread_t handler2;
  pthread_t handler3;

  sem_init(&sem,0,1);
  pthread_create(&handler1,NULL,threadfun1,message);
  pthread_create(&handler2,NULL,threadfun2,message);
  pthread_create(&handler3,NULL,threadfun3,message);
  while(1)
  {
     sem_wait(&sem);
     printf("I am in main\n:");
     printf("Enter line 1:");
     __fpurge(stdin);
     fgets(message,80,stdin);
     len = strlen(message);
     printf("Enter line 2:");
     __fpurge(stdin);
     fgets(message+len,80,stdin);
     puts(message);
     printf("Enter exit to terminate\n");
     if(strncmp(message,"exit",4)==0)
       exit(0);
     sem_post(&sem);
     sleep(1);  
  } 
  
}  

