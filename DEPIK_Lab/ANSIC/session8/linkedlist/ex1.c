#if 0
Adds given node to the tail of the linked list.
delete the first node in the linked list whose info field matches with given value.
search and return pointer to the node whose info field value matches with the given value.

#endif
//STANDARD HEADER FILES
#include <stdio.h>
#include <stdlib.h>

//USER DEFINED HEADER FILES
#include "link.h"
/*
 * displays all the nodes in the linked list starting from head of the linked list.use the above function.
 */
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
    {
     temp=temp->pNxtNode;
    }
  }
  return NULL;
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
    printf("4.Delete node.");
    printf("5.Search node.");
    printf("6.Exit.");
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
          printf("\n%d\n",ret);
          break;    
    case 6:
          exit(1);
    }
  }
}       


/*
 * Adds given node to the head of the linked list
 */
void addNodeToHead(sampNode_t *pNode)
{
  fillNode(pNode);
  pNode->pNxtNode=pHead;
  pHead=pNode;
}

/*
 * Fill the info filed of given node by taking data from user.
 */
void fillNode(sampNode_t *pNode)
{
  printf("Enter Phone No:");
  scanf("%d",&pNode->info);
}

/*
 *displays the structure fields only info field.
 */
void dispNode(sampNode_t *p)
{
  printf("The element:%d\n",p->info);
}
