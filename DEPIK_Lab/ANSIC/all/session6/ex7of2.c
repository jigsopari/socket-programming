typedef union sampUnion_s
{
  unsigned char carray[4];
  unsigned short shortvalue;
  unsigned char charvalue; 
  unsigned int intvalue3;
}sampUnion_t;

main()
{
  sampUnion_t unval;
  unval.carray[0]=12;
  unval.carray[1]=34;
  unval.carray[2]=56;
  unval.carray[3]=78;

  //  printf("size of union variable=%d\n",sizeof(unval));
  //printf("Address or variable=%u\n",&unval);
  //printf("value of field carray[4]=%x\n",unval.carray);
  printf("value of field intvalue3=%d\n",unval.intvalue3);
  printf("value of field shortvalue=%d\n",unval.shortvalue);
  printf("value of field charvalue=%d\n",unval.charvalue);

}

