void logical(int i,int j)
{
  int ch;
  unsigned int k;
  while(1)
  {
    printf("\n\n1.logical AND\n");
    printf("2.logical OR\n");   
    printf("3.logical NOT\n");  
    printf("4.exit\n");
    printf("Enter choice:");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:
          //logiAnd();
          k=i&&j;
          printf("\nlogical AND=%x ",k);
          break;  
      case 2:
          //logiOr();
          k=i||j;
          printf("\nlogical OR=%x ",k);
          break;
      case 3:
          k=!(i>j); 
          printf("\nlogical NOT of i>j =%x ",k);
          break;

      case 4:
          exit(0);
     }
  }
}         
void bit(int i,int j)
{
  int ch;
  unsigned int k;
  while(1)
  {
    printf("\n\n1.Bit wise AND\n");
    printf("2.Bit wise OR\n");   
    printf("3.Bit wise XOR\n");   
    printf("4.Bit wise NOT\n");  
    printf("5.exit\n");
    printf("Enter choice:");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:
          //bitAnd();
          k=i&j;
          printf("Bit wise AND=%x",k);
          break;  
      case 2:
          //bitOr();
          k=i|j;
          printf("Bit wise OR=%x",k);
          break;
      case 3:
          //bitXor();
          k=i^j;
          printf("Bit wise XOR=%x",k);
          break;
      case 4:
          //bitNot();
          k=~i;
          printf("Bit wise NOT of variable i=%x",k);
          break;

      case 5:
          exit(1);
     }
  }
}         
  
main()
{
  int ch;
  unsigned int i,j;
  printf("\nEnter the hex value of i:");
  scanf("%x",&i);
  printf("\nEnter the hex value of j:");
  scanf("%x",&j); 
  while(1)
  {
    printf("1.logical operations\n");
    printf("2.Bit operations\n");
    printf("3.exit\n");
    printf("Enter choice:");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:
          logical(i,j);
          break;
      case 2:   
          bit(i,j);
          break;  
      case 3:
          exit(1);
    }
  }
}       
