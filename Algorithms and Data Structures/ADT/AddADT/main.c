#include <stdio.h>
#include <stdlib.h>

struct array{
	int *A;
	int size;
	int length;
};

void add(struct array *arr,int n){
	if(arr->size > arr->length)
		arr->A[arr->length++]=n;
	//this statement increase length value after placement ++arr->length increase before and make execution
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
		
	add(&arr,10);
	
	for(i=0;i<arr.length;i++)
		printf("%d ",arr.A[i]);
	

		
	return 0;
}
