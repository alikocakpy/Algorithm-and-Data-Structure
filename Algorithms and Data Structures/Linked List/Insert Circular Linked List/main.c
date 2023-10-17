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
	last->next=root;
}

void display(){
	struct node *iter=root;
	do{
		printf("\n%d ",iter->data);
		iter=iter->next;
	}while(iter!=root);
}

int isLoop(){
	struct node *p,*q;
	p=q=root;
	do{
		p=p->next;
		q=q->next;
		q=q?q->next:NULL;
	}while(p && q && q!=p);
	
	if(p==q){
		return 1;
	}
	else{
		return 0;
	}
}


void insert(int index,int value){
	struct node *iter=root,*t;
	if(index==0){
		t=(struct node *)malloc(sizeof(struct node));
		t->data=value;
		if(!iter){
			root=t;
			t->next=t;
		}
		else{
			while(iter->next!=root)iter=iter->next;
			t->next=root;
			iter->next=t;
			root=t;
		}
	}
	else{
		t=(struct node*)malloc(sizeof(struct node));
		t->data=value;
		int i;
		for(i=0;i<index-1;i++)
			iter=iter->next;
		t->next=iter->next;
		iter->next=t;
	}
}

int main(int argc, char *argv[]) {
	int a[]={4,5,8,10,16,25,28};
	struct node *p;
	create(a,7);
	
	if(isLoop()){
		printf("This is LOOP");
	}
	else{
		printf("This is not LOOP");
	}
	
	getch();
	insert(1,9);
	display(); //if you active this code line program always write same value because we create a loop
	return 0;
}
