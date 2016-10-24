typedef struct
{
  char name;
  int no;
}studentInfo_t;  
char *pc;
short *ps;
int *pi;
float *pf;
studentInfo_t *pst;
main()
{
  pc=(char *)100;
  ps=(short*)100;
  pi=(int *)100;
  pf=(float *)100;
  pst=(studentInfo_t *)100;
  printf("Address of pc=%u  value of pc=%d\n",&pc,pc); 
  printf("Address of ps=%u  value of ps=%d\n",&ps,ps); 
  printf("Address of pi=%u  value of pi=%d\n",&pi,pi); 
  printf("Address of pf=%u  value of pf=%d\n",&pf,pf); 
  printf("Address of pst=%u  value of pst=%d\n",&pst,pst);
  pc++;
  ps++;
  pi++;
  pf++;
  pst++;
  printf("value of pc=%d\n",pc); 
  printf("value of ps=%d\n",ps); 
  printf("value of pi=%d\n",pi); 
  printf("value of pf=%d\n",pf); 
  printf("value of pst=%d\n",pst);
  pc+=10;
  ps+=10;
  pi+=10;
  pf+=10;
  pst+=10;
  printf("value of pc=%d\n",pc); 
  printf("value of ps=%d\n",ps); 
  printf("value of pi=%d\n",pi); 
  printf("value of pf=%d\n",pf); 
  printf("value of pst=%d\n",pst);
} 
    
	
