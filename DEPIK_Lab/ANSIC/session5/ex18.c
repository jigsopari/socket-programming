#include<stdio.h>
typedef struct bookInfo_s
{
  int bookId;
  char title[40];
  char author[20];
}bookInfo_t;
void getBookInfo(bookInfo_t *pBi)
{
  printf("Enter book Id:");	
  scanf("%d",&pBi->bookId);	
  printf("Enter title:");	
  scanf("%s",pBi->title);	
  printf("Enter book author:");	
  scanf("%s",pBi->author);
}  
void printBookInfo_t(bookInfo_t *pBi)
{
  printf("book id=%d\n",pBi->bookId);	
  printf("book title=%s\n",pBi->title);	
  printf("book author=%s\n",pBi->author);	
}
void main()
{
  int i;
  bookInfo_t *pBi[5];
  for(i=0;i<5;i++)
  {
  pBi[i]=(bookInfo_t *)malloc(sizeof(bookInfo_t));	
  getBookInfo(pBi[i]);
  }

  for(i=0;i<5;i++)
  {
  printBookInfo_t(pBi[i]);
  } 
}  
