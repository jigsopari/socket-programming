#include<stdio.h>
void main()
{
  int ival=0x12345678,i;
  char cval=0x9a;
  float fval=1234.5678;
  short sval=0xbcde;
  int ival1=0xf1234567;
  unsigned char message[15];
  char *ptr;
  ptr=(char *)&ival;
  message[0]=*ptr;
  message[1]=*(ptr+1);
  message[2]=*(ptr+2);
  message[3]=*(ptr+3);
  message[4]=cval;

  ptr=(char *)&fval;
  message[5]=*ptr;
  message[6]=*(ptr+1);
  message[7]=*(ptr+2);
  message[8]=*(ptr+3);
  ptr=(char *)&sval;
  message[9]=*ptr;
  message[10]=*(ptr+1);
  ptr=(char *)&ival1;
  message[11]=*ptr;
  message[12]=*(ptr+1);
  message[13]=*(ptr+2);
  message[14]=*(ptr+3);

  /*memcpy(&message[5],(unsigned char *)&fval,4);
 * memcpy(&message[9],(unsigned char *)&sval,2);
  *memcpy(&message[11],(unsigned char *)&ival1,4);*/
  
 *ptr=(char *)&ival;
  *(ptr+4)=(char *)&cval;
  *(ptr+8)=(char *)fval;
  *(ptr+12)=(char *)&sval;
  *(ptr+16)=(char *)&ival1;
  for(i=0;i<15;i++)
  {
    printf("%x\n",message[i]);
  
}


} 
