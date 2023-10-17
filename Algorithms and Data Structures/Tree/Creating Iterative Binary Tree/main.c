#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include "stack.h"

struct node *root=NULL;

void createTree(){
	struct queue q;
	create(&q,25);
	
	struct node *t=NULL,*p=NULL;
	int x;
	
	printf("Enter the root data :");
	scanf("%d",&x);
	
	
	root=(struct node *)malloc(sizeof(struct node));
	root->lChild=root->rChild=NULL;
	root->data=x;
	
	enqueue(root,&q);
	
	while(!isEmpty(q)){
		p=dequeue(&q);
		printf("Enter the left child of %d :",p->data);
		scanf("%d",&x);
		if(x!=-1){
			t=(struct node *)malloc(sizeof(struct node));
			t->lChild=t->rChild=NULL;
			t->data=x;
			p->lChild=t;
			enqueue(t,&q);
		}
		printf("Enter the right child of %d :",p->data);
		scanf("%d",&x);
		if(x!=-1){
			t=(struct node *)malloc(sizeof(struct node));
			t->lChild=t->rChild=NULL;
			t->data=x;
			p->rChild=t;
			enqueue(t,&q);
		}
	}
}

void IPreOrder(struct node *p){
	struct stk st;
	createStk(&st,25);
	
	while(p || !isEmptyStk(st)){
		if(p){
			printf("%d ",p->data );
			push(&st,p);
			p=p->lChild;
		}
		else{
			p=pop(&st);
			p=p->rChild;
		}
	}
	
}


void IInOrder(struct node *p){
	struct stk st;
	createStk(&st,25);
	
	while(p || !isEmptyStk(st)){
		if(p){
			push(&st,p);
			p=p->lChild;
		}
		else{
			p=pop(&st);
			printf("%d ",p->data );
			p=p->rChild;
		}
	}
	
}


/*
Post order has complex structure. first of all adress can not be negative so we think unsigned variable. at this code block we send address value at stack but stack has keeping struct node *, and we send long int value(double value not accept by stack/push) 
so when we use function and send varieble or structure we pass the address so we dont different anything we use this method we send addres and push use unsigned value and when send back the adress send with signed so temp has value and its signed we made
type casting and we reached address's accessing variable doesnt diffrent anything.

but ý dont know every thing about this topic. maybe I doesnt know some imformation that's why more efficent and true way push and other funcitons at stack change according to temp's variable. I dont change this project becusouse this method work at here
as well as other way work but whis preorder and ýnorder have struct structure thats wyh ý dont change ý cover this way postorder.
*/


void IPostOrder(struct node *p){
	struct stk st;
	createStk(&st,25);
	int temp;
	while(p || !isEmptyStk(st)){
		if(p){
			push(&st,p);
			p=p->lChild;
		}
		else{
			temp=pop(&st);
			if(temp>0){
				push(&st,-temp);
				p=((struct node *)temp)->rChild;
			}
			else{
				printf("%d ",((struct node *)-temp)->data);
				p=NULL;
			}
		}
	}
	
}

int main(int argc, char *argv[]) {
	createTree();
	IPreOrder(root);
	printf("\n");
	IInOrder(root);
	printf("\n");
	IPostOrder(root);
	return 0;
}
