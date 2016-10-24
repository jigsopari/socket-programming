
int count;
main()
{
  char source[]="ramanareddy";

count=countVowelsInStr(source);
  
  printf("no of vowels in the given string:%d \n",count);
}

int countVowelsInStr(char *s)
{ 
  int i;
  char vowels[]="aeiouAEIOU";
  while(*s!='\0')
  {
    for(i=0;i<=9;i++)
    {
      if(*s==vowels[i])
      {
        count++;
      }
    }
  s++;
  }
return(count);
}

