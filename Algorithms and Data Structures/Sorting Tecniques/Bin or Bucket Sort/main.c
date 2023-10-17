#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

int find(int a[],int n){
	int i;
	int max=0;
	for(i=0;i<n;i++){
		if(max<a[i])
			max=a[i];
	}
		
	
	return max;
}


void initilize(struct node **arr,int max){
	int i;
	for(i=0;i<max;i++)
		arr[i]=NULL;
}

void insert(struct node **arr,int value){
	struct node *t;
	t=(struct node *)malloc(sizeof(struct node));
	t->data=value;
	t->next=NULL;
	
	if(arr[value]==NULL)
		arr[value]=t;
	else{
		struct node *p=arr[value];
		while(p->next)
			p=p->next;
		p->next=t;
	}
		
}

int dlt(struct node **arr,int max){
	struct node *p;
	int i=0;
	while(i<max)
	{
		if(arr[i]!=NULL){
			p=arr[i];
			arr[i]=arr[i]->next;
			int x=p->data;
			free(p);
			return x;
		}
		else{
			i++;
		}
	}
}

void binSort(int a[],int n){
	int max=find(a,n);
	
	struct node **arr=(struct node **)malloc(sizeof(struct node*)*(max+1));
	initilize(arr,max+1);
	
	int i;
	for(i=0;i<n;i++)
		insert(arr,a[i]);
	for(i=0;i<n;i++)
		a[i]=dlt(arr,max+1);
	
	free(arr);
	
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
		
}


int main(){
	int a[]={1,5,6,3,4,7,9,2,5,8,6,4,3,5,7};
	int n=sizeof(a)/sizeof(a[0]);
	
	binSort(a,n);
}
