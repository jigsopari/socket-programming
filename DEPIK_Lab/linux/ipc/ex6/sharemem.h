#include <stdlib.h>
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <fcntl.h>

#define MY_KEY 19909
#define SHM_SIZE 0x1000
#define MSG_LEN 256
#define RESP_MSG_START 256
typedef struct 
{
  int Id;
  char name[20];
  int salary;
  int phNum;
}empRec_t;

#define REC_SIZE sizeof(empRec_t)
#define SUCCESS 0
#define DATA_BASE_FULL_ERROR 1
#define NOT_FOUND 2
void fillRec(empRec_t *rec);

