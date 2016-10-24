#include <stdio.h>
#include <stdlib.h>
#include <string.h>
main()
{
  struct emp
  {
    char name[20];
    int id;
  };
  struct emp *emp1;
  //emp1=(struct emp *)malloc(sizeof(struct emp));
  emp1=malloc(sizeof(struct emp));
  printf("Enter name:");
  //scanf("%s",(*emp1).name);
  fgets((*emp1).name,20,stdin);
  printf("Enter id:");
  scanf("%d",&(*emp1).id);
  printf("Name:%s",(*emp1).name);
  printf("Id:%d",(*emp1).id);
}  
