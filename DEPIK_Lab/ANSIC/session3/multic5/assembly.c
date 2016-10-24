int sum;
void testFunc();
main()
{
  testFunc();
}
 void testFunc()
{
  int a,b,c;
  a=20;
  b=a;
  c=a+b;
  sum=average(a,b,c);
  printf("average=%d\n",sum);
}
 
 int  average(int x,int y,int z)
{
  int av;
  av=(x+y+z)/3;
return(av);
  
}

