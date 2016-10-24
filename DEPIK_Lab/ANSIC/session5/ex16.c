#include<stdio.h>
void main()
{
  int *p,i,j=10;
  p=(int *)malloc(10);
  for(i=0;i<10;i++)
  {
    *(p+i)=j;
    j++;
  }
  for(i=0;i<10;i++)
  {
    printf("%d ",*(p+i));
  }
} 
