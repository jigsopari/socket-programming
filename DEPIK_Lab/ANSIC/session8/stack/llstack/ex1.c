#include <stdio.h>
#include "llstack.h"
main()
{
  int ch,ret;
  //strval.top=-1;
  element_t *p;
  while(1)
  {
     printf("1.push Element to stack");
     printf("2.pop Element from stack");
     printf("3.Display all elements in the stack");
     printf("4.Exit");
     printf("Enter choice:");
     scanf("%d",&ch);
     switch(ch)
     {
        case 1:
             p=(element_t *)malloc(sizeof(element_t));
             ret=pushElementToStack(p);
             printf("\n%d\n",ret);
             break;
       case 2:
             p=(element_t *)malloc(sizeof(element_t));
             popElementFromStack(p);    
             break;
       case 3:
             displayStack();
             break;
       case 4:
            exit(1);
    }
  }
}       


