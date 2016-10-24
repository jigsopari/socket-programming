#include <stdio.h>
#include<string.h> 
void myStrCat(char *pDst,char *pSrc);
void myStrCpy(char *pDst,char *pSrc);
int  myStrLen(char *pDst);
void countWordsInStrTD();
void countVowelsInStrTD();
void myStrCatTD();
void myStrCpyTD();
void myStrLenTD();

main()
{
  int choice;
  while(1)
  {
    printf("1.String length\n");
    printf("2.String copy\n");
    printf("3.String concatenation\n");
    printf("4.Vowels in a String\n");
    printf("5.Words in a String\n");
    printf("6.Exit\n");
    printf("Enter choice:\n");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:
         myStrLenTD();
          break;
      case 2:
         myStrCpyTD();
         break;
      case 3:
         myStrCatTD();
         break; 
      case 4:
         countVowelsInStrTD();
         break; 
      case 5:
         countWordsInStrTD();
         break;
      case 6:
         exit(0);   
    }
  }

}
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
void myStrCatTD()
{
  char pSrcStr[80];
  char pDstStr[80];  
  printf("Enter String1:\n");
  //gets(pDstStr);
  //__fpurge(stdin); 
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
  
     
