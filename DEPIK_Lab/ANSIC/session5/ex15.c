#include<stdio.h>
int array[10];
int *p=array;
void main()
{
  int i,j=101;	
  printf("content of p=%u\n",p);
  printf("array variables=");	  
  for(i=0;i<10;i++)
  {
    printf("%d ",array[i]);
  }
  for(i=0;i<10;i++)
  {  
      *(p+i)=j;
      j++;
  }    
  printf("\nafter initialization array variables using array as pointer=");	  
  
  for(i=0;i<10;i++)
  {
    printf("%d ",*(array+i));
  }
  
  printf("\nafter initialization array variables using  p as pointer=");	  

  for(i=0;i<10;i++)
  {
    printf("%d ",*(p+i));
  }
  
  printf("\nafter initialization array variables using  p as pointer and each time by incrementing the pointer=");
  for(i=0;i<10;i++)
  {
    printf("%d ",*p);
    p++;
  }
  
  printf("\nafter initialization array variables using array as an array=");	  

  for(i=0;i<10;i++)
  {
    printf("%d ",array[i]);
  }
  
  
  
  
