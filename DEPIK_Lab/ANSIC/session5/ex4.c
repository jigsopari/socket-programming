#include<stdio.h>
void main()
{
  char *chptr;
  short *shptr;  
   int *intptr;
   unsigned int x=0x12345678;
  chptr=(char *)&x;
  shptr=(short *)&x;
  intptr=&x;
  printf("chptr=%x\n",*chptr);
  printf("shptr=%x\n",*shptr);
  printf("intptr=%x\n",*intptr);
  printf("after adding chptr=%x\n",(*chptr+5));
  printf("after adding shptr=%x\n",(*shptr+5));
  printf("after adding intptr=%x\n",(*intptr+5));
}

