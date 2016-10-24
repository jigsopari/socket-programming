#include<stdio.h>
typedef struct sampStruc
{
  unsigned int intvalue1;
  unsigned short shvalue;
  unsigned int intvalue2;
  unsigned char chvalue;
  unsigned int intvalue3;
}sampStruc_t;
void main()
{
  int i;
  sampStruc_t strcval;
  strcval.intvalue1=0x1234;
  strcval.shvalue=0x56;
  strcval.intvalue2=0x789a;
  strcval.chvalue=0xbc;
  strcval.intvalue3=0xfedcba98;
  unsigned char *ptr;
  ptr=(unsigned char *)&strcval;
  for(i=0;i<20;i++)
  {
    printf("%x ",*(ptr+i));
  }
}



