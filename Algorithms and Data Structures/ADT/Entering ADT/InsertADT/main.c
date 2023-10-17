#include <stdio.h>
#include <stdlib.h>

struct array{
	int *A;
	int size;
	int length;
};

void insert(struct array *arr,int index,int x){
	int i;
	if(index>=0 && index <= arr->length){
		for(i=arr->length;i>index;i--)
			arr->A[i]=arr->A[i-1];
		arr->A[index]=x;
		arr->length++;
	}
}

int main(int argc, char *argv[]) {
	struct array arr;
	printf("enter size of array");
	scanf("%d",&arr.size);
	arr.A=(int *) malloc(sizeof(int));
	int i,n;
	printf("enter number of elements :");
	scanf("%d",&n);
	arr.length=n;
	for(i=0;i<n;i++)
		scanf("%d",&arr.A[i]);
		
	insert(&arr,3,10);
	
	for(i=0;i<arr.length;i++)
		printf("%d ",arr.A[i]);
	

		
	return 0;
}
