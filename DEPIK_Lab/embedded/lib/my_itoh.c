
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
    array[i++]=(val%16)+'a'-10;
    val=val/16;
  }
  puts("\n\rResult in HexaDecimal form:");
  while(i>0)
  {
    putchar(array[--i]);
  }
}

main()
{
  int val = 26;
  dispAsHexNumber(val);
}
