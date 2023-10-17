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

//This method is display the circular LOOP ->method 1

void display(){
	struct node *iter=root;
	while(iter){
		printf("%d ",iter->data);
		iter=iter->next;
	}
}

void display2(struct node *iter){
	static int counter=0;
	if(root!=iter ||counter==0){
		counter=1;
		printf("\n%d ",iter->data);
		display2(iter->next);
	}
	counter=0;
}


void middle(){
	struct node *p,*q;
	p=q=root;
	while(p){
		p=p->next;
		if(p){
			p=p->next;
			q=q->next;
		}
			
		
	}
	printf("middle of the array %d",q->data);
}


int main(int argc, char *argv[]) {
	int a[]={4,5,8,10,16,25,28};
	struct node *p;
	create(a,7);
	display();
	middle();
	
	return 0;
}
