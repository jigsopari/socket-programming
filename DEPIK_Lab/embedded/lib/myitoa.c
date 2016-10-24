void itoa(int val)
{
  int ii =0;
  char array[3];
  while(val)
  {
    array[ii] = (val % 10) + '0';
    val = val/10;
    ii++;
  }
  while(ii>0)
  putchar(array[--ii]);
}  

main()
{
  int val = 97;
  itoa(val);
 }
 
