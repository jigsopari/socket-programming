main()
{
  int ii;
  char name1[] ="durga";
  char name2[] ="durgapathi";
  ii = mystrncmp(name1,name2,5);
  printf("ii = %d\n",ii);
}  
  


int mystrncmp(char *s1, char *s2,int size)
{
  while((*s1 == *s2) && *s1 && *s2)
  {
      s1++;
      s2++;
      size--;
      if(size==1)
       break;
  } 
  return *s1 - *s2;
}
