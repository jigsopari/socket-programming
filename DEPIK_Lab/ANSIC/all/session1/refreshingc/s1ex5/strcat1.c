main()
{
  int len;
  char source[]="floks";
  char target[30]="hello";
  
  xstrcat(target,source);
  printf("after concatenation........: %s\n",target);

}
xstrcat(char *t,char *s)
{
  int len;
  len=strlen(t);
  strcpy(t+len,s);
}


