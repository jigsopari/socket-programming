typedef struct sampStruc
{
  unsigned int intvalue1;
  unsigned short shvalue;
  unsigned int intvalue2;
  unsigned char chvalue;
  unsigned int intvalue3;
}sampStruc_t;

getStruct(sampStruc_t *strcptr)
{
  //strcptr=(sampStruc_t *)malloc(sizeof(sampStruc_t));
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
}
DispStructWithPtr(sampStruc_t *strcptr)
{
  printf("intvalue1=%x\n",strcptr->intvalue1);
  printf("shvalue=%x\n",strcptr->shvalue);
  printf("intvalue2=%x\n",strcptr->intvalue2);
  printf("chvalue=%x\n",strcptr->chvalue);
  printf("intvalue3=%x\n",strcptr->intvalue3);
}
DispStruct(sampStruc_t strcptr)
{
  printf("intvalue1=%x\n",strcptr.intvalue1);
  printf("shvalue=%x\n",strcptr.shvalue);
  printf("intvalue2=%x\n",strcptr.intvalue2);
  printf("chvalue=%x\n",strcptr.chvalue);
  printf("intvalue3=%x\n",strcptr.intvalue3);
}
main()
{
  sampStruc_t st;

  getStruct(&st);
  DispStruct(st);
  DispStructWithPtr(&st);
  
}



