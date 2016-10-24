void getSumDifAndProduct(int a,int b,int *ptr)
{                                           //static memory allocation//
  *ptr=a+b;
  *(ptr+1)=a-b;
  *(ptr+2)=a*b;
}

 main()
{
  int a,b,ptr[3];
  printf("Enter the value of a=");
  scanf("%d",&a);
  printf("Enter the value of b=");
  scanf("%d",&b);
  getSumDifAndProduct(a,b,ptr);
  printf("sum=%d\n",*ptr);
  printf("difference=%d\n",*(ptr+1));
  printf("product=%d\n",*(ptr+2));
}
  
