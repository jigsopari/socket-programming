main()
{
  int intval=0x12345678,i;
  short shval=0x3456;
  char chval=0x12,*p1;
  p1=(char *)&intval;
  for(i=0;i<4;i++)
  {
     printf("\nintval=%x",*(p1+i));
  }

  p1=(char *)&shval;
  for(i=0;i<2;i++)
  {
     printf("\nshval=%x",*(p1+i));
  }
     p1=&chval;
     printf("\nchval=%x\n",*p1);
}
