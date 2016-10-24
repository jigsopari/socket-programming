#include <stdio.h>
#include "hash.h"
main()
{
  int ch,ret;
  char key[20];
  hashItem_t *p;
  while(1)
  {
     printf("\n1.add Element to hash list");
     printf("\n2.search Element in hash list");
     printf("\n3.Exit");
     printf("\nEnter choice:");
     scanf("%d",&ch);
     switch(ch)
     {
        case 1:
             p=(hashItem_t *)malloc(sizeof(hashItem_t));
             ret=addToHashList(p);
             printf("\n%d\n",ret);
             break;
        case 2:
              printf("Enter the name:");
              scanf("%s",key);
             searchHashList(key);    
             break;
        case 3:
             exit(1);
    }
  }
}       


