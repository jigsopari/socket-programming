#include <stdio.h>
#include "file.h"
main()
{
  int indx=2,Id,salary,phoneNum;
  empRecord_t *p;
  char msg[80];
  char name[20];
  char *res;
  res=(char *)malloc(10); 
  while(1)
  {
   printf("\n\t|----------------------------------------------------------|");
   printf("\n\t|              1.Add Employee Details                      |");
   printf("\n\t|              2.Delete Employee Details                   |");
   printf("\n\t|              3.Get Employee Details                      |");
   printf("\n\t|              4.Modify Employee Details                   |");
   printf("\n\t|              5.Exit                                      |");
   printf("\n\t|                Enter command No:                         |");
   printf("\n\t|----------------------------------------------------------|");
    __fpurge(stdin);
    scanf("%c",&msg[indx]);
    switch(msg[indx])
    {
       case '1':
             p=(empRecord_t *)malloc(sizeof(empRecord_t)); 
            fillEmpDetails(p);
          sprintf(&msg[3],"%d %s %d %d \n",p->Id,p->name,p->salary,p->phoneNum);
            processDbCmdMsg(msg,res);
            printf("\n%c\n",res[0]);
            break;  
       case '2':
            printf("Enter Employee Id:");
            scanf("%d",&msg[3]); 
            processDbCmdMsg(msg,res);
            printf("\n%c\n",res[0]);
            break;
       case '3':
            printf("Enter Employee Id:");
            scanf("%d",&msg[3]); 
            processDbCmdMsg(msg,res);
            break;
       case '4':
             p=(empRecord_t *)malloc(sizeof(empRecord_t)); 
            fillEmpDetails(p);
          sprintf(&msg[3],"%d %s %d %d \n",p->Id,p->name,p->salary,p->phoneNum);
            processDbCmdMsg(msg,res);
            printf("\n%c\n",res[0]);
            break;
       case '5':
            exit(1);
    }
  }
}  
