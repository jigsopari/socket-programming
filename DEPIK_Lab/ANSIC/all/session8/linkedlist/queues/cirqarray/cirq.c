#include <stdio.h>
#include "file.h"
int addElementToQ(element_t *pElm)
{
   printf("Enter Employee Number:");
   scanf("%d",&pElm->empNo);
   printf("Enter salary:");
   scanf("%d",&pElm->salary);
   if(stval.noOfElms==MAX_Q_SIZE)
      return Q_FULL_ERROR;
   else 
      stval.qBuf[stval.wrindx++]=*pElm;
   if(stval.wrindx==MAX_Q_SIZE)
      stval.wrindx=0;
   stval.noOfElms++;
}
void displayQueue()
{
  int i;
  for(i=stval.rdindx;i<stval.noOfElms;i++)
  {
     printf("emp no.%d ",stval.qBuf[i].empNo);  
     printf("salary:%d\n ",stval.qBuf[i].salary);  
  }
}
int getElementFromQ(element_t *pElm)
{
   if(stval.noOfElms==0)
      return Q_EMPTY_ERROR;
   else
      *pElm=stval.qBuf[stval.rdindx++];
   if(stval.rdindx==MAX_Q_SIZE)
      stval.rdindx=0;
   stval.noOfElms--;
     printf("emp no.%d ",pElm->empNo);  
     printf("salary:%d\n ",pElm->salary);  
     return SUCCESS;         
}
    
        
