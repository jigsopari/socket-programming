void dispAsHexNumber(int val);
int atoi(char *digitString);

int atoi(char *digitString)
{
  int sum = 0;
  while(*digitString != '\0')
  {
    sum = (sum * 10) + (*digitString - '0');
    digitString++;
  }
  return sum;
}

void dispAsHexNumber(int val)
{
  int i=0,hex;
  char array[4];
  while(val)
  {
    hex=val%16;
    if(hex<10)
    array[i++]=(val%16)+'0';
    else
    array[i++]=(val%16)+'0'+39;
    val=val/16;
  }
  while(i>0)
  {
    putchar(array[--i]);
  }
}

main()
{
  int ii;
  char str[]="123";
  ii = atoi(str);
  printf("ii = %d\n",ii);
  
  dispAsHexNumber(ii);
} 
