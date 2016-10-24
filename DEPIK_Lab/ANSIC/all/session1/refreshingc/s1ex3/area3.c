  void areaOfCircleTstDrv()
    {
       int radius,area;
       printf("Enter radius:");
       scanf("%d",&radius);
       area=areaOfCircle(radius);
       printf("Area of Circle=%d sq.units\n",area);
    }
    


int areaOfCircle(int radius)
{
  int area;
  area=3.14*radius*radius;
  return(area);
}

