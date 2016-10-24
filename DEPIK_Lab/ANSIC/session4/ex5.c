#include<stdio.h>
void function3()
{printf("i am in function3\n");}

void function2(void (*ptr)())
{
  printf("i am in function2\n");
  printf("i am calling function3\n");
  (*ptr)();
}

main()
{
  printf("i am in main\n");
  printf("i am calling function 2\n");
  function2(function3);
}  
