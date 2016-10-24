#include <stdio.h>
#include "array.h"

void insertTest();
void  displayTest();
void dispAllElements(void);
//void deleteTest(); 
//void searchTest();    

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
    printf("\nEnter the element:");
    scanf("%d",&element);
    result=insertElement(element);
    printf("\n%d\n",result);
}
    
int insertElement(int elm)
{
    int i;
    if(noOfElements==MAX_ARRAY_SIZE)
      return ARRAY_FULL_ERROR;
    
    for(i=noOfElements-1;sampArray[i]>elm;i--)
      sampArray[i+1]=sampArray[i];
    sampArray[i+1]=elm;
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
void searchTest()
{
    int ele,result;
    printf("Enter the ele:");
    //__fpurge(stdin);
    scanf("%d",&ele);
    result=binarySearch(ele);
    printf("\nIndex=%d\n",result);
}         
int binarySearch(int elm)
{
    int flag=1;
    int lower=0;
    int higher=noOfElements-1;
    int mid=(lower+higher)/2;
    for(mid=(lower+higher)/2;lower<=higher;mid=(lower+higher)/2)
    {    
         if(sampArray[mid]==elm)
         {
            return mid;
            flag=0;
            break; 
         }
         if(sampArray[mid]>elm)
           higher=mid-1;
         else
          lower=mid+1;
    }
    if(flag)
        return NOT_FOUND;
}
    
main()
{
     int ch;    
     printf("\nThe elements in the array=");
    dispAllElements();
     printf("Enter the array elements in ascending ordet:"); 
    add();
    while(1)
    {
        printf("\n1.Insert Element");
        printf("\n2.Display Elements");
        printf("\n3.Binary search Element");
        printf("\n4.Exit");
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
                 searchTest();    
                  break; 
              case 4:
                    exit(1);
        }
    }          
}
