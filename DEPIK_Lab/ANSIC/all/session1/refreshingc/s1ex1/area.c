#include <stdio.h>
main()
{
  int base,height,area;
  int radius;
  int length,width;
  printf("Enter radius:");
    scanf("%d",&radius);
    area=0.5*radius*radius;
    printf("Area of Circle:%d\n",area); 
  printf("Enter length and width:");
    scanf("%d%d",&length,&width);
    area=length*width;
    printf("Area of Rectangle:%d\n",area);
  printf("Enter base and height:");
    scanf("%d%d",&base,&height);
    area=0.5*base*height;
    printf("Area of Triangle=%d\n",area);
}
