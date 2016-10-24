/*int mystrcmp(char *s1, char *s2)
{
  while((*s1 == *s2) && *s1 && *s2)
  {
      s1++;
      s2++;
  } 
  return *s1 - *s2;
}*/
int mystrcmp(char *s1, char *s2)
{
  while(*s2)
  {
    if(*s1 != *s2)
    {
      return (*s1-*s2);
    }  
      s1++;
      s2++;
  } 
  return 0;
}



main()
{
  int ret;
  char buf1[10], buf2[10];
  scanf("%s",buf1);
  scanf("%s",buf2);
  ret=mystrcmp(buf1,buf2);
  printf("ret:%d",ret);
}  
