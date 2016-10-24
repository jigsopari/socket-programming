
#include <stdio.h>
#include "ex4.h"

void fillNode(sampNode_t *pNode)
{
  printf("Enter Phone No:");
  scanf("%d",&pNode->info);
}
void addNodeToHead(sampNode_t *pNode)
{ 
  fillNode(pNode);
  if(pHead==NULL)
  {
     pNode->pNxtNode=pHead;
     pHead=pNode;
     pTail=pNode;
  }
  else
  {
     pNode->pNxtNode=pHead;
     pHead=pNode;
  }
     
}
void dispNode(sampNode_t *p)
{
  printf("The element:%d\n",p->info);
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
void addNodeToTail(sampNode_t *pNode)
{
   //sampNode_t *temp;
   fillNode(pNode);
   pNode->pNxtNode=NULL;
  if(pTail==NULL)
  {
    pTail=pNode;
    pHead=pNode;
  }
  else
  {
    //temp=pHead;
    //while(temp->pNxtNode)
     // temp=temp->pNxtNode;
    
    pTail->pNxtNode=pNode;
    pTail=pNode;
    //pNode->pNxtNode=NULL;
  }  
}      
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
     temp=temp->pNxtNode;
  }
  return NULL;
}  
void deleteNodeFromDll(sampNode_t *pNode)
{
  sampNode_t *temp;
  if(pNode==pHead)
  {
    pNode->pNxtNode->pPrvNode=NULL;
    pHead=pNode->pNxtNode;
  }
  else if(pNode==pTail)
  {  
    pNode->pPrvNode->pNxtNode=NULL;
    pTail=pNode->pPrvNode;
  }
  else 
  {
  pNode->pPrvNode->pNxtNode=pNode->pNxtNode;
  pNode->pNxtNode->pPrvNode=pNode->pPrvNode;
  }
}
main()
{
  int ch,num,res;
  sampNode_t *ret;
  sampNode_t *p;
  while(1)
  {
    printf("1.Add node to head.");
    printf("2.Display.");
    printf("3.Add node to Tail.");
    printf("4.Delete node by traversing from phead.");
    printf("5.Delete node without traversing the linked list.");
    printf("6.Search node.");
    printf("7.Exit.");
    printf("Enter choice:");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:
           p=(sampNode_t *)malloc(sizeof(sampNode_t));
           addNodeToHead(p);
           break;
     case 2:
           dispNodes();
           break;
    case 3:
           p=(sampNode_t *)malloc(sizeof(sampNode_t));
           addNodeToTail(p);
           break;   
    case 4:
          res=deleteNode(num);
          printf("\n%d\n",res);
          break;    
    case 5:
          ret=searchNode(num);
          deleteNodeFromDll(ret);
          break;
    case 6:
          ret=searchNode(num);
          printf("\n%d\n",ret);
          break;    
    case 7:
          exit(1);
    }
  }
}       
