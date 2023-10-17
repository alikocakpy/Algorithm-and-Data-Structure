#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
}*first,*second;

void create(int a[],int n,struct node *root){
	struct node *last,*iter;
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

void display(struct node *iter){
	while(iter){
		printf("%d ",iter->data);
		iter=iter->next;
	}
}

void concantenating(struct node *first,struct node *second){
	struct node *third=first;
	while(third->next!=NULL){
		third=third->next;
	}
	third->next=second;
}

struct node *mergin(struct node *first,struct node *second){
	struct node *third,*last;
	if(first->data<second->data){
		third=last=first;
		first=first->next;
		last->next=NULL;
	}
	else if(second->data<first->data){
		third=last=second;
		second=second->next;
		last->next=NULL;
	}
	while(first->next!=NULL && second->next!=NULL){
		if(first->data<second->data){
			last->next=first;
			last=first;
			first=first->next;
			last->next=NULL;
		}
		else if(second->data<first->data){
			last->next=second;
			last=second;
			second=second->next;
			last->next=NULL;
		}
		else{
			last->next=first;
			last=first;
			first=first->next;
			second=second->next;
			last->next=NULL;
		}
	}
	if(first->next!=NULL){
		last->next=first;
		last=first;
		first=first->next;
		last->next=NULL;
	}
	if(second){
		last->next=second;
		last=second;
		second=second->next;
		last->next=NULL;
	}
	return third;
}


int main(int argc, char *argv[]) {
	int a[]={4,5,8,10,13,16};
	int b[]={3,6,9,12,13,19};
	first=(struct node *)malloc(sizeof(struct node));
	second=(struct node *)malloc(sizeof(struct node));
	create(a,6,first);
	create(b,6,second);
	
	display(first);
	printf("\n");
	display(second);
	printf("\n");
	concantenating(first,second);
	display(first);
	printf("\n");
	struct node *third=mergin(first,second);
	display(third);
	return 0;
}
