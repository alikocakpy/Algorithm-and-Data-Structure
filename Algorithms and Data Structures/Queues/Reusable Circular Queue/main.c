#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct queue{
	int size;
	int front;
	int last;
	int *q;
};

typedef struct queue que;
que qu;
/*------Stack------*/

int enqueue(int x){
	if((qu.last+1)%qu.size==qu.front){
		printf("Stack full!!!");
		return -1;
	}
	else{
		qu.last=(qu.last+1)%qu.size;
		qu.q[qu.last]=x;
	}
}

int dequeue(){
	if(qu.last%qu.size==qu.front){
		printf("Memeory is Empty");
		return -1;
	}
	else{
		qu.front=(qu.front+1)%qu.size;
		printf("%d deleted \n",qu.q[qu.front]);
	}
}


void display(){
	int i=(qu.front+1)%qu.size;
	do{
		printf("%d \n",qu.q[i]);
		i=(i+1)%qu.size;
	}while(i!=(qu.last+1)%qu.size);
}

int main(){
	printf("Enter Size:");
	scanf("%d",&qu.size);
	qu.q=(int *)malloc(sizeof(int)*qu.size);
	qu.front=0;
	qu.last=0;
	enqueue(10);
	enqueue(20);
	enqueue(30);
	enqueue(40);
	enqueue(50);
	display();
	dequeue();
	dequeue();
	dequeue();
	enqueue(10);
	enqueue(20);
	enqueue(30);
	enqueue(40);
	enqueue(50);
	display();
}
 
