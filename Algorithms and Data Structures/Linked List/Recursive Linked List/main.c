#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
}*root;

void create(int a[],int n){
	root=(struct node *)malloc(sizeof(struct node));
	root->data=a[0];
	root->next=NULL;
	struct node *iter,*last;
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

void display(struct node *root){
	
	if(root->next != NULL)
		display(root->next);
	printf("%d ",root->data);
}

int main(int argc, char *argv[]) {
	int a[]={1,5,7,15,65,75};
	create(a,6);
	display(root);
	return 0;
}
