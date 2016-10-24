
#include <stdio.h>
int count;
int flag=0;
main()
{
  //char source[]="durga pathi shiva";
  char source[80];
  
  printf("enter string\n");
  fgets(source,80,stdin);
  count=wordsInStr(source);
  
  printf("no.of words in the given string:%d \n",count);
printf("prg completed\n");
}

int wordsInStr(char *s)
{
  while(*s!='\0')
  {
    if(*s == ' '|| *s == '\n'||*s=='\t')
    {
      flag = 0;
    }
    else if(flag == 0)
    {
      flag = 1;
      count++;
    }
    s++;
      
  }
 return count;
} 
  
