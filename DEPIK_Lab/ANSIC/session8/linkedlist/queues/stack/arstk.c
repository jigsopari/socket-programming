#include <stdio.h>
#include "stack.h"
int pushElementToStack(element_t *pElm)
{  
   int top=-1;
   printf("Enter Employee No:");
   scanf("%d",&pElm->empNo);
   printf("Enter salary:");
   scanf("%d",&pElm->salary);
   if(noOfElements==MAX_STACK_SIZE)
      return STACK_FULL_ERROR;
   else 
   {
      strval.sBuf[++strval.top]=pElm;
      noOfElements++;
   }
}         
void displayStack()
{
  int i;
  for(i=stval.top;i<stval.noOfElements;i++)
  {
     printf("emp No:%d",stval.sBuf[stval.top].empNo);
     printf("salary:%d",stval.sBuf[stval.top].salary);
  }
}
 
