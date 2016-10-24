#define SUCCESS 0
#define NOT_FOUND 2
typedef struct empRecord
{
  int Id;
  char name[20];
  int salary; 
  int phoneNum;
  struct empRecord *pNxt;
}empRecord_t;
empRecord_t *pHead;
//void prepareModiDetails(char *pCmdMsg);
//void  prepareGetDetails(char *msg,empRecod_t *r);
//void prepareAddMsg(char *msg,empRecord_t *pEmpRec);
