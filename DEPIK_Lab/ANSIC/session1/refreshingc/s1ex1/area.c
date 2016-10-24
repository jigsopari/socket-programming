/***** list of Header files *****/
#include <stdio.h>

/***** hash defines *****/
#define HALF  0.5
#define MYPRINT printf

/***** function declarations *****/
void printStartBanner(void);

int main(void)
{
	unsigned int base=0, height=0, area=0, radius=0, length=0 , width=0;

  while(1)
  {
    printStartBanner();
		MYPRINT("Enter the radius of the circle\n radius=");
		scanf("%d",&radius);

		area= HALF * radius * radius; /*Formula to calculate circle Radius*/
  	MYPRINT("Area of Circle:%d\n",area); 

		MYPRINT("Enter length and width of rectangle:\nlength=");
		scanf("%d",&length);
		MYPRINT("width=");
		scanf("%d",&width);

		area= length * width;/*Formula to calculate rectangle area*/
   	MYPRINT("Area of Rectangle:%d\n",area);

		MYPRINT("Enter base and height of triangle:\nbase =");
   	scanf("%d",&base);
		MYPRINT("height =");
   	scanf("%d",&height);

   	area= HALF * base * height; /*formula to calculate triangle area*/
   	MYPRINT("Area of Triangle=%d\n",area);
   
  };

return 0;
}


void printStartBanner(void)
{
	MYPRINT("This program is for computing area of Circle,Rectangle and Triangle\n");
}
