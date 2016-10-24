#include <stdio.h>
#include "file.h"

main()
{
   int ch;
   element_t *p;
   while(1)
   {
      printf("1.add element to queue");
      printf("2.get element from queue");
      printf("3.Display all elements in the queue");
      printf("4.exit");
      printf("Enter choice:");
      scanf("%d",&ch);
      switch(ch)
      {
         case 1:
              p=(element_t *)malloc(sizeof(element_t));
              addElementToQ(p);
              break;
         case 2:
              displayQueue();
              break;
        case 3:
              p=(element_t *)malloc(sizeof(element_t));
              getElementFromQ(p);
              break;
        case 4:
              exit(1);
     }
   }
}
