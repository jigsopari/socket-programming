main()
{
  unsigned int uival,stbit,bitval,range,res;

  printf("Enter a 32 bit number:");
  scanf("%x",&uival);

  printf("Enter a starting bit number that you required to set:");
  scanf("%d",&stbit);
  printf("Enter a bit value that you required to set:");
  scanf("%d",&bitval);
  printf("Enter a No.of bits that you required to set:");
  scanf("%d",&range);

  res = setbits(uival,stbit,range,bitval);
  printf("resultant uival=%x",res);
}
 

  int setbits(int uival,int stbit,int range,int bitval)
{
  int mask1,res,ret;
  
  ret=mask(range);//getting the range number of 1s
  mask1=ret<<stbit;//moving the number to the masked position
  
  if(bitval == 1)
  res=uival | mask1;
  
  else
    res=uival & (~mask1);
  
  return res;
}

int mask(int range)
{
  int p=1,i;
  for(i=0;i<range;i++)
     p=p*2;
  
  return p-1;
}  
