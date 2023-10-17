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

void removee(){
	struct node *iter,*p;
	iter=root->next;
	p=root;
	while(iter){
		if(iter->data==p->data){
			p->next=iter->next;
			free(iter);
			iter=p->next;
		}
		else{
			p=iter;
			iter=iter->next;
		}
	}
}

int main(int argc, char *argv[]) {
	int a[]={4,5,5,6,8,9,9,9};
	struct node *p;
	create(a,8);
	display();
	removee();
	printf("\n");
	display();
	return 0;
}
