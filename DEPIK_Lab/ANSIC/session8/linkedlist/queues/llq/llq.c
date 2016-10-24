#include <stdio.h>
#include "ex2.h"

int addElementToQ(element_t *pElm)
{
   printf("Enter Employee Number:");
   scanf("%d",&pElm->empNo);
   printf("Enter salary:");
   scanf("%d",&pElm->salary);
   if(wrHead==NULL)
   {
      wrHead=rdHead=pElm;
      pElm->pNxt=NULL;
   }
   else
   {
      wrHead->pNxt=pElm;
      pElm->pNxt=NULL;
      wrHead=pElm;
   }
}       
void displayQueue()
{
  element_t *temp;
  temp=rdHead;
  while(temp)
  {
    printf("Emp No:%d ",temp->empNo);
    printf("Salary:%d\n",temp->salary);
    temp=temp->pNxt;
  }
}  
int getElementFromQ(element_t *pElm)
{
  if(rdHead==NULL)
    return Q_EMPTY_ERROR;
  else
    pElm=rdHead;
    rdHead=rdHead->pNxt;
    printf("Emp No:%d ",pElm->empNo);
    printf("Salary:%d\n",pElm->salary);
    return SUCCESS; 
}
