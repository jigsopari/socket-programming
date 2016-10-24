main()
{
  unsigned int val=0xabcd1234;
  char *p;
  p=(char *)&val;
  printf("before over written val=%x \n",val);
  *(p+2)=0xef;
  printf("after over written val=%x \n",val);
}
  
