void function(char *p)
{
  int ival,ival1;
  unsigned char cval;
  float fval;
  unsigned short sval;
  memcpy(&ival,p,4);
  memcpy(&cval,p+4,1);
  memcpy(&fval,p+5,4);
  memcpy(&sval,p+9,2);
  memcpy(&ival1,p+11,4);
  printf("ival=%x \tcval=%x \tfval=%f \tsval=%x \tival1=%x \n",ival,cval,fval,     sval,ival1);
}  
  
main()
{
  int ival=0x12345678,i;
  char cval=0x9a;
  float fval=1234.5678;
  short sval=0xbcde;
  int ival1=0xf1234567;
  unsigned char message[15];
  unsigned char *ptr;
  ptr=(unsigned char *)&ival;
  message[0]=*ptr;
  message[1]=*(ptr+1);
  message[2]=*(ptr+2);
  message[3]=*(ptr+3);
  message[4]=cval;
  memcpy(&message[5],(unsigned char *)&fval,4);
  memcpy(&message[9],(unsigned char *)&sval,2);
  memcpy(&message[11],(unsigned char *)&ival1,4);
  function(message); 
  /**for(i=0;i<15;i++)
  {
    printf("%x\n",message[i]);
  }*********/


  


} 
