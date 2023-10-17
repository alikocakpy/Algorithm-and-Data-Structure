#include <stdio.h>
#include <stdlib.h>

struct array{
	int *A;
	int size;
	int length;
};


int delete(struct array *arr,int index){
	if(index>=0 && index<arr->length){
		int i,x;
		x=arr->A[index];
		for(i=index;i<arr->length-1;i++){
			arr->A[i]=arr->A[i+1];
		}
		arr->length--;
		return x;
	}
	
	return 0;
}


int main(int argc, char *argv[]) {
	struct array arr;
	printf("Entering size of array :");
	scanf("%d",&arr.size);
	arr.A=(int *) malloc(arr.size*sizeof(int));
	int i,n;
	printf("Enter number of elements :");
	scanf("%d",&n);
	arr.length=n;
	printf("Enter all elements :\n");
	for(i=0;i<n;i++)
		scanf("%d",&arr.A[i]);
	
	printf("deleted valude :%d \n",delete(&arr,3));
	
	for(i=0;i<arr.length;i++){
		printf("%d",arr.A[i]);
	}
	return 0;
}
