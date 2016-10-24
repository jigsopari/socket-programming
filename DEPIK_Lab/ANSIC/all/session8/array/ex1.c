#include <stdio.h>
#include "array.h"
void insertTest();
void  displayTest();
void dispAllElements(void);
void deleteTest(); 
void searchTest();    

int add(void)
{
    int addelement;
    while(1)
    {
        printf("\nDo you want to enter element in the array?(y/n)");
        __fpurge(stdin);
        if(getchar()=='n')
             break;
        printf("\nenter element:");
        scanf("%d",&addelement);
        if(noOfElements==MAX_ARRAY_SIZE)
        return ARRAY_FULL_ERROR;
        sampArray[noOfElements]=addelement;
        noOfElements++;
    }
}

void insertTest()
{
    int index,element,result;
    printf("\nEnter the index(0 to 19):");
    __fpurge(stdin);
    scanf("%d",&index);
    printf("\nEnter the element:");
    scanf("%d",&element);
    result=insertElements(element,index);
    printf("\n%d\n",result);
}
    
int insertElements(int elm,int indx)
{
  int i;
  if(noOfElements==MAX_ARRAY_SIZE)
      return ARRAY_FULL_ERROR;
  if(indx>noOfElements)
      return INVALID_INDEX;
  for(i=noOfElements-1;i>=indx;i--)
      sampArray[i+1]=sampArray[i];
  sampArray[indx]=elm;
  noOfElements++;
  return SUCCESS;
}
void  displayTest()
{
 dispAllElements();
}

void dispAllElements(void)
{
  int i;
  for(i=0;i<=noOfElements;i++)
  {
    printf("%d\t",sampArray[i]);
  }
}
void deleteTest()
{
    int index;
    printf("\nEnter the index(0 to 19):");
    __fpurge(stdin);
    scanf("%d",&index);
    deleteElementAtIndex(index);
}
int deleteElementAtIndex(int indx)
{
    int i;
    if(indx>=noOfElements)
      return INVALID_INDEX;
    for(i=indx;i<noOfElements;i++)
    {
        sampArray[i]=sampArray[i+1];
        noOfElements--;
    }
} 
void searchTest()
{
    int ele,result;
    printf("Enter the ele:");
    //__fpurge(stdin);
    scanf("%d",&ele);
    result=linearSearch(ele);
    printf("\nIndex=%d\n",result);
}         
int linearSearch(int elm)
{
    int i;
    for(i=0;i<=noOfElements;i++)
    {    if(elm==sampArray[i])
            return i;
     } 
           return NOT_FOUND;
}    
main()
{
     int ch;    
     printf("\nThe elements in the array=");
    dispAllElements();
    add();
    while(1)
    {
        printf("\n1.Insert Element");
        printf("\n2.Display Elements");
        printf("\n3.Delete Element");
        printf("\n4.Linear search Element");
        printf("\n5.Exit");
        printf("\nEnter choice:");
        scanf("%d",&ch);
        switch(ch)
        {
              case 1:
                    insertTest();
                    break; 
              case 2:
                    displayTest();
                    break; 
              case 3:
                    deleteTest(); 
                    break; 
              case 4:
                    searchTest();    
                    break; 
              case 5:
                    exit(1);
        }
    }          
}
