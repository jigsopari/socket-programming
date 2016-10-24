#define NUM_OF_STUDENTS 16
main()
{
  int avg;  
  int marks[NUM_OF_STUDENTS]={70,65,89,45,32,58,91,83,28,59,66,60,45,38,78,68};
  average=avgMark(&marks[0],16);
  printf("average=%d",average);
}

int avgMark(int *mark,int size)
{
  int average;
  int ch; 
  int sum=0;
  for(ch=0;ch<size;ch++)
  {
     sum=sum+*mark; 
     mark++;
  }  
   average=sum/size;
   return(average);
}
