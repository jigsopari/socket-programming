#define NUM_OF_STUDENTS 16
void printArray(int *marks,int size);
void fillArray(int marks[],int size);
main()
{ 
   // int *ptr;
  int choice;
  int average;
  int min,max,count; 
  int marks[NUM_OF_STUDENTS]={70,65,89,45,32,58,91,83,28,59,66,60,45,38,78,68};
  while(1)
  {
    printf("1.Average of all Marks present in array\n");
    printf("2.Minimum mark of an array\n");
    printf("3.Maximum mark of an array\n");
    printf("4.No.of Students Passed\n");
    printf("5.No.of Students who got second class\n");
    printf("6.No.of Students who failed,passed with ordinary,passed with second     class and passed with first class\n");
    printf("7.No.of Students who got above Average Marks present in array\n");
    printf("8.all Marks present in array\n");
    printf("9.Fills the marks array by taking input from user \n");
    printf("10.exit\n");
    printf("Enter Choice:");
    scanf("%d",&choice);
  
    switch(choice)
    {
      case 1:
           average=avgMark(&marks[0],16);
           printf("average=%d \n",average);
           break;
      case 2:
           min=minMark(&marks[0],16);    
           printf("Minimum mark of an array=%d \n",min);
           break; 
      case 3:
           max=maxMark(&marks[0],16);    
           printf("Maximum mark of an array=%d \n",max);
           break;
      case 4:
           count=passCount(&marks[0],16);
           printf("No.of Students Passed=%d \n",count);
           break;
      case 5:
           count=secondClassCount(&marks[0],16);
           printf("No.of Students who got second class=%d \n",count);
	   break;
      case 6:
           printfailOrd2ndFirst(&marks[0],16);
	   //printf("%d\n%d\n%d\n%d\n",*(ptr+0),*(ptr+1),*(ptr+2),*(ptr+3));
	   break;
      case 7:
           count=averageAboveCount(&marks[0],16);
           printf("7.No.of Students who got above Average Marks present in array           =%d \n",count);
           break; 
      case 8:
	   printArray(&marks[0],16);
	   break;
      case 9:
           fillArray(&marks[0],16);
	   break;
      case 10:
           exit(0);
    }
  }    
  
}

int avgMark(int mark[],int size)
{
  int average;
  int ch; 
  int sum=0;
  for(ch=0;ch<size;ch++)
  {
     sum=sum+mark[ch];
  }  
   average=sum/size;
   return(average);
}
int minMark(int mark[],int size)
{
  int temp,i,j;
  for(i=0;i<=size-1;i++)
  {
    for(j=i+1;j<=size-1;j++)
    {
      if(mark[i]>mark[j])
       {
         temp=mark[i];
         mark[i]=mark[j];
         mark[j]=temp;
       }
     }
   }
  return(mark[0]);
} 
int maxMark(int mark[],int size)
{
  int temp,i,j;
  for(i=0;i<=size-1;i++)
  {
    for(j=i+1;j<=size-1;j++)
    {
      if(mark[i]<mark[j])
       {
         temp=mark[i];
         mark[i]=mark[j];
         mark[j]=temp;
       }
     }
   }
  return(mark[0]);
}
int passCount(int mark[],int size)
{
  int i,count=0; 
  for(i=0;i<=size-1;i++)
  {
    if(mark[i]>40)
    {
      count++;
    }
  }
  return(count);
}
int secondClassCount(int mark[],int size)
{
  int i,count=0; 
  for(i=0;i<=size-1;i++)
  {
    if(mark[i]<60&&mark[i]>50||mark[i]==50)
    {
      count++;
    }
  }
  return(count);
}
int printfailOrd2ndFirst(int mark[],int size)
{
  int a[4];
  int i;
 int fail=0,ord=0,second=0,first=0; 
  for(i=0;i<=size-1;i++)
  {
    if(mark[i]<40)
    {
     fail++;
    }
    else
    {
        if(mark[i]<50&&mark[i]>40||mark[i]==40)
        { 
          ord++;
        }
        else
        {
            if(mark[i]<60&&mark[i]>50||mark[i]==50)
            {      
              second++;
            }
            else
            {
                if(mark[i]>=60)
                {
                  first++; 
                }
	    }
        }
    }
			
  }

printf("%d\n%d\n%d\n%d\n",fail,ord,second,first);
}    
int averageAboveCount(int mark[0],int size)
{
  int count=0,i,avg;
  int marks[NUM_OF_STUDENTS]={70,65,89,45,32,58,91,83,28,59,66,60,45,38,78,68};
  avg=avgMark(&marks[0],16);
  for(i=0;i<=size-1;i++)
  {
    if(mark[i]>avg||mark[i]==avg)
    {
      count++;
    }
  }
  return(count);
}
void printArray(int mark[],int size)
{
  int i;
  for(i=0;i<=size-1;i++)
  {
    if(i%4==0)
      printf("\n");

         printf("%d ",mark[i]);
    
    
  }
}  
  
/*void printArray(int *marks,int size)
{
  int i;
  for(i=0;i<=size-1;i++)
  {
    if(i%4==0)
      printf("\n");
   
  printf("%d ",*(marks+i));
} 
}*/
void fillArray(int *a,int size)
{
  int i;
  
  for(i=0;i<=size-1;i++)
  {
    printf("Enter Marks:");
    scanf("%d",&a[i]);
  }  

  for(i=0;i<=size-1;i++)
  {
    printf("%d ",*(a+i));
  }  
}
