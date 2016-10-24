#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include<errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <pthread.h>
#define MSG_LEN 256 

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
void * srvClient(void *arg);


struct sockaddr_in srvAdr,cliAdr;
int fileFd;
