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

struct node * search(struct node *iter,int key){
	while(iter){
		if(key==iter->data)
			return iter;
		iter=iter->next;
	}
	return NULL;
}

struct node *Rsearch(struct node *iter,int key){
	if(!iter)
		return NULL;
	if(key==iter->data)
		return iter;
	Rsearch(iter->next,key);

}

int main(int argc, char *argv[]) {
	int a[]={1,6,53,24,98,75,63};
	create(a,7);
	display();
	printf("\n%d",search(root,24));
	printf("\n%d",Rsearch(root,24));
	return 0;
}
