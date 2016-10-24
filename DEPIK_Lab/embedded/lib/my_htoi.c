main()
{
  int val;
  char buf[] = {'1','A','\0'};
  val = htoi(buf);
  //puts((char *)&val);
  printf("val = %d",val);
}  





int htoi(char *buf)
{
  int sum = 0;
  while(*buf)
  {
    if((*buf-'0') < 10)
      sum = (sum * 16) + (*buf - '0');
    else if((*buf >= 'a') && (*buf <= 'f'))
      sum = (sum * 16) + (*buf-'a'+10);
    else if((*buf >= 'A') && (*buf <= 'F'))
      sum = (sum * 16) + (*buf-'A'+10);
    buf++;  
  }
  return sum;
}
