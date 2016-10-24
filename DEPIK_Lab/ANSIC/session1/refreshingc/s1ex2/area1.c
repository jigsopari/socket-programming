main() 
{
  int length,width;
  int base,height;
  int radius;
  int area,i;
  printf("Enter value of i:");
  scanf("%d",&i);
  switch (i)
    {
     case 1:
          printf("Enter length and width:");
          scanf("%d%d",&length,&width);  
          area= areaOfRectangle(length,width);
          printf("Area of Rectangle:%d\n",area);
          break;     
     case 2:
          printf("Enter base and height:");
          scanf("%d%d",&base,&height);  
          area=areaOfTriangle( base, height);
          printf("Area of Triangle:%d\n",area); 
          break;     
    case 3:
          printf("Enter radius:");
          scanf("%d",&radius);  
          area=areaOfCircle( radius);
          printf("Area of Circle:%d\n",area); 
          break;     
    case 4:
         printf("exit\n");        
  }
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
