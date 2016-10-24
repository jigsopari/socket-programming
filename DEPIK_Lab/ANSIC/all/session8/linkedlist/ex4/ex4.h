typedef struct sampNode
{
  int info;
  struct sampNode *pNxtNode;
  struct sampNode *pPrvNode;
}sampNode_t;
sampNode_t *pHead;
sampNode_t *pTail;
#define SUCCESS 2
#define NOT_FOUND 0
