#include <stdio.h>
void countVowelsInStrTD()
{
  int count;
  char pStr[80];
  printf("Enter String:\n");
  getchar();
  fgets(pStr,80,stdin);
  count=countVowelsInString(pStr);
  printf("No.of Vowels present in the given String=%d \n",count);
}

int countVowelsInString(char *pS)
{
  int count=0,i;
  char vowels[]="aeiouAEIOU";
  while(*pS!='\0')
  {
    for(i=0;i<=9;i++)
    {
      if(*pS==vowels[i])
      {
        count++;
      }
    } 
    pS++;
  }
  return(count);
}

     
