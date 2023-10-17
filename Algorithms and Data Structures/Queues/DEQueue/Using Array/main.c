#include <stdio.h>
#include <stdlib.h>

struct queue{
	int front;
	int rear;
	int size;
	int *q;
};

typedef struct queue que;
que qu;


int enqueue(int x,int index){
	if(index<1 || index>2){
		printf("hata!!!");
		return -1;
	}
	if(index==1 && qu.front>-1){
		qu.q[qu.front--]=x;
	}
	else if(index==2 && qu.front<qu.size){
		qu.q[qu.rear++]=x;
	}
	else{
		printf("hata var !!!");
	}
}

int dequeue(int x){
	if(x<1 || x>2){
		printf("hata!!!");
		return -1;
	}
	if(qu.front==qu.rear){
		printf("Memory is empty");
	}
	if(x==1){
		printf("%d deleted\n",qu.q[++qu.front]);
	}
	else if(x==2){
		printf("%d deleted\n",qu.q[--qu.rear]);
	}
	
}

void display(){
	int i=qu.front;
	while(i!=qu.rear){
		printf("%d \n",qu.q[i++]);
	}
	
}

int main(int argc, char *argv[]) {
	printf("enter the size:");
	scanf("%d",&qu.size);
	qu.rear=qu.front=0;
	qu.q=(int *)malloc(sizeof(int)*qu.size);
	
	
	enqueue(10,2);
	enqueue(20,2);
	enqueue(30,2);
	enqueue(40,2);
	enqueue(50,2);
	enqueue(60,2);
	dequeue(1);
	dequeue(2);
	enqueue(120,1);
	enqueue(413,2);
	enqueue(506,2);
	enqueue(40,2);
	enqueue(50,2);
	enqueue(60,2);
	dequeue(1);
	dequeue(2);
	dequeue(1);
	dequeue(2);
	display();
	
	return 0;
}
