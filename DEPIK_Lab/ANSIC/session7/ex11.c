#include <string.h>
#include <stdio.h>

void  swap(char *stptr,char *enptr)
{
  char temp;
  temp=*enptr;
  *enptr=*stptr;
  *stptr=temp;
}  
extern void reverse(char *str)
{
  int len;
  char array[80],*stptr,*enptr;
  printf("\nEnter string:");
  scanf("%s",array);
  printf("\nBefore reversing string:%s",array);
  len=strlen(array);
  printf("len=%d",len);
  stptr=array;
  enptr=&array[len-1];
  
  while(1)
  {
    if(stptr>enptr)
      break;

    swap(stptr,enptr);
    stptr++;
    enptr--;
  }
  printf("\nAfter reversing string:%s\n",array);
}
main()
{
 char *str;
 reverse(str);
}  
