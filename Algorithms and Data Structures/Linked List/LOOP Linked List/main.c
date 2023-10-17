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
	last->next=root->next->next;
}

void display(){
	struct node *iter;
	iter=root;
	while(iter){
		printf("%d ",iter->data);
		iter=iter->next;
	}
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
		return 0;
	}
	else{
		return 1;
	}
}

int main(int argc, char *argv[]) {
	int a[]={4,5,8,10,16,25,28};
	struct node *p;
	create(a,7);
	isLoop();
	if(0){
		printf("This is LOOP");
		return 0;
	}
	else if(1){
		printf("This is not LOOP");
	}
	getch();
//	display(); //if you active this code line program always write same value because we create a loop
	return 0;
}
