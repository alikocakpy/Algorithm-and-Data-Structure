#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
}*root;

void create(int a[],int n){
	struct node *iter,*t;
	root=(struct node *)malloc(sizeof(struct node));
	root->data=a[0];
	root->next=NULL;
	iter=root;
	int i;
	for(i=1;i<n;i++){
		t=(struct node *)malloc(sizeof(struct node));
		t->data=a[i];
		t->next=NULL;
		iter->next=t;
		iter=t;
	}
}

void display(){
	struct node *iter;
	iter=root;
	while(iter){
		printf("%d ",iter->data);
		iter=iter->next;
	}
}

int del(int wanted){
	struct node *iter,*t=NULL;
	iter=root;
	int x;
	while(iter->data!=wanted && iter){
		t=iter;
		iter=iter->next;
	}
	if(iter==root){
		t=root;
		root=root->next;
		x=t->data;
		free(t);
	}
	else{
		t->next=iter->next;
		x=iter->data;
		free(iter);
	}
	return x;
	
}

int main(int argc, char *argv[]) {
	int a[]={4,5,8,10,16,25,28};
	struct node *p;
	create(a,7);
	display();
	printf("\n%d\n",del(4));
	printf("\n");
	display();
	return 0;
}
