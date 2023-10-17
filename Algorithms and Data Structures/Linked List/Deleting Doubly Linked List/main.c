#include <stdio.h>
#include <stdlib.h>

struct node{
	struct node *prev;
	int data;
	struct node *next;
}*root;

void create(int a[],int n){
	struct node *iter,*t;
	root=(struct node *)malloc(sizeof(struct node));
	root->data=a[0];
	root->next=root->prev=NULL;
	iter=root;
	int i;
	for(i=1;i<n;i++){
		t=(struct node *)malloc(sizeof(struct node));
		t->data=a[i];
		t->next=NULL;
		t->prev=iter;
		iter->next=t;
		iter=t;
	}
}

void display(){
	struct node *iter=root;
	while(iter){
		printf("%d ",iter->data);
		iter=iter->next;
	}
}

void deletee(int index){
	struct node *iter=root,*p;
	if(index<1 || index>9){
		printf("hatali index !!!");
		goto end;
	}
		
	if(index==1){
		if(iter->next){
			iter=iter->next;
			iter->prev=NULL;
			root=iter;
		}
		else{
			free(iter);
			root=NULL;
		}
	}
	else{
		int i;
		for(i=0;i<index-2;i++)
			iter=iter->next;
		p=iter->next;
		if(p->next){
			p->next->prev=iter;
		}
		iter->next=p->next;

		free(p);
	}
	end:printf("\n");
}


int main(int argc, char *argv[]) {
	int a[]={1,2,3,4,5,6,7,8,9};
	create(a,9);
	display();
	deletee(0);
	printf("\n");
	display();
	return 0;
}
