#include<stdio.h>

void main()
{
  unsigned int uival;
  int ch;

  printf("Enter a 32 bit number:");
  scanf("%x",&uival);

  printf("Enter a bit number that you require:");
  scanf("%d",&ch);

  uival = uival >> ch;
  uival = uival & 1;

  printf("uival=%d\n",uival);
} 
