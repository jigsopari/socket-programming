
void dispAllPrintablechars()
{
  int i,k=1;
  for(i=32;i<=126;i++)
  {
    if(k%16==0)

    putchar('\n');
    //printf("\n");
    putchar(i);  
    k++;
  }
}
main()
{
  dispAllPrintablechars();
}

