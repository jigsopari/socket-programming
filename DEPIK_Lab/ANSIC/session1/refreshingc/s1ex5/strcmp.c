main()
{
  char string1[]="ferry";
  char string2[]="jerry";
  int i,j,k;

  i=xstrcmp(string1,string2);
  j=xstrcmp(string1,"ferry");
  k=xstrcmp(string1,"ferry boy");
  
  printf("%d%d%d",i,j,k);
}

xstrcmp(char *s1,char *s2)
{ 
int i=0;
  while(*s2)
  {
    if(*s1!=*s2)
     {
       i=1;
       break;
     }
       s1++;
        s2++; 
   }
if(i=1)
return(*s1-*s2);
else
return(0);    
}   
   
   
     
       
         
    
  
 
         
