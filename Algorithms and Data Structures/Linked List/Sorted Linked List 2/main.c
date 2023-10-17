#include <stdio.h>
#include <stdlib.h>


/*This is not completely work but idea work.
this is my method I create and test only want to try*/

struct node{
	int data;
	struct node *next;
}*root;

void create(int a[],int n){
	struct node *iter,*t;
	root=(struct node *)malloc(sizeof(struct node));
	root->data=a[0];
	root->next=NULL;
	iter=root;
	int i;
	for(i=1;i<n;i++){
		t=(struct node *)malloc(sizeof(struct node));
		t->data=a[i];
		t->next=NULL;
		iter->next=t;
		iter=t;
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
void change(struct node *t){
	struct node *iter=root;
	while(iter && iter->next->data!=t->data){
		iter=iter->next;
	}
	iter->next=t->next;
	iter=root;
	while(iter && iter->next->data<t->data){
		iter=iter->next;
	}
	t->next=iter->next;
	iter->next=t;
}

int sorted(){
	struct node *iter=root;
	int x=-451;
	while(iter){
		if(iter->data<x){
			change(iter);
		}
		x=iter->data;
		iter=iter->next;
	}
	return 1;
}

int main(int argc, char *argv[]) {
	int a[]={4,5,8,10,9,6,16,25,28};
	struct node *p;
	create(a,9);
	display();
	printf("\n%d\n",sorted());
	printf("\n");
	display();
	return 0;
}
