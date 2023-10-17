#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *lChild;
	struct node *rChild;
}*root;


struct node *RInsert(struct node *p,int key){
	struct node *t;
	if(!p){
		t=(struct node *)malloc(sizeof(struct node));
		t->lChild=t->rChild=NULL;
		t->data=key;
		return t;
	}
	
	if(p->data>key)
		p->lChild=RInsert(p->lChild,key);
	else if(p->data<key)
		p->rChild=RInsert(p->rChild,key);
	
	return p;
}

void Inorder(struct node *p){
	if(p){
		Inorder(p->lChild);
		printf("%d ",p->data);
		Inorder(p->rChild);
	}
}

struct node *InPre(struct node *p){
	while(p && p->rChild){
		p=p->rChild;
	}
	return p;
}

struct node *InSucc(struct node *p){
	while(p && p->lChild)
		p=p->lChild;
	return p;
}

int height(struct node *p){
	int x,y;
	if(p){
		x=height(p->lChild);
		y=height(p->rChild);
		
		if(x>y)
			return x+1;
		else
			return y+1;
	}
	return 0;
	
}

struct node *delete(struct node *p,int key){
	struct node *q=NULL;
	if(!p){
		return NULL;
	}
	if(!p->lChild && !p->rChild){
		if(!root)
			root=NULL;
		free(p);
		return NULL;
	}
	
	if(p->data>key)
		p->lChild=delete(p->lChild,key);
	else if(p->data<key)
		p->rChild=delete(p->rChild,key);
	else{
		if(height(p->lChild)>height(p->rChild)){
			q=InPre(p->lChild);
			p->data=q->data;
			p->lChild=delete(p->lChild,q->data);
		}
		else{
			q=InSucc(p->rChild);
			p->data=q->data;
			p->rChild=delete(p->rChild,q->data);
		}
	}
	return p;
}




int main(int argc, char *argv[]) {
	root=RInsert(root,5);
	RInsert(root,2);
	RInsert(root,8);
	RInsert(root,1);
	RInsert(root,3);
	RInsert(root,7);
	RInsert(root,9);
	
	delete(root,12);
	
	Inorder(root);
	
	return 0;
}
