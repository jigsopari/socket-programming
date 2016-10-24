#include <stdio.h>
#include "stack.h"
main()
{
  int ch;
  element_t *p;
  while(1)
  {
     printf("1.push Element to stack");
     printf("2.Display all elements in the stack");
     printf("3.Exit");
     printf("Enter choice:");
     scanf("%d",&ch);
     switch(ch)
     {
        case 1:
             p=(element_t *)malloc(sizeof(element_t));
             pushElementToStack(p);
             break;
       case 2:
             displayStack();
             break;
       case 3:
            exit();
    }
  }
}       


