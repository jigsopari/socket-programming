#include <stdio.h> 
void myStrCat(char *pDst,char *pSrc);
void myStrCatTD();

main()
{
    char pSrcStr[80];
    char pDstStr[80];  
    printf("Enter String1:\n");
   // __fpurge(stdin);
   //fgets(pDstStr,80,stdin);
    gets(pDstStr);
    printf("Enter String2:\n");
   // __fpurge(stdin);
  // fgets(pSrcStr,80,stdin);
   gets(pSrcStr);
   // scanf("%s%s",pSrcStr, pDstStr);
//  sprintf(pSrcStr,"ravi kiran");
//scanf("%[^\n] s ",pSrcStr);
    myStrCat(pDstStr,pSrcStr);
    
    printf("concatenated String=%s \n",pDstStr);
}  
void myStrCat(char *pDst,char *pSrc)
{
   
  while(*pDst!='\0')
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

