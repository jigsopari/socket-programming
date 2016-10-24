typedef struct
{
  int bookId;
  char title[20];
  char author[20];
}bookInfo_t;

typedef struct
{
  int studentId;
  char name[20];
  int phone;
}studentInfo_t;

typedef struct
{
  int studentId;
  int bookId;
  int day;
  int month;
  int year;
}tranInfo_t;

typedef union
{
  bookInfo_t book;
  studentInfo_t student;
  tranInfo_t transac;
}recUnion_t;

main()
{ 
  int ch;
  recUnion_t unival;
  
  printf("\n1.Book Information");
  printf("\n2.Student Information");
  printf("\n3.Transaction Information");
  printf("\nEnter Choice:");
  scanf("%d",&ch);
  
  displayRecord(ch,&unival);

}

displayRecord(int recordType,recUnion_t *pRecord)
{
    switch(recordType)
    {
      case 1:
          printf("\nEnter book Id=");
          scanf("%d",&pRecord->book.bookId);  
          printf("\nEnter title=");
          scanf("%s",pRecord->book.title);  
          printf("\nEnter author=");
          scanf("%s",pRecord->book.author);

          printf("\nBook Information:");
          printf("\nBook Id   =%d",pRecord->book.bookId);  
          printf("\nAuthor    =%s",pRecord->book.author);  
          printf("\nBook Title=%s\n",pRecord->book.title);  
          break;  
     case 2:
          printf("\nEnter Student Id=");
          scanf("%d",&pRecord->student.studentId);  
          printf("\nEnter Name=");
          scanf("%s",pRecord->student.name);  
          printf("\nEnter phone=");
          scanf("%d",&pRecord->student.phone);

          printf("\nStudent Information:");
          printf("\nStudent Id=%d",pRecord->student.studentId);  
          printf("\nName      =%s",pRecord->student.name);  
          printf("\nPhone     =%d\n",pRecord->student.phone); 
          break;   
     case 3:
          printf("\nEnter Student Id=");
          scanf("%d",&pRecord->transac.studentId);  
          printf("Enter Book Id=");
          scanf("%d",&pRecord->transac.bookId);  
          printf("Enter Day=");
          scanf("%d",&pRecord->transac.day);
          printf("Enter month=");
          scanf("%d",&pRecord->transac.month);   
          printf("Enter year=");
          scanf("%d",&pRecord->transac.year);   

          printf("\nTransaction Information:");
          printf("\nStudent Id    =%d",pRecord->transac.studentId);  
          printf("\nBook Id       =%d",pRecord->transac.bookId);  
          printf("\nDay/Month/Year=%d/%d/%d\n",pRecord->transac.day,                         pRecord->transac.month,pRecord->transac.year); 
          break;
    }
      
}                 
