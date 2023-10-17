#include <stdio.h>
#include <stdlib.h>

struct queue{
	int data;
	struct queue *next;
}*root=NULL,*last=NULL;

int enqueue(int x){
	struct queue *t;
	t=(struct queue *)malloc(sizeof(struct queue)); 
	if(t==NULL){
		printf("Memory is full");
		return -1;
	}
	else if(last==NULL){
		t->data=x;
		t->next=NULL;
		last=root=t;
	}
	else{
		t->data=x;
		t->next=NULL;
		last->next=t;
		last=t;
	}
}
/*
int dequeue(){
	if(root==NULL){
		printf("Memory is empty");
		return -1;
	}
	else{
		struct queue *iter=root;
		root=root->next;
		printf("%d deleted\n",iter->data);
		free(iter);
	}
}

*/
void display(){
	struct queue *iter=root;
	while(iter){
		printf("%d ",iter->data);
		iter=iter->next;
	}
}

int main(int argc, char *argv[]) {
	enqueue(10);
	enqueue(30);
	enqueue(40);
	enqueue(50);
	enqueue(60);
	enqueue(20);
	enqueue(40);
	enqueue(50);
/*	dequeue();
	dequeue();
	dequeue();*/
	display();
	return 0;
}
