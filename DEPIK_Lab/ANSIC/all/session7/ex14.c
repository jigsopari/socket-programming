main()
{
   char array[5]={49,'2','3','4','\0'};
   int binary;
   binary=getDecimalInteger(array);
   printf("%d",binary);
}
int getDecimalInteger(char *ptr)
{
  int sum=0;
  while(*ptr)
  {
    sum=(sum*10)+(*ptr)-'0';
    ptr++;
  }
  return(sum);
}





