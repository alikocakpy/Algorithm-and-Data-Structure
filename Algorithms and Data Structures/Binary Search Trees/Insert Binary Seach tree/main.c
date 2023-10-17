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

struct node *bst(struct node *p,int data){
	struct node *t,*q=NULL;
	while(p){
		t=p;
		if(p->data==data)
			return p;
		else if(p->data<data)
			p=p->rChild;
		else
			p=p->lChild;
	}
	//if value doesn't valid array we create space and t->r/l child show it.
	q=(struct node *)malloc(sizeof(struct node));
	q->lChild=q->rChild=NULL;
	q->data=data;
	if(t->data>data){
		t->lChild=q;
	}
	else
		t->rChild=q;
	
	return NULL;
}

struct node *bstR(struct node *p,int data){
	if(!p){
		struct node *q=(struct node *)malloc(sizeof(struct node));
		q->lChild=q->rChild=NULL;
		q->data=data;
		return q;
	}
	if(p->data==data)
		return p;
	else if(p->data>data)
		p->lChild=bstR(p->lChild,data);
	else if(p->data<data)
		p->rChild=bstR(p->rChild,data);
}

int main(int argc, char *argv[]) {
	createTree();
	preOrder(root);
	printf("\n");
	inOrder(root);
	printf("\n");
	postOrder(root);
	
	printf("\n\n");
	int key=7;
	struct node *t=bst(root,key);
	if(t){
		printf("%d founded",t->data);
		inOrder(root);
	}
	else{
		printf("%d not founded but inserted tree \n",key);
		inOrder(root);
	}
	printf("\n");
	key=25;
	t=bstR(root,key);
	printf("\n");
	if(t->data==key){
		printf("%d founded",t->data);
	}
	else{
		printf("%d not founded but inserted tree \n",key);
		inOrder(root);
	}
	
	return 0;
}
