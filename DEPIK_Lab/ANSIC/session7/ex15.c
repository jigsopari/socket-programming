main()
{
   char array[]={49};
   unsigned int binary;
   binary=getHexNumber(array);
   printf("%x",binary);
}
int getHexNumber(char *ptr)
{
  int hex;
  int sum=0;
  while(*ptr)
  {
    hex=(*ptr)-'0';
    if(hex<10)
    sum=(sum*10)+(*ptr)-'0';
    else
    sum=(sum*10)+(*ptr)-'0'+39;
    ptr++;
  }
  return(sum);
}





