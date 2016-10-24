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
  sampStruc_t *strcptr;
  strcptr=(sampStruc_t *)malloc(sizeof(sampStruc_t));
  printf("\nEnter intvalue1=");
  scanf("%x",&strcptr->intvalue1);
  printf("\nEnter shvalue=");
  scanf("%x",&strcptr->shvalue);
  printf("\nEnter intvalue2=");
  scanf("%x",&strcptr->intvalue2);
  printf("\nEnter intvalue3=");
  scanf("%x",&strcptr->intvalue3);
  printf("\nEnter chvalue=");
  scanf("%x",&strcptr->chvalue);
  printfield(strcptr);
  /*  strcval.intvalue1=0x1234;
  strcval.shvalue=0x56;
  strcval.intvalue2=0x789a;
  strcval.chvalue=0xbc;
  strcval.intvalue3=0xfedcba98;
  printfield(&strcval);*/
}



