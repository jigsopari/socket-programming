typedef struct sampNode
{
  int info;
  struct sampNode *pNxtNode;
}sampNode_t;
sampNode_t *pHead;
sampNode_t *pTail;

void fillNode(sampNode_t *pNode);
void dispNode(sampNode_t *p);
void addNodeToHead(sampNode_t *pNode);
void addNodeToTail(sampNode_t *pNode);
void insertNodeInSortedList(sampNode_t *pNode); 
#define SUCCESS 2
#define NOT_FOUND 0
