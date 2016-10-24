
void dispAsHexNumber(int val);
main()
{
  int val;
  printf("Enter decimal number:");
  scanf("%d",&val);
  dispAsHexNumber(val);

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
   
  
