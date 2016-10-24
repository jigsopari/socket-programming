main()
{
  unsigned int uival,uival1,ret,ch,range;

  printf("Enter a 32 bit number:");
 scanf("%x",&uival);

  printf("Enter starting bit number to be extracted of extracted range:");
  scanf("%d",&ch);
  printf("Enter No.of bits to be extracted of extracted range:");
  scanf("%d",&range);
  uival1=extractBits(uival,ch,range);

  printf("uival=%x",uival);
}
 
extractBits(int uival, int ch, int range)
{
  int uival1,ret;
  uival1=uival>>ch;
  ret=mask(range);
  uival=uival1&ret;
  return  uival;
}

int mask(int n)
{
  int i,p=1;
  for(i=0;i<n;i++)
  {
    p=p*2;
  }
  return(p-1);
}   
