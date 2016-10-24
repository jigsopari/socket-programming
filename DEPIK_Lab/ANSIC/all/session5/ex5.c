main()
{
  int arr[10]={0,1,2,3,4,5,6,7,8,9};
  int *ptr1,*ptr2;
  ptr1=&arr[1]; 
  ptr2=&arr[7];
*ptr1=100;
*ptr2=1000;  

printf("address of ptr1=%u\n",ptr1); 
  printf("address of ptr2=%u\n",ptr2);
  printf("difference of ptr1 and ptr2=%u\n",ptr2-ptr1);
printf("%d",*ptr2-*ptr1);
}
