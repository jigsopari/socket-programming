/********************* Header Files **********************************/ 
#include<string.h>
#include<stdio.h>
#include<fcntl.h>
/********************* Macros *****************************************/
#define SUCCESS 0
#define NOT_FOUND 1
#define REC_SIZE sizeof(student_t)

/********************** Global Declarations ***************************/
typedef struct 
{
	int Id;
	char name[20];
	int phNo;
}student_t;
/*********************** Main Function *******************************/
main()
{
  int studentId;	
  int len;
  int ch,status;
  FILE *fp;
  student_t *ps;
  fp=fopen("filename","w+");
  if(fp == NULL)
  {	
      printf("File is not created...");
      exit(1);
   }
    
  while(1)
  {  
    printf("\n\t|--------------------------------|");
    printf("\n\t|	1.ADD NEW RECORDS        |");
    printf("\n\t|	2.DISPLAY ALL RECORDS    |");
    printf("\n\t|	3.DELETE RECORDS         |");
    printf("\n\t|       4.EXIT                   |");
    printf("\n\t| 	ENTER YOUR CHOICE        |");
    printf("\n\t|--------------------------------|");
    scanf("%d",&ch);
    switch(ch)
    {
       case 1:
            ps=(student_t *)malloc(sizeof(student_t));
            status=addNewStudentRec(fp,ps);
	    printf("%d",status);
	    break;
       case 2:
            dispAllStudentRecs(fp);
	    break;
       case 3:
	    printf("\nEnter Student Id:");
	    scanf("%d",&studentId);
            status=deleteStudentRec(fp,studentId);
	    printf("%d",status);
	    break;
        case 4:
	    fclose(fp);
	    exit(1);
     }		
   }
 }
   
 int addNewStudentRec(FILE *fp,student_t *ps)
 {
    char buf[100];
    int len,first,second;
    student_t trec;
    printf("\n Enter the studentID:");
    scanf("%d",&ps->Id);
    printf("\n Enter the Name:");
    scanf("%s",ps->name);
    printf("\n Enter the phone Number:");
    scanf("%d",&ps->phNo);
    fseek(fp,0,SEEK_SET);
    while(1)
    {
      
      first=ftell(fp);
      len=fscanf(fp,"%d  |  %s  |  %d\n",&trec.Id,trec.name,&trec.phNo);
      if(len<0)
      {	      
       fprintf(fp,"%-4d  |  %-20s  |  %-8d\n",ps->Id,ps->name,ps->phNo);
         return SUCCESS;
      }
      else
      {
        if(trec.Id==-1)
        {  
          second=ftell(fp);
    	  fseek(fp,-1*(second-first),SEEK_CUR);
       fprintf(fp,"%-4d  |  %-20s  |  %-8d\n",ps->Id,ps->name,ps->phNo);
	  return SUCCESS;
        }
        else
          continue;
      }
    }  
 }  

int dispAllStudentRecs(FILE *fp)
{
  char buf[72];
  int len;
  student_t trec;
  fseek(fp,0,SEEK_SET);
  len=fscanf(fp,"%d  |   %s  |   %d\n",&trec.Id,trec.name,&trec.phNo);
  
  if(len<0)
  {	
    printf("no records to printf...");
    return;
  }
         
  while(len>0)
  {
      if(trec.Id==-1)
      {
      len=fscanf(fp,"%d  |  %s  |  %d\n",&trec.Id,trec.name,&trec.phNo);
         continue;
      }
      else
      {  	
    printf("%-4d  |  %-20s  |  %-8d\n", trec.Id,trec.name,trec.phNo);
        len=fscanf(fp,"%d  |  %s  |  %d\n",&trec.Id,trec.name,&trec.phNo);
      }
  }
}   
int deleteStudentRec(FILE *fp,int studentId)
{
   int len,first,second;
   student_t trec;
   fseek(fp,0,SEEK_SET);
   first=ftell(fp);
   len=fscanf(fp,"%d  |  %s  |  %d\n",&trec.Id,trec.name,&trec.phNo);
   while(len>0)
   {
	if(trec.Id==studentId)
	{
	  second=ftell(fp);
	  trec.Id = -1;
	  fseek(fp,-1*43,SEEK_CUR);
    fprintf(fp,"%-4d  |  %-20s  |  %-8d\n",trec.Id,trec.name,trec.phNo);
	  return SUCCESS;
        }
	else
	  first=ftell(fp);
        len=fscanf(fp,"%d  |  %s  |  %d\n",&trec.Id,trec.name,&trec.phNo);
   }
   return NOT_FOUND;
}	
