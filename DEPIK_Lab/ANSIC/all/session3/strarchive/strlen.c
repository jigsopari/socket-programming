#include <stdio.h>
void myStrLenTD()
{ 
  int length;
  char pStr[80];
  printf("Enter String:\n");
  getchar();
  fgets(pStr,80,stdin);
  length=myStrLen(pStr);
  printf("Length of the given String=%d \n",length);
}
  
  

int myStrLen(char *s)
{
  int length=0;
  while(*s!='\0')
  {
    length++;
    s++;
  }
  return(length-1);
}
