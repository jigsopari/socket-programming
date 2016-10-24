#include <stdio.h>
main()
{
   int *ptr,i;
   char ch;
  ptr=(int *)malloc(sizeof(int)*10);

  FILE *ft;
  FILE *fb;

  ft=fopen("textfile","r");
  if(ft==NULL)
  {
    puts("can not open the text file");
    exit(1);
  }
  
  printf("\ntext file output:");  
  for(i=0;i<=9;i++)
  {
    fscanf(ft,"%d ",ptr+i);
    printf("%d ",*(ptr+i));
  }

  fb=fopen("binfile","rb");
  if(fb==NULL)
  {
    puts("can not open the binary file");
    exit(1);
  }
    fread(ptr,4,10,fb);
    printf("\nbinary file output:");
    for(i=0;i<=9;i++)
       printf("%d ",*(ptr+i));
    
  fclose(ft);
  fclose(fb);
}
