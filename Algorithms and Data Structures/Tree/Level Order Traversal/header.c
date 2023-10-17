#include <stdio.h>
#include <stdlib.h>
#include "header.h"


void create(struct queue *q,int size){
	q->rear=q->front=0;
	q->size=size;
	q->Q=(struct node **)malloc(sizeof(struct node *)*q->size);
}

void enqueue(struct node *p,struct queue *q){
	if((q->rear+1)%q->size==q->front){
		printf("Queue is full");
	}
	else{
		q->rear=(q->rear+1)%q->size;
		q->Q[q->rear]=p;
	}
}

struct node *dequeue(struct queue *q){
	struct node *x=NULL;
	if(q->front==q->rear){
		printf("Queue is empty");
	}
	else{
		q->front=(q->front+1)%q->size;
		x=q->Q[q->front];
	}
	return x;
}

int isEmpty(struct queue q){
	if(q.front==q.rear)
		return 1;
	else
		return 0;
}
