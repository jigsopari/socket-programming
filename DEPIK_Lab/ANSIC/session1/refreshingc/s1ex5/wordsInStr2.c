
#include <stdio.h>
#define IN 1
#define OUT 0
main()
{
  int nw,state;
  char c;
  nw=0;
  state=OUT;
  while((c=getchar())!='\n')
  {
    
    if(c==' '||c=='\n'||c=='\t')
    {
      state=OUT;
    }

    else if(state==OUT)
    {
      state=IN;
      ++nw;
    }
  }
  printf("no.of words in the given string:%d \n",nw);
}

  
