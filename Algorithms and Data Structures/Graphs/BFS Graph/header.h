#ifndef header
#define	header

struct queue{
	int front;
	int rear;
	int size;
	int *q;
}*q;

void create(int n);
void enqueue(int key);
int dequeue();
int isEmpty(struct queue *q);
#endif
