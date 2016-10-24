#include <stdio.h>
void  dispGivenAsciiChars(char start,char end)
{
  int i;
  for(i=start;i<=end;i++)
  {
    putchar(i);
  }
}
/*void dispAllPrintablechars()
{
  int i,k=1;
  for(i=32;i<=126;i++)
  {
    if(k%16==0)

    putchar('\n');
    putchar(i);  
    k++;
  }
}*/
main()
{
  char start,end;

  //dispAllPrintablechars();

  printf("Enter starting char:");
  __fpurge(stdin);
  scanf("%c",&start);
  printf("Enter end char:");
  __fpurge(stdin);
  scanf("%c",&end);

  dispGivenAsciiChars(start,end);
}

