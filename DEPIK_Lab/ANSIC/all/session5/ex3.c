main()
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
}

