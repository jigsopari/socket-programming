#include <stdio.h>

main(int argc,char *argv[])
{
  int bytes;
  int i=0,j=1;
  char k;	
  FILE *fp;
  unsigned char buf[16];
  
  fp=fopen(argv[1],"r");
			  /*for(k=30;k<70;k++)
			  {	  
     fwrite(&k,1,1,fp);
  }*/
  fseek(fp,0,0);
  while(fread(buf,1,1,fp)>0)
  { 
    //bytes = strlen(buf);
    //printf("by:%d\n",bytes);
    //for(i=0;i<bytes;i++)
    //{
       printf("%02x ",buf[i]);
    //}   
  /*  printf("\t");
    if(bytes <16)
    {
    printf("\t");
    printf("\t");
    printf("\t");
    }
    for(j=0;j<bytes;j++)
    {
      if(buf[j]<32)
      {
        printf(".");
      }
      else
        printf("%c",buf[j]);
    }  
    printf("\n");
    //__fpurge(buf);
    continue;
       //i++;*/
       if(j % 16 == 0)
         printf("\n");
         j++;
  }
  
    
} 
