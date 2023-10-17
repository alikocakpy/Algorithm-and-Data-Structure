#include <stdio.h>
#include <stdlib.h>

struct node{
	struct node *prev;
	int data;
	struct node *next;
}*root;

void create(int a[],int n){
	struct node *iter,*t;
	root=(struct node *)malloc(sizeof(struct node));
	root->prev=NULL;
	root->data=a[0];
	root->next=NULL;
	iter=root;
	int i;
	for(i=1;i<n;i++){
		t=(struct node *)malloc(sizeof(struct node));
		t->data=a[i];
		t->prev=iter;
		t->next=NULL;
		iter->next=t;
		iter=t;
	}
}

void display(){
	struct node *iter=root;
	while(iter){
		printf("%d ",iter->data);
		iter=iter->next;
	}
}

int main(int argc, char *argv[]) {
	int a[]={1,2,3,4,5,6,7,8,9};
	create(a,9);
	display();
	return 0;
}
