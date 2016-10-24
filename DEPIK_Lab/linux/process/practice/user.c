#include <pwd.h>
main()
{
  struct passwd *pass;
  int uid;
  uid=getuid();
  pass=getpwuid(uid);
  printf("login name:%s\n",pass->pw_name);
  printf("encrypted password:%d\n",pass->pw_passwd);
  printf("user uid:%d\n",pass->pw_uid);
}  
