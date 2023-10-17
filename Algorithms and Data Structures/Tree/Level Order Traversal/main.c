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

void levelOrder(struct node *p){
	struct queue qu;
	create(&qu,25);
	
	printf("%d ",p->data);
	enqueue(p,&qu);
	
	while(p){
		p=dequeue(&qu);
		if(p->lChild){
			printf("%d ",p->lChild->data);
			enqueue(p->lChild,&qu);
		}
		if(p->rChild){
			printf("%d ",p->rChild->data);
			enqueue(p->rChild,&qu);
		}
	}
	
}


int main(int argc, char *argv[]) {
	createTree();
	levelOrder(root);
	return 0;
}
