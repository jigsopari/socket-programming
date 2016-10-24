#include <stdio.h>
int uig1;
int ig1=1;
int uig2;
int ig2=2;
int uig3;
int ig3=3;

void f1(int pa,int pb)
{
  int x,y;

printf("\nAddressess of all the local and parameter variables of f1\n");  
printf("\nAddressess of parameter variables of f1 pa:%x pb:%x \n",&pa,&pb);
printf("\nvalue of parameter variables of f1 pa:%x pb:%x \n",pa,pb);
printf("\nAddressess of local variables of f1 x:%x y:%x \n",&x,&y);
}
void f2()
{
  f1(1,2);
}

int main()
{
  int uila;
  int ila=10;
  static uis1;
  static is1=20;
printf("Addressess of function f1: %x,  f2: %x,  and main : %x  \n",f1,f2,main);
printf("Size of function f1: %x,  f2: %x,  and main : %x  \n",sizeof(f1),sizeof(f2),sizeof(main));
printf("Addressess of all local variables in main\n");
printf("uila: %x, ila : %x  uis1: %x, is1: %x \n",&uila,&ila,&uis1,&is1);
printf("Addressess of all global variables\n");
printf("uig1: %x, ig1 : %x \n",&uig1,&ig1);
printf("uig2: %x, ig2 : %x \n",&uig2,&ig2);
printf("uig3: %x, ig3 : %x \n",&uig3,&ig3);
printf("Addressess of dynamically allocated memory :%x\n",malloc(100));
f1(1,2);  
f2();  
f1(1,2);  
}

