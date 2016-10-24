main()
{
  int i;
  float fval=10.1234;
  char *ptr;
  ptr=(char *)&fval;
  printf("float variable=\n");
  for(i=0;i<4;i++)
  {
    printf("%x",*(ptr+i));
  }
}
