
#include <stdio.h>
#include "link.h"

/*void addNodeToHead(sampNode_t *pNode)
{
  fillNode(pNode);
  pNode->pNxtNode=pHead;
  pHead=pNode;
}*/
void fillNode(sampNode_t *pNode)
{
  printf("Enter Phone No:");
  scanf("%d",&pNode->info);
}
void dispNodes()
{
  sampNode_t *pN;
  pN=pHead;
  while(pN)
  {
    dispNode(pN);
    pN=pN->pNxtNode;
  }
}
void dispNode(sampNode_t *p)
{
  printf("The element:%d\n",p->info);
}
/*void addNodeToTail(sampNode_t *pNode)
{
   sampNode_t *temp;
  if(pHead==NULL)
  {
    fillNode(pNode);
    pNode->pNxtNode=NULL;
    pHead=pNode;
  }
  else
  {
    temp=pHead;
    while(temp->pNxtNode)
      temp=temp->pNxtNode;
    
    fillNode(pNode);
    temp->pNxtNode=pNode;
    pNode->pNxtNode=NULL;
  }  
} */     
int deleteNode(int val)
{
  sampNode_t *temp,*previous;
  temp=pHead;
  printf("Enter the number:");
  scanf("%d",&val);
  while(temp)
  {
    if(temp->info==val)
    {
         if(temp==pHead)
         {
             pHead=pHead->pNxtNode;
             return SUCCESS;
         }
         else
         {
            previous->pNxtNode=temp->pNxtNode;
            free(temp);
            return SUCCESS;
         }    
    }
    else
    {
         previous=temp;
         temp=temp->pNxtNode;
    }
  }
  return NOT_FOUND;
}
sampNode_t *searchNode(int val)
{
  sampNode_t *temp=pHead;
  printf("Enter the number:");
  scanf("%d",&val);
  while(temp)
  {
    if(temp->info==val)
      return temp;
    else
    {
     temp=temp->pNxtNode;
    }
  }
  return NULL;
}  
void insertNodeInSortedList(sampNode_t *pNode)
{
  int val;
  sampNode_t *previous,*temp=pHead;
  printf("Enter the Phone(info):");
  scanf("%d",&val);
  pNode->info=val;
  if(pHead==NULL)
  {
    pNode->pNxtNode=NULL;
    pHead=pNode;
  }
  else
  {
     if(val < temp->info)
     {
        pNode->pNxtNode=temp;
        pHead=pNode;
     }
     else
     {
        while((temp!=NULL)&&(val > temp->info))
       {
           previous=temp;
           temp=temp->pNxtNode;
       }
       pNode->pNxtNode=previous->pNxtNode;
       previous->pNxtNode=pNode;
    }
  }
}
main()
{
  int ch,num,res;
  sampNode_t *ret;
  sampNode_t *p;
  while(1)
  {
    printf("1.Insert sorted.");
    printf("2.Display.");
    printf("3.Delete node.");
    printf("4.Search node.");
    printf("5.Exit.");
    printf("Enter choice:");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:
           p=(sampNode_t *)malloc(sizeof(sampNode_t));
           insertNodeInSortedList(p); 
           break;
     case 2:
           dispNodes();
           break;
    case 3:
          res=deleteNode(num);
          printf("\n%d\n",res);
          break;    
    case 4:
          ret=searchNode(num);
          printf("\n%d\n",ret);
          break;    
    case 5:
          exit(1);
    }
  }
}       
