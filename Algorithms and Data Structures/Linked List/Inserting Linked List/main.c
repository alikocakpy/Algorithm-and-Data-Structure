#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
}*root;

void create(int a[],int n){
	struct node *last,*iter;
	root=(struct node *)malloc(sizeof(struct node));
	root->data=a[0];
	root->next=NULL;
	last=root;
	int i;
	for(i=1;i<n;i++){
		iter=(struct node *)malloc(sizeof(struct node));
		iter->data=a[i];
		iter->next=NULL;
		last->next=iter;
		last=iter;
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

void insert(int node,int data){
	struct node *t,*iter;
	if(node==0){
		t=(struct node *)malloc(sizeof(struct node));
		t->data=data;
		t->next=root;
		root=t;
	}
	else if(node>0){
		iter=root;
		int i;
		for(i=0;i<node-1;i++)
			iter=iter->next;
		if(iter){
			t=(struct node *)malloc(sizeof(struct node));
			t->data=data;
			t->next=iter->next;
			iter->next=t;
		}
		t=(struct node *)malloc(sizeof(struct node));
		
	}
}

int main(int argc, char *argv[]) {
	int a[]={1,6,53,24,98,75,63};
	//struct node *p;
	create(a,7);
	display();
	insert(1,95);
	printf("\n");
	display();
	return 0;
}
