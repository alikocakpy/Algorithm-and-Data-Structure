#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
}*root;

void create(int a[],int n){
	int i=1;
	struct node *iter,*last;
	root=(struct node *)malloc(sizeof(struct node));
	root->data=a[0];
	root->next=NULL;
	last=root;
	while(i<n){
		iter=(struct node *)malloc(sizeof(struct node));
		iter->data=a[i];
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

int max(struct node *iter){
	int x=-32768;
	while(iter){
		if(iter->data>x)
			x=iter->data;
		iter=iter->next;
	}
	return x;
}

int Rmax(struct node *iter){
	int x=-32768;
	if(!iter)
		return x;
	else{
		x=Rmax(iter->next);
		if(x>iter->data)
			return x;
		else
			return iter->data;
	}
}

int main(int argc, char *argv[]) {
	int a[]={0,9,35,120,78,36};
	create(a,6);
	printf("\ncounting number :%d \n",display(root));
	printf("%d \n",max(root));
	printf("%d \n",Rmax(root));
	return 0;
}
