#include <stdlib.h>
typedef struct
{
  int sum;
  int diff;
  int product;
}outStruct_t;



void getSumDifAndProduct(int a,int b,outStruct_t *ptr)
{      
  //int sum,diff,product;
                                    //static memory allocation//
  ptr->sum=a+b;
  ptr->diff=a-b;
  ptr->product=a*b;
}
int main()
{
  int a,b;
  outStruct_t var;
  printf("Enter the value of a=");
  scanf("%d",&a);
  printf("Enter the value of b=");
  scanf("%d",&b);
  getSumDifAndProduct(a,b,&var);
  printf("sum=%d\n",var.sum);
  printf("difference=%d\n",var.diff);
  printf("product=%d\n",var.product);
}
  
