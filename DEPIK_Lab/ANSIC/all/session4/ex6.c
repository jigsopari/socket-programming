void f1();
void f2();
void f3();
void f4();
void f5();
void (*funptr[5])()={f1,f2,f3,f4,f5};
void f1()
{
  printf("i am in function1\n");
}
void f2()
{
  printf("i am in function2\n");
}
void f3()
{
  printf("i am in function3\n");
}
void f4()
{
  printf("i am in function4\n");
}
void f5()
{
  printf("i am in function5\n");
}
main()
{
  int ch;
  while(1)
  {
    printf("1.function1\n");
    printf("2.function2\n");
    printf("3.function3\n");
    printf("4.function4\n");
    printf("5.function5\n");
    printf("6.exit\n");
    printf("\nEnter choice:");
    scanf("%d",&ch);

    switch(ch)
    {
      case 1:
          (*funptr[0])();
          break;
      case 2:
          (*funptr[1])();
          break;
      case 3:
          (*funptr[2])();
          break;
      case 4:
          (*funptr[3])();
          break;
      case 5:
          (*funptr[4])();
          break;
      case 6:
          exit(0);
    }
  }
}
