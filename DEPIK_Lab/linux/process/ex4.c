#include <sys/types.h>
#include <unistd.h>
main(int argc,char *argv[])
{
  //pid_t pid;
  printf("i am in main");
  execl("/bin/cp","cp",argv[1],argv[2],0);
}  
