#include <stdio.h>
void myStrCpy(char *pDst,char *pSrc);
void myStrCpyTD()
{
  char pSrcStr[80];
  char pDstStr[80];  
  printf("Enter String:\n");
  getchar();
  fgets(pSrcStr,80,stdin);
  myStrCpy(pDstStr,pSrcStr);
  printf("The Destination String=%s \n",pDstStr);
}  
void myStrCpy(char *pDst,char *pSrc)
{
  while(*pSrc!='\0')
  {
    *pDst=*pSrc;
    pSrc++;
    pDst++;
  }
  *pDst='\0';
}
     
