#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
main()
{
  int ret;
  char file[20],string[10];
  struct stat buf;
  printf("Enter the file name:");
  scanf("%s",file);
  ret=stat(file,&buf);
  printf("ret=%d\n",ret);
  
  if((buf.st_mode & S_IFREG) == S_IFREG) {string[0] = '-';
  printf("Regular file\n");}
  else if((buf.st_mode & S_IFDIR) == S_IFDIR) {string[0] = 'd';
  printf("directory file\n");}
  //else if((buf.st_mode & S_IFBLK) == S_IFBLK) string[0] = 'd';
  else string[0]='-';
  if((buf.st_mode & S_IRUSR) == S_IRUSR) string[1] = 'r';
  else string[1]='-';
  if((buf.st_mode & S_IWUSR) == S_IWUSR) string[2] = 'w';
  else string[2]='-';
  if((buf.st_mode & S_IXUSR) == S_IXUSR) string[3] = 'x';
  else string[3]='-';
  if((buf.st_mode & S_IRGRP) == S_IRGRP) string[4] = 'r';
  else string[4]='-';
  if((buf.st_mode & S_IWGRP) == S_IWGRP) string[5] = 'w';
  else string[5]='-';
  if((buf.st_mode & S_IXGRP) == S_IXGRP) string[6] = 'x';
  else string[6]='-';
  if((buf.st_mode & S_IROTH) == S_IROTH) string[7] = 'r';
  else string[7]='-';
  if((buf.st_mode & S_IWOTH) == S_IWOTH) string[8] = 'w';
  else string[8]='-';
  if((buf.st_mode & S_IXOTH) == S_IXOTH) string[9] = 'x';
  else string[9]='-';
  printf("File permissions:%s\n",string);
  //else printf("Not a Regular File\n");
  printf("uid:%u\n",buf.st_uid);
  printf("gid:%u\n",buf.st_gid);
  printf("time of last access:%s\n",(char *)(ctime(&buf.st_ctime)));
printf("Time of last modification:%s\n",(char *)(ctime(&buf.st_mtime)));
}  

