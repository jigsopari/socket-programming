main()
{
  int i;
  int marks[]={55,65,75,85,95};
  for(i=0;i<=4;i++)
   {
     display(&marks[i]);
   }
} 
  
display(int *n)
{ 
  show(&n);
}

show(int **m)
{
  printf("%d \n",**m);
}
