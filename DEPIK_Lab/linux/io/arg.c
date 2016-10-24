#include <stdio.h>
main(int argc,char *argv[])
{ 
   int i;
   printf("%d",argc);
   for(i=0;argv[i]!=NULL;i++)
   {
      printf("argd[%d]: %s\n",i,argv[i]);
   }
}   
