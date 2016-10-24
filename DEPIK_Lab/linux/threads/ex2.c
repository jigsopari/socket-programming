#include <stdio.h>
#include <pthread.h>

void * thread1(void * arg)
{
   while(1)
   {
     sleep(arg);
     printf("thread1 slept for %d seconds\n",arg);
   }
}   


  pthread_t my_handle1;

int main()
{
  int num;
  pthread_create(&my_handle1,NULL,thread1,(void *)5);
  pthread_create(&my_handle1,NULL,thread1,(void *)10);
  pthread_create(&my_handle1,NULL,thread1,(void *)15);
  while(1)
  {
    printf("Enter the Number:\n");
    scanf("%d",&num);
    if(num==100)
      exit(0);
    else
      continue;
  }
}  
