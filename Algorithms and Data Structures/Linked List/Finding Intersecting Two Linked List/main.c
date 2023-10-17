#include <stdio.h>
#include <stdlib.h>

/*
Normally abdul bari use the stack1,stack2,pop,push but I dont know this quality so I did my method
but this is my method not exactly stack method.
*/


struct node{
	int data;
	struct node *next;
}*root1,*root2;

void create(struct node *root,int a[],int n){
	struct node *iter,*t;
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

void display(struct node *iter){
	while(iter){
		printf("%d ",iter->data);
		iter=iter->next;
	}
	printf("\n");
}

struct node *pop(struct node *tail,struct node *head){
	struct node *iter=head;
	while(iter->next!=tail)
		iter=iter->next;
	
	free(tail);
	tail=iter;
	return iter;
	
}

int intersecting(struct node *root1,struct node *root2){
	struct node *iter1=root1,*iter2=root2;
	int a;
	while(iter1->next)iter1=iter1->next;
	while(iter2->next)iter2=iter2->next;
	while(iter1->data==iter2->data){
		a=iter2->data;
		iter1=pop(iter1,root1);
		iter2=pop(iter2,root2);
	}
	
	printf("%d intersecting point.",a);
}



int main(int argc, char *argv[]) {
	int a[]={2,4,6,8,9,10};
	int b[]={1,3,5,7,8,9,10};
	root1=(struct node *)malloc(sizeof(struct node));
	root2=(struct node *)malloc(sizeof(struct node));
	create(root1,a,6);
	display(root1);
	create(root2,b,7);
	display(root2);
	intersecting(root1,root2);
	return 0;
}
