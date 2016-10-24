
void dispAllPrintablechars()
{
  int i,k=1;
  for(i=32;i<=126;i++)
  {
    if(k%16==0)
    putchar('\n');
    
    putchar(i);  
    putchar(' ');  
    k++;
  }
}
main()
{
  dispAllPrintablechars();
}

