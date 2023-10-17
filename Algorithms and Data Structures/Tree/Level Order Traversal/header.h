#ifndef header
#define header

struct queue{
	int front;
	int rear;
	int size;
	struct node **Q;
};

struct node{
	struct node *lChild;
	int data;
	struct node *rChild;
};

void create(struct queue *q,int size);
void enqueue(struct node *p,struct queue *q);
struct node *dequeue(struct queue *q);
int isEmpty(struct queue q);

#endif
