void dispDecimalInteger(int val);

main()
{
  int val;
  printf("Enter decimal number:");
  scanf("%d",&val);
  dispDecimalInteger(val);
}

void dispDecimalInteger(int val)
{
  int i=0;
  char array[4];
  while(val)
  {
    array[i++]=(val%10)+'0';
    val=val/10;
  }
  while(i>0)
  {
    putchar(array[--i]);
    printf("%c",array[--i]);
  }
}
   
