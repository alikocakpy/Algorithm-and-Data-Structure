#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
}*root;

void create(){
	int i=1,n=5;
	struct node *iter,*last;
	root=(struct node *)malloc(sizeof(struct node));
	root->data=0;
	root->next=NULL;
	last=root;
	while(i<n){
		iter=(struct node *)malloc(sizeof(struct node));
		iter->data=i;
		iter->next=NULL;
		last->next=iter;
		last=iter;
		i++;
	}
}


int display(struct node *iter){
	
	if(iter!=NULL){
		printf("%d ",iter->data);
		return display(iter->next) + 1;
	}
	else
		return 0;
}

//this method or
/*
while(iter){
	count+=1;
	iter=iter->next;
}
*/


int main(int argc, char *argv[]) {
	create();
	printf("\ncounting number :%d",display(root));
	return 0;
}
