int dispBytes(unsigned char *pB,int count)
{ 
  int i,n=1;
  printf("bytes\n"); 
  for(i=0;i<count;i++)
  {
    printf("%02x ",*(pB+i)); 
    if(n%16==0)
    {
      printf("\n");
    }
    n++;
  }
}      
int dispWords(unsigned short *pW,int count)
{ 
  int i,n=1;
  printf("words\n"); 
  for(i=0;i<count;i++)
  {
    printf("%04x ",*(pW+i)); 
    if(n%8==0)
    {
      printf("\n");
    }
    n++;
  }
}      
int dispLongs(unsigned int *pL,int count)
{ 
  int i,n=1;
  printf("words\n"); 
  for(i=0;i<count;i++)
  {
    printf("%08x ",*(pL+i)); 
    if(n%4==0)
    {
      printf("\n");
    }
    n++;
  }
}
main()
{
  int i;
  char arr[128];
  for(i=0;i<=127;i++)
  {
      arr[i]=i;
  }
  dispBytes(arr,128);
  dispWords((unsigned short *)arr,64);
  dispLongs((unsigned int *)arr,32);
}
  
