void getSumDifAndProduct(int a,int b,int *ptr)
{                                               //dynamic memory allocation//
  *ptr=a+b;
  *(ptr+1)=a-b;
  *(ptr+2)=a*b;
}
int main()
{
  int a,b,*ptr;
  ptr=(int *)malloc(3*sizeof(int));
  printf("Enter the value of a=");
  scanf("%d",&a);
  printf("Enter the value of b=");
  scanf("%d",&b);
  getSumDifAndProduct(a,b,ptr);
  printf("sum=%d\n",*ptr);
  printf("difference=%d\n",*(ptr+1));
  printf("product=%d\n",*(ptr+2));
}
  
