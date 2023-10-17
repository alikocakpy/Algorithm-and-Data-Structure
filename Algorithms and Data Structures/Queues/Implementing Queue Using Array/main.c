#include <stdio.h>
#include <stdlib.h>

struct queue{
	int size;
	int front;
	int rear;
	int *q;
};

typedef struct queue que;
que qu;

void enqueue(int x){
	if(qu.rear==qu.size-1){
		printf("Memory is full!!!");
		return ;
	}
	qu.rear++;
	qu.q[qu.rear]=x;
}

void dequeue(){
	if(qu.front==qu.rear){
		printf("Memory is empty");
		return ;
	}
	qu.front++;
	printf("\n%d deleted ",qu.q[qu.front]);
	
}
//This is again using blank memory method
void check(){
	if(qu.rear==qu.front){
		qu.rear=qu.front=-1;
	}
	else if(qu.rear>qu.front){
		int i=qu.rear-qu.front;
		qu.rear=0;
		while(qu.rear<i){
			qu.rear++;
			qu.q[qu.rear]=qu.q[qu.front++];
		}
		qu.front=-1;
	}
}

void display(){
	int i=qu.front+1;
	while(i<=qu.rear)
		printf("\n%d ",qu.q[i++]);
}

int main(int argc, char *argv[]) {
	printf("Enter queue size:");
	scanf("%d",&qu.size);
	qu.q=(int *)malloc(sizeof(int)*(qu.size));
	qu.front=-1;
	qu.rear=-1;
	
	enqueue(15);
	enqueue(25);
	enqueue(19);
	enqueue(12);
	enqueue(18);
	enqueue(89);
	display();
	dequeue();
	dequeue();
	dequeue();
	dequeue();
	check();
	enqueue(98);
	enqueue(36);
	display();
	
	
	return 0;
}
