#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
}*first;

void create(int a[],int n){
	struct node *t,*last;
	first=(struct node *)malloc(sizeof(struct node));
	first->data=a[0];
	first->next=NULL;
	last=first;
	int i;
	for(i=1;i<n;i++){
		t=(struct node *)malloc(sizeof(struct node));
		t->data=a[i];
		t->next=NULL;
		last->next=t;
		last=t;
	}
}

void display(struct node *p){
	while(p!=NULL){
		printf("%d ",p->data);
		p=p->next;
	}
}

int main(int argc, char *argv[]) {
	int a[]={1,2,3,4,5,6};
	create(a,6);
	display(first);
	return 0;
}
