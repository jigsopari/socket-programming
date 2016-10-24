#include <stdio.h>
#include "file.h"
main()
{
  int indx=2,retval;
  empRecord_t *p;
  //p=(empRecord_t *)malloc(sizeof(empRecord_t)); 
  char msg[50];
  char *res;
  res=(char *)malloc(50); 
  while(1)
  {
    printf("\n\t|-----------------------------------------------|");
    printf("\n\t|         1.Add Employee Details                |");        printf("\n\t|         2.Delete Employee Details             |");
    printf("\n\t|         3.Get Employee Details                |");
    printf("\n\t|         4.Modify Employee Details             |");
    printf("\n\t|         5.Exit                                |");
    printf("\n\t|         Enter command No:                     |");
    printf("\n\t|-----------------------------------------------|");
    __fpurge(stdin);
    scanf("%c",&msg[indx]);
    switch(msg[indx])
    {
       case '1':
             p=(empRecord_t *)malloc(sizeof(empRecord_t)); 
            fillEmpDetails(p);
            prepareAddMsg(msg,p);
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
            p=(empRecord_t *)malloc(sizeof(empRecord_t)); 
            printf("Enter Employee Id:");
            scanf("%d",&msg[3]); 
            retval=processDbCmdMsg(msg,res);
          if(retval == SUCCESS)
          { 
             res[0]='0';
             printf("\n%c\n",res[0]);
          } 
          else if(retval==NOT_FOUND)
           { 
              res[0]='2';
              printf("\n%c\n",res[0]);
              break;
              
          }
            prepareGetDetails(res,p); 
            break;
       case '4':
             p=(empRecord_t *)malloc(sizeof(empRecord_t)); 
            fillEmpDetails(p);
            prepareAddMsg(msg,p);
            processDbCmdMsg(msg,res);
            printf("\n%c\n",res[0]);
            break;
            //prepareGetMsg() 
            //getEmpDetails();
       case '5':
            exit(1);
    }
  }
}  
