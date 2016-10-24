#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
char *wrBuf;
typedef struct
{
  char *buf;
  int maxBufSize;
  int readIndex;
  int writeIndex;
  int noOfChars;
  sem_t semaphore;
  int waitFlag;
}cirq_t;  
cirq_t xpipe; 
sem_t semaphore; 
