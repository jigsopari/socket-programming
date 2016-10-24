#include <stdio.h>
#include <fcntl.h>
typedef struct 
{
  int Id;
  char name;
  int phNo;
}student_t;  
main()
{
  char buf[512];
  FILE *fp;
  student_t rec;
  fp=fopen("studentRecord","r");
  fread(buf,1,sizeof(rec),fp);
}  
