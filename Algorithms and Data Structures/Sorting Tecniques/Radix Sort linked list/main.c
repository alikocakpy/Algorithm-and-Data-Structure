#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node{
	int data;
	struct node *next;
};

int find(int a[],int n){
	int i;
	int max=0;
	for(i=0;i<n;i++){
		if(a[i]>max)
			max=a[i];
	}
	return max;
}

int get(int max){
	int i,exp=0;
	for(i=1;i<max;i=i*10)
		exp++;
	
	return exp;
}

void initileze(struct node **arr,int n){
	int i;
	for(i=0;i<n;i++)
		arr[i]=NULL;
}

int getNum(int x,int exp){
	return (int)(x/ pow(10,exp))%10;
}


void insert(struct node **arr,int value,int idx){
	struct node *t=(struct node *)malloc(sizeof(struct node));
	t->data=value;
	t->next=NULL;
	
	if(arr[idx]==NULL)
		arr[idx]=t;
	else{
		struct node *p=arr[idx];
		while(p->next!=NULL)
			p=p->next;
		p->next=t;
	}
	
}

int dlt(struct node **arr,int idx){
	struct node *p=arr[idx];
	arr[idx]=arr[idx]->next;
	int x=p->data;
	free(p);
	return x;
}

int radix(int a[],int n){
	int max=find(a,n);
	int passes=get(max);
	
	struct node **arr=(struct node **)malloc(sizeof(struct node *)*10);
	initileze(arr,10);
	
	int i,pass;
	for(pass=0;pass<passes;pass++){
		for(i=0;i<n;i++){
			int num = getNum(a[i],pass);
			insert(arr,a[i],num);
		}
		i=0;
		int j=0;
		while(i<10){
			while(arr[i] !=NULL){
				a[j++]=dlt(arr,i);
			}
			i++;
		}
	}
	
	free(arr);
	
}

void prin(int a[],int n){
	int i;
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
}

int main(int argc, char *argv[]) {
	
	int a[]={251,369,478,341,256,65,624,392,789,153};
	int size=sizeof(a)/sizeof(a[0]);
	
	radix(a,size);
	
	prin(a,size);
	
	return 0;
}
