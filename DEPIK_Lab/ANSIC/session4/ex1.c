#include<stdio.h>
void getSumDifAndProduct(int a,int b,int *sum,int *dif,int *product)
{
  *sum=a+b;
  *dif=a-b;
  *product=a*b;
}
int main()
{
  int a,b,sum,dif,product;
  printf("Enter the value of a=");
  scanf("%d",&a);
  printf("Enter the value of b=");
  scanf("%d",&b);
  getSumDifAndProduct(a,b,&sum,&dif,&product);
  printf("sum=%d\n",sum);
  printf("difference=%d\n",dif);
  printf("product=%d\n",product);
}
  
