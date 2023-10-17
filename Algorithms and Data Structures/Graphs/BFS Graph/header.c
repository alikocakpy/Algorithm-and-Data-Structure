#include <stdlib.h>
#include <stdio.h>
#include "header.h"




void create(int n){
	q=(struct queue *)malloc(sizeof(struct queue));
	q->rear=q->front=0;
	q->size=n;
	q->q=(int *)malloc(sizeof(int *)*q->size);
}

void enqueue(int key){
	if(q->rear==q->size){
		printf("Queue full");
	}
	else{
		q->q[q->rear++]=key;
	}
}

int dequeue(){
	if(q->front==q->rear){
		printf("Queue is empty");
	}
	else{
		return q->q[q->front++];
	}
}

int isEmpty(struct queue *q){
	return q->front==q->rear?1:0;
}
