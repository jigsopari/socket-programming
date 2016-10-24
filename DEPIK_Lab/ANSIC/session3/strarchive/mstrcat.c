#include <stdio.h>
void myStrCat(char *pDst,char *pSrc);
void myStrCatTD()
{
  char pSrcStr[80];
  char pDstStr[80];  
  printf("Enter String1:\n");
  //gets(pDstStr);
  __fpurge(stdin); 
  fgets(pDstStr,80,stdin);
  //sprintf(pSrcStr,"ravi kiran");
  //scanf("%[^\n] s ",pDstStr);
  printf("Enter String2:\n");
  //gets(pSrcStr);
  __fpurge(stdin);
  fgets(pSrcStr,80,stdin);
  myStrCat(pDstStr,pSrcStr);
  printf("The Concatenated String=%s \n",pDstStr);
}  
void myStrCat(char *pDst,char *pSrc)
{
  
  while(*pDst!='\n')
  {
   pDst++;
  }
  while(*pSrc!='\0')
  {
    *pDst=*pSrc;
    pSrc++;
    pDst++;
  }
  *pDst='\0';
}

     
