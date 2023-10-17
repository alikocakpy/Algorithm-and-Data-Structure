#include <stdio.h>
#include <stdlib.h>

int insert(int c[],int key){
	int temp,i;
	i=key;
	temp=c[i];
	while(i>0 && temp>c[i%2==0 ? (i/2)-1 : i/2]){
		c[i]=c[i%2==0 ? (i/2)-1 : i/2];
		i=i%2==0 ? (i/2)-1 : i/2;
	}
	c[i]=temp;
}

int create(int c[],int size){
	int i;
	for(i=0;i<=size;i++){
		insert(c,i);
	}
}

int insertA(int c[],int value,int size){
	int temp,i;
	i=size;
	temp=value;
	while(i>0 && temp>c[i%2==0 ? (i/2)-1 : i/2]){
		c[i]=c[i%2==0 ? (i/2)-1 : i/2];
		i=i%2==0 ? (i/2)-1 : i/2;
	}
	c[i]=temp;
}

int main(int argc, char *argv[]) {
	int heap[10]={54,36,12,98,25,96,6,8,85};
	create(heap,sizeof(heap)/sizeof(heap[0]));
	insertA(heap,76,9);
	int i=0;
	for(i;i<10;i++)
		printf("%d ",heap[i]);
	
	return 0;
}
