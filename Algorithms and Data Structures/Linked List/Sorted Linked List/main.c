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

void sorted(struct node *iter,int key){
	struct node *p=NULL,*t;
	
	t=(struct node *)malloc(sizeof(struct node));
	t->data=key;
	t->next=NULL;
	
	if(!iter){
		root=t;
	}
	else{
		while(iter && iter->data < key){
			p=iter;
			iter=iter->next;
		}
		if(iter==root){
			t->next=iter;
			root=t;
		}
		else{
			p->next=t;
			t->next=iter;
		}
		
	}
}

int main(int argc, char *argv[]) {
	int a[]={4,5,8,10,16,25,28};
	struct node *p;
	create(a,7);
	display();
	sorted(root,15);
	printf("\n");
	display();
	return 0;
}
