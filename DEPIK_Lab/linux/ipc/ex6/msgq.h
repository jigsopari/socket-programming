#include <stdio.h>
#include<errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#define MY_KEY 19920809 
#define MSG_LEN 256 
#define SRV_MSG_TYPE 1 
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
 
