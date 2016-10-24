#include <stdio.h>
void countWordsInStrTD()
{
  int count;
  char pStr[80];
  printf("Enter String:\n");
  //getchar();
  __fpurge(stdin);
  fgets(pStr,80,stdin);
  count=countWordsInString(pStr);
  printf("No.of Words present in the given String=%d \n",count);
}  
  
  

int countWordsInString(char *pSr)
{
  int flag=0;
  int count;
  while(*pSr!='\n')
  {
    if(*pSr==' '||*pSr=='\n'||*pSr=='\t')
    {
      flag=0;
    }
    else if(flag==0)
    {
      flag=1;
      count++;
     }
    
     pSr++;
   
  }
  
  return(count-1);

}    
  
     
