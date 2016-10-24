
/*************************** File: root.c *************************/

#define SIO_PORT_BASE 0x3f8
#define SIO_DATA_PORT SIO_PORT_BASE+0
#define DIV_LATCH_LOW SIO_PORT_BASE+0
#define DIV_LATCH_HIGH SIO_PORT_BASE+1
#define LCR SIO_PORT_BASE+3
#define SIO_STAT_PORT SIO_PORT_BASE+5

/*unsigned char mygetchar()
{
  unsigned char ch;
  while(! ( inb(SIO_STAT_PORT) & SIO_RXRDY_BIT))
  {
  }
  ch = inb(SIO_DATA_PORT);
  return ch;
}

void myputchar(unsigned char ch)
{
  while(!(inb(SIO_STAT_PORT) & SIO_TXEMPTY_BIT))
  {
  }
  outb(SIO_DATA_PORT,ch);
}  

void myputs(char *str)
{
  while(*str)
    myputchar(*str++);
}

  */
 
void *mymemset(char *cBuf, int c, int size)
{
  int ii;
  for(ii=0;ii<size;ii++)
  {
    cBuf[ii] = c;
  }
  return cBuf;
}  
   
void spkon()
{
 unsigned char ch;
  ch = inb(0x61);
  ch = ch | 0x03;
  outb(0x61,ch);
}  
void spkoff()
{
  unsigned char ch;
  ch = inb(0x61);
  ch = ch & 0xfc;
  outb(0x61,ch);
}



pianoMain()
{
  char ch;
  unsigned short divisor;
  int ii;
  while(1)
  {
    unsigned char num;
//    myputs("\n\rDurgaPiano> ");
    outb(0x378,0xaa);    

    while(1)
    {
      num = inb(0x379);
      switch(num)
      {
        case 0xff:
                  
	      spkon();
	      //outb(0x61,0x03);
	      divisor = 1930000/1000;
	      outb(0x43,0xb6);/*controlword Register*/
              outb(0x42,divisor&0xff);/*extracting lower one byte*/
              outb(0x42,(divisor>>8)&0xff);/*heigher Byte*/
	      outb(0x378,0x6a);/*Led Port*/

	     while(inb(0x379)==0xff);
	      {
	      }
	      spkoff();
  //             mymemset(&num,'\0', 1);
	      //outb(0x61,0x00);
//	      myputs("ff\n\r");
	      outb(0x378,0xaa);/*leds to default state*/
	      break;
	      
	 case 0x3f:
	       spkon();/*switch on the speaker*/
	       divisor = 1930000/2000;/*tune clock to req. frequency */
	       outb(0x43,0xb6);/*programming the controlword*/
               outb(0x42,divisor&0xff);/*extracting lower one byte*/
               outb(0x42,(divisor>>8)&0xff);/*Heigher Byte*/
	       outb(0x378,0x9a);/*glowing leds*/
	      //outb(0x61,0x03);
               while(inb(0x379)==0x3f);
	       {
	       }/*speaker is on till the button was pressed*/
	      //outb(0x61,0x00);
	      spkoff();
//              mymemset(&num,'\0', 1);
//	      myputs("3f\n\r");
	      outb(0x378,0xaa);/*Bringing the Leds to default state*/
	      break;
	 case 0x5f:
	       spkon();
	       divisor = 1930000/3000;/*chosing clk frequency*/
	       outb(0x43,0xb6);/*setting the controlword*/
               outb(0x42,divisor&0xff);/*extracting lower one byte*/
               outb(0x42,(divisor>>8)&0xff);/*heigher Byte*/
	       outb(0x378,0xa6);/*led glowing format*/
               //outb(0x61,0x03);
	       while(inb(0x379)==0x5f);
	       {
	       }/*speaker on time*/
	      //outb  (0x61,0x00);
	      spkoff();/*switch  off speaker*/
  //            mymemset(&num,'\0', 1);
//	      myputs("5f\n\r");
	      outb(0x378,0xaa);/*default state of leds*/
	      break;
	  case 0x6f:
	        spkon();
	        divisor = 1930000/5000;
	        outb(0x43,0xb6);
                outb(0x42,divisor&0xff);/*extracting lower one byte*/
                outb(0x42,(divisor>>8)&0xff);
	        outb(0x378,0xa9);
                //outb(0x61,0x03);
                while(inb(0x379)==0x6f);
	        {
	        }
	        //outb(0x61,0x00);
	        spkoff();
  //              mymemset(&num,'\0', 1);
//	      myputs("6f\n\r");
	        outb(0x378,0xaa);
	        break;
	  /*default:
	      outb(0x61,0x03);
	      divisor = 1930000/3000;
	      outb(0x43,0xb6);
              outb(0x42,divisor&0xff);//extracting lower one byte
              outb(0x42,(divisor>>8)&0xff);
	      break;*/

	 
	
      }
    }
  }
}   

