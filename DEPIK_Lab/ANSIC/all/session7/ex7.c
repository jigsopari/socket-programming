#include <stdio.h>
main()
{
  int *ptr,i;
  ptr=(int *)malloc(sizeof(int)*10);

  FILE *ft;
  FILE *fb;

  ft=fopen("textfile","w");
  if(ft==NULL)
  {
    puts("can not open the text file");
    exit(1);
  }
  
  for(i=0;i<=9;i++)
  {
    printf("Enter integer%d =",i);
    scanf("%d",&ptr[i]);
    fprintf(ft,"%d ",ptr[i]);
  }

  fb=fopen("binfile","wb");
  if(fb==NULL)
  {
    puts("can not open the text file");
    exit(1);
  }
    fwrite(ptr,4,10,fb);

  fclose(ft);
  fclose(fb);
}
