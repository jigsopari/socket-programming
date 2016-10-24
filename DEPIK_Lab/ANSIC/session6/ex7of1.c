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
  unval.carray[0]=0x12;
  unval.carray[1]=0x34;
  unval.carray[2]=0x56;
  unval.carray[3]=0x78;

    printf("size of union variable=%d\n",sizeof(unval));
  printf("Address or variable=%u\n",&unval);
  printf("value of field carray[4]=%x\n",unval.carray);
  printf("value of field intvalue3=%x\n",unval.intvalue3);
  printf("value of field shortvalue=%x\n",unval.shortvalue);
  printf("value of field charvalue=%x\n",unval.charvalue);

}

