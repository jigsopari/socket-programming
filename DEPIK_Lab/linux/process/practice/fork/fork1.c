main()
{
  int id;
 printf("I am going to emerge new process & my pid is:%d\n",getpid(  ));
 id=fork();
  if(id==0)
  printf("i am in child process and my pid is:%d\n",id);
  else
  printf("i am in parent process and my child pid is:%d\n",id);
  
  //printf("i am ppid=%d i am pid=%d\n",getppid(),getpid());
}  
