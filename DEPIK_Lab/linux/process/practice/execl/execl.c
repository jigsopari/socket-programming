#include <stdio.h>
main()
{ 
  printf("I am going to exec an 'ls' program");
  execl("/bin/date","date",0);
  printf("I am executed 'ls' program");
}  
