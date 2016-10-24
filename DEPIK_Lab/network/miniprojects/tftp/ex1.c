#include <stdio.h>
int srcmp( char *str1, char *str2);
int i;
main()
{
  //int i;
  char str1[20] = "sridharkumar";
  char str2[20] = "sridhar";
  i = srcmp(str1, str2);
  if (i == 1)
  printf(" not equal");
  else 
  printf("Equal");
}

int srcmp(char *str1, char *str2)
{
    while(str1[i] || str2[i])
    {
      if(str1[i] != str2[i])
       return 1;
          i++;
     }
        return 0;  
}
