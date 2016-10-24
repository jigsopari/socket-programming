#include<stdio.h>
#define const 0.5
void areaOfRectangle(int length,int width,int *pArea)  
{
  *pArea=length*width;
}  
void areaOfTriangle(int base,int height,int *pArea)  
{
  *(pArea+1)=const*base*height;
}  
void main()
{
  int *pArea,length=5,width=2,base=3,height=4;
  int array[2];
  pArea=array;
  areaOfRectangle(length,width,pArea);  
  areaOfTriangle(base,height,pArea);  
  printf("Rectangle area=%d\n",*pArea);
  printf("Triangle area=%d\n",*(pArea+1));
}  
