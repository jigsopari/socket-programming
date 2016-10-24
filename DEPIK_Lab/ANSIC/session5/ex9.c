#include<stdio.h>
void fillMemory(unsigned char *pBuf,int size,unsigned char val)
{
  int i;
  for(i=0;i<=63;i++)
  {
   *(pBuf+i)=val;
  }
}
  
void main()
{
  int i,n=1;
  char arr[64];
  fillMemory(arr,64,1);
  for(i=0;i<=63;i++)
  {
    printf("%d ",arr[i]);
    if(n%16==0)
    printf("\n");

    n++;
  }
} 
