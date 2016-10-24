main()
{
  unsigned int uival,bitnum,bitval,mask,res;

  printf("Enter a 32 bit number:");
  scanf("%x",&uival);

  printf("Enter a bit number that you required to set:");
  scanf("%d",&bitnum);
  printf("Enter a bit valuer that you required to set:");
  scanf("%d",&bitval);

  mask=bitnum<<1;
  if(bitval==1)
  {
  res=uival|mask;
  }
  else
  {
    res=uival&~mask;
  }
  //uival=uival&1;

  printf("resultant uival=%x",res);
} 
