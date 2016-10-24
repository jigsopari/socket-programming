main()
{
  int *pi,a,i;
  short *ps;
  unsigned char *pc;
 //  printf("area=%d\n",area);

  //int a=0x88888888;
  pi=&a;
  ps=(short *)&a;
  pc=(unsigned char *)&a;
  //printf("%x\n",*pi);
  //printf("%x\n",*ps);
  //printf("%x\n",*pc);
  //printf("%x\n",a);
  *pi=0x90abcdef;
  printf("%x \n",*pi);
  *ps=0x1234;
  printf("%x \n",*ps);
  *pc=0x56;
 for(i=0;i<4;i++)
 { 
  printf("%x \n",pc[i]);
 }
  printf("%x \n",*pi);

}
