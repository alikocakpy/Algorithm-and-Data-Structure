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


void deletee(int c[],int n){
	int x,i,j;
	int temp;
	x=c[0];
	c[0]=c[n];
	
	i=0;
	j=1;
	while(j<n-1){
		if(c[j+1]>c[j])
			j=j+1;
		if(c[i]<c[j]){
			temp=c[i];
			c[i]=c[j];
			c[j]=temp;
			i=j;
			j=2*i+1;
		}
		else
			break;
		
	
	}
	c[n]=x;
}

int main(int argc, char *argv[]) {
	int heap[10]={54,36,12,98,25,96,6,8,85};
	create(heap,sizeof(heap)/sizeof(heap[0]));
	insertA(heap,76,9);
	int i=0;
	for(i;i<10;i++)
		printf("%d ",heap[i]);
	
	deletee(heap,9);
	deletee(heap,8);
	deletee(heap,7);
	deletee(heap,6);
	deletee(heap,5);
	i=0;
	printf("\n");
	for(i;i<10;i++)
		printf("%d ",heap[i]);
	return 0;
}
