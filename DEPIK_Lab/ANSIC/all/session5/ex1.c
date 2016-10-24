main()
{
  int intval,*p1;
  short shval,*p2;
  char chval,*p3;
  p1=&intval;
  p2=&shval;
  p3=&chval;
  *p1=1000;
  *p2=100;
  *p3=10;
 printf("intval=%d\n",intval);
 printf("shval=%d\n",shval);
 printf("chval=%d\n",chval);
}
