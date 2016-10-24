/* Header files */
#include<stdio.h>

/*Hash defines*/
#define PI	3.142

int main(void)
{
	unsigned int radius = 0,area = 0;

	printf("Enter radius of the circle:");
	scanf("%d",&radius);

	area = PI * radius * radius;

	printf("Area of Circle=%d\n",area);

  return 0;
}
