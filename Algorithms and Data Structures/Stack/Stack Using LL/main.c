#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
}*top=NULL;


int push(int x){
	struct node *t;
	t=(struct node *)malloc(sizeof(struct node));
	if(t==NULL)
		return -1;
	else{
		t->data=x;
		t->next=top;
		top=t;
	}
}

int pop(){
	if(top==NULL)
		printf("Stack is Empty");
	struct node *t;
	t=top;
	top=top->next;
	int x=t->data;
	t->next=NULL;
	free(t);
	return x;
}

int peek(int index){
	struct node *iter;
	iter=top;
	int i;
	for(i=0;i<index && iter;i++){
		iter=iter->next;
	}
	if(iter)
		printf("%d",iter->data);
	return -1;
}

int isEmpty(){
	if(top==NULL)
		printf("This Empty");
	else
		printf("Not Empty");
}

int isFull(){
	struct node *t;
	t=(struct node *)malloc(sizeof(struct node));
	
	if(t==NULL)
		printf("This is Full");
	else
		printf("This is not full");
}

void display(){
	struct node *iter=top;
	while(iter){
		printf("%d\n",iter->data);
		iter=iter->next;
	}
	printf("\n");
}


int main(int argc, char *argv[]) {
	push(5);
	push(6);
	push(7);
	push(8);
	push(9);
	push(13);
	push(19);
	push(12);
	display();
	pop();
	pop();
	pop();
	pop();
	display();
	peek(2);
	printf("\n");
	isEmpty();
	printf("\n");
	isFull();
	return 0;
}
