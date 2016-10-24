#include <stdlib.h>
typedef struct
{
  int sum;
  int diff;
  int product;
}outStruct_t;



void getSumDifAndProduct(int a,int b,outStruct_t *ptr)
{      
  
                                    //dynamic memory allocation//
  ptr->sum=a+b;
  ptr->diff=a-b;
  ptr->product=a*b;
}
int main()
{
  int a,b;
  outStruct_t *ptr;
  ptr=(outStruct_t *)malloc(sizeof(outStruct_t));
  printf("Enter the value of a=");
  scanf("%d",&a);
  printf("Enter the value of b=");
  scanf("%d",&b);
  getSumDifAndProduct(a,b,ptr);
  printf("sum=%d\n",ptr->sum);
  printf("difference=%d\n",ptr->diff);
  printf("product=%d\n",ptr->product);
}
  
