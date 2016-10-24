typedef struct sampStruc
{
  unsigned int intvalue1;
  unsigned short shvalue;
  unsigned int intvalue2;
  unsigned char chvalue;
  unsigned int intvalue3;
}sampStruc_t;

printfield(sampStruc_t *strcptr)
{
  printf("intvalue1=%x\n",strcptr->intvalue1);
  printf("shvalue=%x\n",strcptr->shvalue);
  printf("intvalue2=%x\n",strcptr->intvalue2);
  printf("chvalue=%x\n",strcptr->chvalue);
  printf("intvalue3=%x\n",strcptr->intvalue3);
}

main()
{
  int i;
  sampStruc_t strcval;
  strcval.intvalue1=0x1234;
  strcval.shvalue=0x56;
  strcval.intvalue2=0x789a;
  strcval.chvalue=0xbc;
  strcval.intvalue3=0xfedcba98;
  printfield(&strcval);
  //unsigned char *ptr;
/*  printf("\n intvalue1=%x ",strcval.intvalue1);
  printf("\n shvalue=%x",strcval.shvalue);
  printf("\n intvalue2=%x",strcval.intvalue2);
  printf("\n chvalue=%x",strcval.chvalue);
  printf("\n intvalue3=%x",strcval.intvalue3);*/
  //ptr=(unsigned char *)&strcval;
/*  for(i=0;i<20;i++)
  {
    printf("%x ",*(ptr+i));
  }*/
}



