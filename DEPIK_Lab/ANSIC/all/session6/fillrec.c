#include"stdio.h"
struct sample
{
  int id;
  char name[20];
  int phone;
  struct sample *next;
};struct sample *phead;
main()
{
  char c;
  struct sample *p,i;
  //printf("p size=%d ",sizeof(*p));
  //printf("phead size=%d ",sizeof(*phead));
  //printf("phead size=%d ",sizeof(i));
  while(1)
  {
  printf("Do you want to enter a record?.(y/n)");
  __fpurge(stdin);
  //fflush(stdin);
  if((c=getchar())=='n')
   break;  
  p=(struct sample *)malloc(sizeof(struct sample));
  printf("Enter id,name,phone:");
  scanf("%d%s%d",&p->id,p->name,&p->phone);
  p->next=phead;
  phead=p; 
  //printf("size=%d ",sizeof(*phead));
  }
  p=phead;
  while(p)
  {
    printf("id:%d name:%s number:%d\n",p->id,p->name,p->phone);
    p=p->next;
  }

}
