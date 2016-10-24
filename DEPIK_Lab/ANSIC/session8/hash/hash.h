#define MAX 11 
typedef struct hashItem_s
{
   char name[20];
   int age;
   int salary;
   int phoneNum;
   struct hashItem_s *pNext;
} hashItem_t;
hashItem_t *hBuf[MAX];
