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

struct node *search(struct node *iter,int key){
	struct node *p=NULL,*q=NULL;
	while(iter){
		if(iter->data == key){
			q->next=iter;
			p->next=iter->next;
			iter->next=p;
			return ;
		}
		q=p;
		p=iter;
		iter=iter->next;
	}
	return NULL;
}

int main(int argc, char *argv[]) {
	int a[]={1,6,53,24,98,75,63};
	struct node *p;
	create(a,7);
	display();
	p=search(root,24);
	if(p)
		printf("\n%d\n",p->data);
	else
		printf("\nThis member does not available\n");
	display();
//	printf("\n%d",Rsearch(root,24));
	return 0;
}
