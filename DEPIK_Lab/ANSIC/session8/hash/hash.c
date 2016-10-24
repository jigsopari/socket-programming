#include <stdio.h>
#include "hash.h"
int addToHashList(hashItem_t *phashItem)
{
   int index;
   printf("Enter name:");
   scanf("%s",phashItem->name);
   printf("Enter age:");
   scanf("%d",&phashItem->age);
   printf("Enter salary:");
   scanf("%d",&phashItem->salary);
   printf("Enter phone Number:");
   scanf("%d",&phashItem->phoneNum);
   index=hash(phashItem->name);
   if(hBuf[index]==NULL)
   {
     phashItem->pNext=NULL;
     hBuf[index]=phashItem;
   }
   else
   {
      phashItem->pNext=hBuf[index];
      hBuf[index]=phashItem;
   }
}

int hash(char *arr)
{
   int sum=0;
   while(*arr)
   {
     sum=sum + 3*(5 + *arr);
     arr++;
   }
   sum=sum%11;
   return  sum;
}
int searchHashList(char *s)
{
   int index;
   hashItem_t *temp;
   index=hash(s);  
   temp=hBuf[index];
   while((temp!=NULL) && strcmp(temp->name,s))
   {
      temp=temp->pNext;
   }
  if(temp==NULL)
  {
    printf("Not Found");
  }
  else
  {
    printf("\nName:%s",temp->name);
    printf("\nAge:%d",temp->age);
    printf("\nsalary:%d",temp->salary);
    printf("\nphone Number:%d\n",temp->phoneNum);
  }
}
  
     
      
