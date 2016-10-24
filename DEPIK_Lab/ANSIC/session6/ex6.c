#include<stdio.h>
typedef union sampUnion_s
{
  unsigned char carray[4];
  unsigned short shortvalue;
  unsigned char charvalue; 
  unsigned int intvalue3;
}sampUnion_t;

void main()
{
  sampUnion_t unval;
  printf("size of union variable=%d\n",sizeof(unval));
  printf("Address or variable=%u\n",&unval);
  printf("Address of field carray[4]=%u\n",unval.carray);
  printf("Address of field shortvalue=%u\n",&unval.shortvalue);
  printf("Address of field charvalue=%u\n",&unval.charvalue);
  printf("Address of field intvalue3=%u\n",&unval.intvalue3);
}

