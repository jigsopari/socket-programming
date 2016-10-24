#define Q_FULL_ERROR 0
#define Q_EMPTY_ERROR 1
#define SUCCESS 2
#define MAX_Q_SIZE 10 
typedef struct element
{
  int empNo;
  int salary;
  struct element *pNxt;
}element_t;
 element_t *wrHead,*rdHead;
void displayQueue();
int addElementToQ(element_t *);

