typedef struct sampStruc
{
  unsigned int intvalue1;
  unsigned short shvalue;
  unsigned char chvalue;
  unsigned int intvalue2;
  unsigned int intvalue3;
}sampStruc_t;
main()
{
  sampStruc_t strcval;
  sampStruc_t *strptr;
  printf("\nsize of structure variable=%d",sizeof(strcval));
  printf("\nsize of structure variable=%d",sizeof(sampStruc_t));
  printf("\nsize of structure variable=%d",sizeof(*strptr));
  printf("\nAddress of structure variable=%u",&strcval);
  printf("\nAddress of structure field intvalue1=%u ",&strcval.intvalue1);
  printf("\nAddress of structure field shvalue=%u",&strcval.shvalue);
  printf("\nAddress of structure field intvalue2=%u",&strcval.intvalue2);
  printf("\nAddress of structure field chvalue=%x",&strcval.chvalue);
  printf("\nAddress of structure field intvalue3=%x",&strcval.intvalue3);
}
  
