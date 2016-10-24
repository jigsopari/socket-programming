void dispDecimalInteger(int val);
void reverse(char *str);
void swap(char *stptr,char *enptr);
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
  reverse(array);
  /*while(i>0)
  {
    putchar(array[--i]);
  }*/
  for(i=0;array[i]!='\0';i++)
  putchar(array[i]);
}
   
void reverse(char *str)
{
  int len;
  char temp;
  char *stptr, *enptr;
  len=strlen(str);
  stptr=str;
  enptr=&str[len-1];
  while(1)
  {
   swap(stptr,enptr);
   stptr++;
   enptr--;
   if(stptr>enptr)
     break;
  }
}
   
void swap(char *stptr,char *enptr)
{
char temp;
temp=*enptr;
*enptr=*stptr;
*stptr=temp;
}  
