void showbits(int n)
{
  unsigned int k;
  int i,j,andmask;
  char array[32];
  for(i=31;i>=0;i--)
  {
    andmask=1<<i;
    k=n&andmask;

    array[i]=(k==0?0:1);
  }
  for(i=31;i>=0;i--)
  {
    if(array[i]==1)
     break;
     
  }
  for(j=i;j>=0;j--)
   printf("%d",array[j]);
   
}

main()
{
  unsigned int val,i;
  printf("Enter hex number:");
  scanf("%x",&val);
  printf("the hex equivalent of %x in binary form is= %d",val);
  showbits(val);
}  
