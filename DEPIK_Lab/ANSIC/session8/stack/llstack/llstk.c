#include <stdio.h>
#include "llstack.h" 
int pushElementToStack(element_t *pElm)
{
  printf("Enter Employee No:");
  scanf("%d",&pElm->empNo);
  printf("Enter Salary:");
  scanf("%d",&pElm->salary);
  pElm->pNext=pHead;
  pHead=pElm;
  noOfElements++;
}
void displayStack()
{
   element_t *p;
   p=pHead;
   while(p)
   {
      printf("\nEmployee No:%d   ",p->empNo);
      printf("Salary:%d   ",p->salary);
      p=p->pNext;
   }
}
int popElementFromStack(element_t *pElm)
{
   *pElm=*pHead;
   pHead=pHead->pNext; 
   printf("\nEmployee No:%d   ",pElm->empNo);
   printf("Salary:%d   ",pElm->salary);
   noOfElements--;
}

