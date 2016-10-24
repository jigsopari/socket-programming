#include <stdio.h>

main(int argc,char *argv[])
{
  int bytes;
  //char source[512];	
  int i=0,j=0;
  char k;	
  FILE *fp;
  char buf[16];
 // printf("\nEnter file name:");
  
  //fgets(source,512,stdin);
  fp=fopen(argv[1],"w+");
  for(k=30;k<70;k++)
  {	  
     fwrite(&k,1,1,fp);
  }
  fseek(fp,0,0);
  while(fgets(buf,17,fp)>0)
  { 
    bytes = strlen(buf);
    //printf("by:%d\n",bytes);
    for(i=0;i<bytes;i++)
    {
       printf("%02x ",buf[i]);
    }   
    printf("\t");
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
       //i++;
      // if(j % 16 == 0)
        // printf("\n");
      // j++;
  }
  
    
} 
