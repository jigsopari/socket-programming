void function1()
{
  printf("i am in function1\n");
}
void function2(void (*ptr)())
{
  printf("i am in function2\n");
  printf("i am calling function1\n");
   (*ptr)();
//  function1();
}
main()
{
  //void (*ptr)();
  //ptr=function2;
  printf("i am in main\n");
  printf("i am calling function 2\n");
  function2(function1);
}  
