#define Q_FULL_ERROR 0
#define Q_EMPTY_ERROR 1
#define SUCCESS 2
#define MAX_Q_SIZE 10 
typedef struct
{
  int empNo;
  int salary;
}element_t;
typedef struct
{
  int rdindx;
  int wrindx;
  int noOfElms;
  element_t qBuf[MAX_Q_SIZE];
}cq_t;
cq_t stval;
void displayQueue();
int addElementToQ(element_t *);

