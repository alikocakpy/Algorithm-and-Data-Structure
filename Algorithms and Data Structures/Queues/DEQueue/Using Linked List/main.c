#include <stdio.h>
#include <stdlib.h>

struct queue{
	int data;
	struct queue *next;
}*root=NULL,*last=NULL;

typedef struct queue que;
que * qu;

/* THis Ýs and DEQueue using array method belong me I create */

int enqueue(int x){
	int secim;
	printf("front or rear ?[1/2]]");
	scanf("%d",&secim);
	if(secim ==1){
		que *t;
		t=(que *)malloc(sizeof(que));
		if(t==NULL){
			printf("Memory is full");
			return -1;
		}
		else{
			if(root==NULL){
				t->data=x;
				t->next=NULL;
				last=root=t;
			}
			else{
				t->data=x;
				t->next=root;
				root=t;
				
			}
		}
		
	}
	else if(secim ==2){
		que *t;
		t=(que *)malloc(sizeof(que));
		if(t==NULL){
			printf("Memory is full");
			return -1;
		}
		else{
			if(last==NULL){
				t->data=x;
				t->next=NULL;
				last=root=t;
			}
			else{
				t->data=x;
				t->next=NULL;
				last->next=t;
				last=t;	
			}
			
		}
	}
	else{
		printf("hata!!!");
		return 0;
	}
}

int dequeue(){
	int secim;
	printf("front or rear ?[1/2]]");
	scanf("%d",&secim);
	que *t=NULL;
	if(secim==1){
		t=root;
		root=root->next;
		printf("%d deleted \n",t->data);
		free(t);
	}
	else if(secim==2){
		t=root;
		while(t->next!=last)
			t=t->next;
		printf("%d deleted \n",last->data);
		free(last);
		last=t;
		last->next=NULL;
	}
	else{
		printf("hata var");
		return -1;
	}
}

void display(){
	que *iter=root;
	while(iter){
		printf("%d \n",iter->data);
		iter=iter->next;
	}
	
}



int main(int argc, char *argv[]) {
	enqueue(30);
	enqueue(2);
	enqueue(60);
	enqueue(10);
	enqueue(90);
	enqueue(3);
	enqueue(333);
	display();
	dequeue();
	dequeue();
	dequeue();
	dequeue();
	display();
	enqueue(36);
	enqueue(6);
	enqueue(85);
	display();
	return 0;
}
