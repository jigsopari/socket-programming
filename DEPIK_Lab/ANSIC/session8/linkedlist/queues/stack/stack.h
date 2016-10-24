#define MAX_STACK_SIZE 10
typedef struct
{
  int empNo;
  int salary;
}element_t;
typedef struct 
{
  int top;
  int noOfElements;
  element_t sBuf[MAX_STACK_SIZE];
}stack_t;
stack_t strval;

