#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void * thread1(void * arg)
{
   while(1)
   {
     sleep(5);
     printf("thread1 slept for 5 seconds\n");
   }
}   

void * thread2(void * arg)
{
   while(1)
   {
     sleep(10);
     printf("thread2 slept for 10 seconds\n");
   }
}   

void * thread3(void * arg)
{
   while(1)
   {
     sleep(15);
     printf("thread3 slept for 15 seconds\n");
   }
}   

int main()
{
  pthread_t my_handle1;
  pthread_t my_handle2;
  pthread_t my_handle3;
  int num;
  pthread_create(&my_handle1,NULL,thread1,(void *)0);
  pthread_create(&my_handle2,NULL,thread2,(void *)0);
  pthread_create(&my_handle3,NULL,thread3,(void *)0);
  while(1)
  {
    printf("Enter the Number:\n");
    scanf("%d",&num);
    if(num==100)
      _exit(0);
    else
      continue;
  }
}  
