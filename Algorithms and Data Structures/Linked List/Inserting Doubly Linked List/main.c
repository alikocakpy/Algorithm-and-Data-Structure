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
	root->data=a[0];
	root->next=root->prev=NULL;
	iter=root;
	int i;
	for(i=1;i<n;i++){
		t=(struct node *)malloc(sizeof(struct node));
		t->data=a[i];
		t->next=NULL;
		t->prev=iter;
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

void insert(int index,int x){
	struct node *iter=root,*t;
	int i=0;
	if(index==0){
		t=(struct node *)malloc(sizeof(struct node));
		t->data=x;
		t->next=iter;
		iter->prev=t;
		t->prev=NULL;
		root=t;
	}
	else{
		while(i<index-1){
			i++;
			iter=iter->next;
		} 
		t=(struct node *)malloc(sizeof(struct node));
		t->data=x;
		if(iter->next!=NULL){
			t->next=iter->next;
			iter->next->prev=t;
			iter->next=t;
			t->prev=iter;
		}
		else{
			t->next=iter->next;
			iter->next=t;
			t->prev=iter;
		}
		
	}
	
}

int main(int argc, char *argv[]) {
	int a[]={1,2,3,4,5,6,7,8,9};
	create(a,9);
	display();
	insert(9,99);
	printf("\n");
	display();
	return 0;
}
