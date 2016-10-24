#include <stdio.h>
#include<string.h> 
#include "mystr.h" 

main()
{
  int choice;
  while(1)
  {
    printf("1.String length\n");
    printf("2.String copy\n");
    printf("3.String concatenation\n");
    printf("4.Vowels in a String\n");
    printf("5.Words in a String\n");
    printf("6.Exit\n");
    printf("Enter choice:\n");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:
         myStrLenTD();
          break;
      case 2:
         myStrCpyTD();
         break;
      case 3:
         myStrCatTD();
         break; 
      case 4:
         countVowelsInStrTD();
         break; 
      case 5:
         countWordsInStrTD();
         break;
      case 6:
         exit(0);   
    }
  }

}
     
