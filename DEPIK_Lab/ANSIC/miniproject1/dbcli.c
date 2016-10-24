#include <stdio.h>
#include "file.h"
int  fillEmpDetails(empRecord_t *pEmpRec)
{
   printf("Enter Id:");
   scanf("%d",&pEmpRec->Id);
   printf("Enter name:");
   scanf("%s",pEmpRec->name);
   printf("Enter salary:");
   scanf("%d",&pEmpRec->salary);
   printf("Enter phone Number:");
   scanf("%d",&pEmpRec->phoneNum);
}
void prepareAddMsg(char *msg,empRecord_t *pEmpRec)
{
  int indx=3;
 // msg[indx]=1;
  memcpy(&msg[indx],&pEmpRec->Id,4);
  indx+=4;
  strcpy(msg+indx,pEmpRec->name);
  indx=indx+strlen(pEmpRec->name)+1;
  memcpy(&msg[indx],&pEmpRec->salary,4);
  indx+=4;
  memcpy(&msg[indx],&pEmpRec->phoneNum,4);
  indx+=4;
  memcpy(msg,&indx,2);
}

void  prepareGetDetails(char *msg, empRecord_t *rec)
{
  int index=3;
  memcpy(&rec->Id,&msg[index],4);
  index+=4; 
  strcpy(rec->name,&msg[index]);
  index=index+strlen(msg+index)+1; 
  memcpy(&rec->salary,&msg[index],4);
  index+=4; 
  memcpy(&rec->phoneNum,&msg[index],4);
  index+=4;
   
  printf("\nId=%d",rec->Id); 
  printf("\nName=%s",rec->name); 
  printf("\nsalary=%d",rec->salary); 
  printf("\nphone Number=%d\n",rec->phoneNum);
} 
