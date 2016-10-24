    void areaOfRectangleTstDrv()
     {
       int length,width,area;
       printf("Enter length and width:");
       scanf("%d%d",&length,&width);
       area=areaOfRectangle(length,width);
       printf("Area of Rectangle=%d sq units\n",area);
     }   
    
int areaOfRectangle(int length,int width)
{
  int area;

  area=length*width;
  return(area);
}


