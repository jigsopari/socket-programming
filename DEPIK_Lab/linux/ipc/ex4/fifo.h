#include <stdio.h>
#include <stdlib.h>
#define FIFO1 /ex4/fifo1
#define FIFO2 /ex4/fifo2
typedef struct 
{
  int Id;
  char name[220];
  int salary;
  int phNum;
}empRec_t;

#define REC_SIZE sizeof(empRec_t)
#define SUCCESS 0
#define DATA_BASE_FULL_ERROR 1
#define NOT_FOUND 2
void fillRec(empRec_t *rec);
