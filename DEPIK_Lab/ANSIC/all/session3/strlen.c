main()
{
  char source[]="durga";
  
  int len1;
  int len2;
  
  len1=xstrlen(source);
  len2=xstrlen("durgapathi");
  
  printf("%d %d \n",len1,len2);
}


int xstrlen(char *s)
{
  int length=0;
  while(*s!='\0')
  {
    length++;
    s++;
  }
return(length);
} 
