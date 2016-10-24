
int count;
main()
{
  char source[]="durga";

  count=countVowelsInStr(source);
  
  printf("no of vowels in the given string:%d \n",count);
}

int countVowelsInStr(char *s)
{ 
  while(*s!='\0')
  {  
                  if(*s=='a')
                  {
                    count++;
                  }
    else
    { 
                 if(*s=='e')
                 {
                   count++;
                 }
      else
      {
                 if(*s=='i')
                  {
                     count++;    
                   }
        else
        {
                 if(*s=='o')
                  { 
                     count++;
                   }
          else if(*s == 'u')
            {
              count++;
            } 
         }
       }
     }
     s++;
   }
  return(count);
 }   
    
  

