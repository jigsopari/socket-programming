   void areaOfTriangleTstDrv()
    {
       

	:int base,height,area;
       printf("Enter base and height:");
       scanf("%d%d",&base,&height);
       area=areaOfTriangle(base,height);
       printf("Area of Triangle=%d sq units\n",area);
    }


int areaOfTriangle(int base,int height)
{
  int area;
  //printf("Hello\n");
  area=0.5*base*height;
  return(area); 
}


