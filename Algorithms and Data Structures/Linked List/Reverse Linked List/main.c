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

void reverse1(){
	struct node *iter=root;
	int *p,i=0;
	p=(int *)malloc(sizeof(int)*7);
	while(iter){
		p[i]=iter->data;
		i++;
		iter=iter->next;
	}
	i--;
	iter=root;
	while(iter){
		iter->data=p[i];
		i--;
		iter=iter->next;
	}
}

void reverse2(){
	struct node *iter=root,*p=NULL,*q=NULL;
	while(iter){
		q=p;
		p=iter;
		iter=iter->next;
		p->next=q;
	}
	root=p;
	
}

void reverse3(struct node *q,struct node *p){
	if(p){
		reverse3(p,p->next);
		p->next=q;
	}
	else
		root=q;
}

int main(int argc, char *argv[]) {
	int a[]={4,5,8,10,16,25,28};
	struct node *p;
	create(a,7);
	display();
	reverse3(NULL,root);
	printf("\n");
	display();
	return 0;
}
