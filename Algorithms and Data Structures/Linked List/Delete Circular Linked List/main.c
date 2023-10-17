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
	last->next=root;
}

//This method is display the circular LOOP ->method 1

void display(){
	struct node *iter=root;
	do{
		printf("\n%d ",iter->data);
		iter=iter->next;
	}while(iter!=root);
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

int isLoop(){
	struct node *p,*q;
	p=q=root;
	do{
		p=p->next;
		q=q->next;
		q=q?q->next:NULL;
	}while(p && q && q!=p);
	
	if(p==q){
		return 1;
	}
	else{
		return 0;
	}
}

void deletee(int index){
	struct node *iter=root,*q;
	if(index==1){
		while(iter->next!=root)iter=iter->next;
		if(iter!=root){
			iter->next=root->next;
			free(root);
			root=iter->next;
		}
		else{
			free(root);
			root=NULL;
		}
	}
	else{
		int i;
		for(i=0;i<index-2;i++)iter=iter->next;
		q=iter->next;
		iter->next=q->next;
		free(q);
	}
}

int main(int argc, char *argv[]) {
	int a[]={4,5,8,10,16,25,28};
	struct node *p;
	create(a,7);
	display();
	if(isLoop()){
		printf("This is LOOP");
	}
	else{
		printf("This is not LOOP");
	}
	getch();
	deletee(3);
	display2(root); //if you active this code line program always write same value because we create a loop
	return 0;
}
