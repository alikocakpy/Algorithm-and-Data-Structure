#include <stdio.h>
#include <stdlib.h>
#include "header.h"

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

void preOrder(struct node *p){
	if(p){
		printf("%d ",p->data);
		preOrder(p->lChild);
		preOrder(p->rChild);
	}
}

void inOrder(struct node *p){
	if(p){
		inOrder(p->lChild);
		printf("%d ",p->data);
		inOrder(p->rChild);
	}
}

void postOrder(struct node *p){
	if(p){
		postOrder(p->lChild);
		postOrder(p->rChild);
		printf("%d ",p->data);
	}
}

int main(int argc, char *argv[]) {
	createTree();
	preOrder(root);
	printf("\n");
	inOrder(root);
	printf("\n");
	postOrder(root);
	return 0;
}
