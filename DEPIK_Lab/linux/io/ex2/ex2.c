/********************* Header files **********************************/ 
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
/********************* Macros *****************************************/
#define SUCCESS 0
#define NOT_FOUND 1
#define INVALID_CMD_ERR 2
#define REC_SIZE sizeof(student_t)

/********************** Global Declarations ***************************/
typedef struct 
{
	int Id;
	char name[20];
	int phNo;
}student_t;
int fd;
/*********************** Main Function ********************************/
main()
{
  int status,studentId;	
  int len;
  int ch;
  student_t *ps;
  ps=(student_t *)malloc(sizeof(student_t));
  
  fd=open("studentRecord",O_RDWR);
  if(fd<0)
  {	
    printf(" Creating File....");
    fd=open("studentRecord",O_RDWR|O_CREAT,0644);
    if(fd<0)
    {
      printf("File can Not Created...");
      exit(1);
    }
  }
    
  while(1)
  {
    printf("\n\n\t\tTelephone directory program, ver 1\n\n");
    printf("\n\t\t1.ADD NEW RECORDS       ");
    printf("\n\t\t2.DISPLAY ALL RECORDS    ");
    printf("\n\t\t3.DELETE RECORDS         ");
    printf("\n\t\t4.EXIT               \n\n");
    printf("\n\t\tENTER YOUR CHOICE:");
    __fpurge(stdin);
    scanf("%d",&ch);
    switch(ch)
    {
       case 1:
            status=addNewStudentRec(fd,ps);
	    printf("%d",status);
	    break;
       case 2:
            status=dispAllStudentRecs(fd);
	    printf("%d",status);
	    break;
       case 3:
	    printf("\nEnter student Id:");
	    scanf("%d",&studentId);
            status=deleteStudentRec(fd,studentId);
	    printf("%d",status);
	    break;
        case 4:
	    exit(1);
       default:
            printf("INVALID_CMD_ERR\n");
        printf("continue by selecting the following options only\n");
	    break;
     }		
   }
 }
 int addNewStudentRec(int fd,student_t *ps)
 {
    int len;
    student_t trec;
    
    printf("\n enter the studentID:");
    scanf("%d",&ps->Id);
    printf("\n enter the name:");
    scanf("%s",ps->name);
    printf("\n enter the phno:");
    scanf("%d",&ps->phNo);
    
    lseek(fd,0,SEEK_SET);

    while(1)
    {
      len=read(fd,&trec,REC_SIZE);
      if(len!=REC_SIZE)
      {	      
        write(fd,ps,REC_SIZE);
        return SUCCESS;
      }
      //break;
      if(trec.Id==-1)
      {
    	 lseek(fd,-1*REC_SIZE,SEEK_CUR);
	 write(fd,ps,REC_SIZE);
	 return SUCCESS;
      }
      //len=read(fd,&trec,REC_SIZE);
    }
    //write(fd,&rec,REC_SIZE);
    //return SUCCESS;
 }  

int dispAllStudentRecs(int fd)
{
  int len;
  student_t trec;
  lseek(fd,0,SEEK_SET);
  len=read(fd,&trec,REC_SIZE);
  if(len!=REC_SIZE)
  {	
    printf("no records to printf...");
    return;
  }
         
  while(len==REC_SIZE)
  {
      if(trec.Id==-1)
      {
         len=read(fd,&trec,REC_SIZE);
         continue;
      }
      else
      {  	
  	  printf("\n%d %s %d ", trec.Id,trec.name,trec.phNo);
	  len=read(fd,&trec,REC_SIZE);
      }
  }
}   
int deleteStudentRec(int fd,int studentId)
{
   int len=0;
   student_t rec;
   //rec=(student_t *)malloc(sizeof(student_t));
   lseek(fd,0,SEEK_SET);
   len=read(fd,&rec,REC_SIZE);
   while(len==REC_SIZE)
   {
	//if(len!=REC_SIZE)
	  //return NOT_FOUND;
	//break;
	if(rec.Id==studentId)
	{
	  rec.Id = -1;
	  lseek(fd,REC_SIZE*-1,SEEK_CUR);
	  write(fd,&rec,REC_SIZE);
	  return SUCCESS;
        }
	else
        len=read(fd,&rec,REC_SIZE);
   }
   return NOT_FOUND;
}		
