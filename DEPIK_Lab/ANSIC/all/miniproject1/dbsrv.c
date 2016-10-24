#include <stdio.h>
#include "file.h"
void addToll(empRecord_t *p);
void prepareModiDetails(char *pCmdMsg,empRecord_t *pNode);

int processDbCmdMsg(unsigned char *pCmdMsg,unsigned *pRespMsg)
{ 
   int retval;
   //char *msg;  
   int Id;
   empRecord_t *rec;
   empRecord_t *pNode;
   pNode=(empRecord_t *)malloc(sizeof(empRecord_t));
   switch(pCmdMsg[2])
   {
     case '1':
          retval=addEmpDetails(pCmdMsg);   
          if(retval == SUCCESS)
             pRespMsg[0]='0';
          break;
     case '2':
          retval=deleteEmp(pCmdMsg[3]);
          if(retval == SUCCESS)
             pRespMsg[0]='0';
          else
          {
            if(retval==NOT_FOUND)
              pRespMsg[0]='2';
          }
          break;
     case '3':
          rec=(empRecord_t *)malloc(sizeof(empRecord_t)); 
          //msg=(char *)malloc(50*sizeof(char)); 
          retval=getEmpDetails(pCmdMsg[3],pRespMsg);
          break;
     case '4':
          prepareModiDetails(pCmdMsg,pNode); 
          retval=modifyEmpDetails(pNode);
          if(retval == SUCCESS)
             pRespMsg[0]='0';
          else
          {
            if(retval==NOT_FOUND)
              pRespMsg[0]='2';
          }
         //modifyEmpDetails(pCmdMsg);
 
   }
} 
int addEmpDetails(char *pCmdMsg)
{   
  int indx;
  empRecord_t *pNode;
          pNode=(empRecord_t *)malloc(sizeof(empRecord_t));
          indx=3;
          memcpy(&pNode->Id,pCmdMsg+indx,4);
          indx+=4;
          strcpy(pNode->name,pCmdMsg+indx);
          indx=indx+strlen(pCmdMsg+indx)+1;
          memcpy(&pNode->salary,pCmdMsg+indx,4);
          indx+=4;
          memcpy(&pNode->phoneNum,pCmdMsg+indx,4);
          indx+=4;

          addToll(pNode); 
          return SUCCESS; 
}
void addToll(empRecord_t *p)
{
   p->pNxt=pHead;
   pHead=p;
}

int deleteEmp(int empId)
{
   empRecord_t *temp;
   empRecord_t *prev;
   temp=pHead;
   while(temp)
   {
      if(temp->Id==empId)
      {
         if(temp==pHead)
         {
            pHead=pHead->pNxt;
            free(temp);
            return SUCCESS;
         } 
         else
         {
            prev->pNxt=temp->pNxt;
            free(temp);
            return SUCCESS;
         }
      }
      else
      {
         prev=temp;
         temp=temp->pNxt;
      }
  } 
  return NOT_FOUND;
}

           

int getEmpDetails(int empId,unsigned char *pOutMsg)
{
      
   int index=3;
   empRecord_t *temp;
   temp=pHead;
   while((temp!=NULL) && temp->Id!=empId)
   {
      temp=temp->pNxt;
   }
  if(temp==NULL)
  {
     return NOT_FOUND;
    //printf("Not Found");
  }
  else
  {
    memcpy(&pOutMsg[3],&temp->Id,4);
    index+=4;
    strcpy(&pOutMsg[index],temp->name);
    index=index+strlen(temp->name)+1;
    memcpy(&pOutMsg[index],&temp->salary,4);
    index+=4;
    memcpy(&pOutMsg[index],&temp->phoneNum,4);
    index+=4;
    return SUCCESS;
  }
}
void prepareModiDetails(char *pCmdMsg,empRecord_t *pNode)
{ 
  int indx;
          indx=3;
          memcpy(&pNode->Id,pCmdMsg+indx,4);
          indx+=4;
          strcpy(pNode->name,pCmdMsg+indx);
          indx=indx+strlen(pCmdMsg+indx)+1;
          memcpy(&pNode->salary,pCmdMsg+indx,4);
          indx+=4;
          memcpy(&pNode->phoneNum,pCmdMsg+indx,4);
          indx+=4;
}
int modifyEmpDetails(empRecord_t *pEmpRec)
{
   int index=0;
   empRecord_t *temp;
   temp=pHead;
   while((temp!=NULL) && temp->Id!=pEmpRec->Id)
         temp=temp->pNxt;
     if(temp==NULL)
      //printf("Not Found");
      return NOT_FOUND;
    else
    {
      *temp=*pEmpRec;
      return SUCCESS;
    }
}
