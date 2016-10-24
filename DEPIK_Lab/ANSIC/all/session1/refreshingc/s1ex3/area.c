
    void areaOfRectangleTstDrv();
    void areaOfTriangleTstDrv();
    void areaOfCircleTstDrv();

main()
{
  int choice;
  while(1)
   {
     printf("\n1.Area of Rectangle");
     printf("\n2.Area of Triangle");
     printf("\n3.Area of Circle");
     printf("\n4.exit");
     printf("\nEnter choice:");
     scanf("%d",&choice);
     if(choice==1)
      {
          areaOfRectangleTstDrv();
      }
    else
      {
        if(choice==2)
         {
            areaOfTriangleTstDrv();
         }
       else
        {
          if(choice==3)
           {
             areaOfCircleTstDrv();
           }
          else
           {
             exit(1);
           }         
         }
      }
    }
 }
    void areaOfRectangleTstDrv()
     {
       int length,width,area;
       printf("Enter length and width:");
       scanf("%d%d",&length,&width);
       area=areaOfRectangle(length,width);
       printf("Area of Rectangle=%d sq units\n",area);
     }   
   void areaOfTriangleTstDrv()
    {
       int base,height,area;
       printf("Enter base and height:");
       scanf("%d%d",&base,&height);
       area=areaOfTriangle(base,height);
       printf("Area of Triangle=%d sq units\n",area);
    }
  void areaOfCircleTstDrv()
    {
       int radius,area;
       printf("Enter radius:");
       scanf("%d",&radius);
       area=areaOfCircle(radius);
       printf("Area of Circle=%d sq.units\n",area);
    }
    
int areaOfRectangle(int length,int width)
{
  int area;
  area=length*width;
  return(area);
}

int areaOfTriangle(int base,int height)
{
  int area;
  area=0.5*base*height;
  return(area); 
}

int areaOfCircle(int radius)
{
  int area;
  area=3.14*radius*radius;
  return(area);
}

