#include <stdio.h>
#include "file.h"

main()
{
   int ch,status;
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
              status=addElementToQ(p);
	      if(status==0)
	        printf("ELEMENT ADDED SUCCESSFULLY\n");
	      else
	        printf("QUEUE FULL ERROR\n");
              break;
         case 3:
              displayQueue();
              break;
         case 2:
              p=(element_t *)malloc(sizeof(element_t));
              status=getElementFromQ(p);
	      if(status==0)
	      {
                 printf("emp no.%d ",p->empNo);  
                 printf("salary:%d\n ",p->salary);  
	      }
	      else 
	        printf("QUEUE EMPTY ERROR\n");
	         
              break;
        case 4:
              exit(1);
     }
   }
}
