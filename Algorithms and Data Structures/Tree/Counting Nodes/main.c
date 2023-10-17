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

int count(struct node *p){
	int x,y;
	if(p){
		x=count(p->lChild);
		y=count(p->rChild);
		
		return x+y+1;
	}
	return 0;
}

int count2(struct node *p){
	int x,y;
	if(p){
		x=count2(p->lChild);
		y=count2(p->rChild);
		
		if(x>y)
			return x+1;
		else
			return y+1;
			
	}
	return 0;
}

int count3(struct node *p){
	int x,y;
	if(p){
		x=count3(p->lChild);
		y=count3(p->rChild);
		return x+y+p->data;
	}
	return 0;
}

int count4(struct node *p){
	int x,y;
	if(p){
		x=count4(p->lChild);
		y=count4(p->rChild);
		if(p->rChild && p->lChild)
			return x+y+1;
		else
			return x+y;
	}
	return 0;
}

int main(int argc, char *argv[]) {
	createTree();
	preOrder(root);
	printf("\n");
	inOrder(root);
	printf("\n");
	postOrder(root);
	printf("\n\n\n");
	int x=count(root);
	printf("Number of Nodes :%d \n",x);
	x=count2(root);
	printf("Height of a tree: %d \n",x);
	x=count3(root);
	printf("Sum of all nodes value : %d \n",x);
	x=count4(root);
	printf("Number of hasing left and right children : %d \n",x);
	return 0;
}
