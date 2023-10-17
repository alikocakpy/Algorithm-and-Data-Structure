#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *lchild;
	struct node *rchild;
}*root;

void insert(int data){
	struct node *p=root;
	struct node *t,*r;
	
	if(!root){
		t=(struct node *)malloc(sizeof(struct node));
		t->lchild=t->rchild=NULL;
		t->data=data;
		root=t;
		return;
	}
	
	while(p){
		r=p;
		if(p->data>data){
			p=p->lchild;
		}
		else if(p->data<data){
			p=p->rchild;
		}
		else{
			return;
		}
	}
	t=(struct node *)malloc(sizeof(struct node));
	t->lchild=t->rchild=NULL;
	t->data=data;
	if(r->data>data){
		r->lchild=t;
	}
	else
		r->rchild=t;
}

struct node * search(int data){
	struct node *p=root;
	while(p){
		if(p->data<data)
			p=p->rchild;
		else if(p->data>data)
			p=p->lchild;
		else if(p->data==data)
			return p;
		else
			return NULL;
	}
}

void inorder(struct node *p){
	if(p){
		inorder(p->lchild);
		printf("%d ",p->data);
		inorder(p->rchild);
	}
}

int main(int argc, char *argv[]) {
	insert(10);
	insert(20);
	insert(30);
	insert(40);
	insert(50);
	insert(60);
	insert(70);
	
	inorder(root);
	printf("\n");
	struct node *t;
	t=search(60);
	if(t)
		printf("%d found",t->data);
	else
		printf("member is invalid");
	
	return 0;
}
