main()
{
  
  char source[]="floks";
  char target[30]="hello";

  xstrcat(target,source);

  printf("\nsource=%s",source);
  printf("\ntarget=%s\n",target);
}

xstrcat(char *t,char *s)
{
  int len;
  len=xstrlen(t);
  xstrcpy(t+len,s);
}



xstrlen(char *s)
{
  int length=0;
  while(*s!='\0')
  {
    length=length+1;
    s++;
  }
return(length);
}
   


