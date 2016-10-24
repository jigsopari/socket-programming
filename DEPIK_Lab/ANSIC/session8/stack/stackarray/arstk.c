#include <stdio.h>
#include "stack.h"
int pushElementToStack(element_t *pElm)
{  
   printf("Enter Employee No:");
   scanf("%d",&pElm->empNo);
   printf("Enter salary:");
   scanf("%d",&pElm->salary);
   if(strval.noOfElements==MAX_STACK_SIZE)
      return STACK_FULL_ERROR;
   else
   {
       strval.sBuf[++strval.top]=*pElm;
       strval.noOfElements++;
       printf("\nsuccess=");
       return SUCCESS;
    }
}

int popElementFromStack(element_t *pElm)
{
  if(strval.noOfElements==0)
    return STACK_EMPTY_ERROR;
  else
   {
    *pElm=strval.sBuf[strval.top];
    
    printf("Employee No:%d   ",pElm->empNo);
    printf("salary:%d\n",pElm->salary);
    strval.top--;
    strval.noOfElements--;
    }
    return SUCCESS;
}

void displayStack()
{
   int i,j=0;
   for(i=0;i<strval.noOfElements;i++)
    {
       printf("Employee No:%d   ",strval.sBuf[i].empNo);
       printf("salary:%d\n",strval.sBuf[i].salary);
    }
}
