
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
