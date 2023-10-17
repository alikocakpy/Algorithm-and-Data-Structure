#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include "stack.h"

struct node *root=NULL;

void createTree(){
	struct queue q;
	create(&q,25);
	
	struct node *t=NULL,*p=NULL;
	int x;
	
	printf("Enter the root data :");
	scanf("%d",&x);
	
	
	root=(struct node *)malloc(sizeof(struct node));
	root->lChild=root->rChild=NULL;
	root->data=x;
	
	enqueue(root,&q);
	
	while(!isEmpty(q)){
		p=dequeue(&q);
		printf("Enter the left child of %d :",p->data);
		scanf("%d",&x);
		if(x!=-1){
			t=(struct node *)malloc(sizeof(struct node));
			t->lChild=t->rChild=NULL;
			t->data=x;
			p->lChild=t;
			enqueue(t,&q);
		}
		printf("Enter the right child of %d :",p->data);
		scanf("%d",&x);
		if(x!=-1){
			t=(struct node *)malloc(sizeof(struct node));
			t->lChild=t->rChild=NULL;
			t->data=x;
			p->rChild=t;
			enqueue(t,&q);
		}
	}
}

/*
this is the true way we store the addres at integer so we can store negative or positive we only did type casting at main function. this is simple already we pass address variable and value so program made itself but this time we did.
we cant define storing variable type double becouse double keep the unsigned value so we use long int.
*/



void IPostOrder(struct node *p){
	struct stk st;
	createStk(&st,25);
	
	long int temp;
	while(p || !isEmptyStk(st)){
		if(p){
			temp=p;
			push(&st,temp);
			p=p->lChild;
		}
		else{
			temp=pop(&st);
			if(temp>0){
				push(&st,-temp);
				p=((struct node *)temp)->rChild;
			}
			else{
				printf("%d ",((struct node*)(-temp))->data);
				p=NULL;
			}
		}
	}
}

int main(int argc, char *argv[]) {
	createTree();
	IPostOrder(root);
	return 0;
}
