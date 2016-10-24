#include<stdio.h>
main()
{
  int id,option;
  while(1)
  {
    printf("Enter 1 to execute 'ls' program in child process and 0 to exit\n");
    scanf("%d",&option);
    if(option==0)
      exit(1);
    else
    {
      id=fork();//hello is executable file of exec.c
      if(id==0)
       // execl("/home/durga/linux/process/practice/hello","hello",0);
        execl("./hello","hello",0);
      wait();
    }
  }
}  
