#include <stdio.h>
#include <stdlib.h>

struct array{
	int *A;
	int size;
	int length;
};

void display(struct array arr){
	int i;
	printf("\nElements are \n");
	for(i=0;i<arr.length;i++){
		printf("%d",arr.A[i]);
	}
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
		
	display(arr);
	return 0;
}
