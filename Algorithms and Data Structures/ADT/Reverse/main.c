#include <stdio.h>
#include <stdlib.h>

struct array{
	int *a;
	int size;
	int length;
};

void display(struct array arr){
	int i;
	for(i=0;i<arr.length;i++){
		printf("%d ",arr.a[i]);
	}
}

void reverse(struct array *arr,int length){
	int *b;
	b=(int *) malloc(length*sizeof(int));
	int i,j;
	for(i=length-1,j=0;i>=0;i--,j++){
		b[j]=arr->a[i];
	}
	
	for(i=0;i<length;i++){
		arr->a[i]=b[i];
	}
}


void reverse2(struct array *arr){
	int i,j,temp;
	for(i=0,j=arr->length-1;i<j;i++,j--){
		temp=arr->a[i];
		arr->a[i]=arr->a[j];
		arr->a[j]=temp;
	}
}

int main(int argc, char *argv[]) {
	struct array arr;
	arr.size=10;
	arr.length=10;
	int i;
	arr.a=(int *) malloc(sizeof(int) * arr.length);
	for(i=0;i<arr.length;i++){
		arr.a[i]=i;
	}
	
	reverse(&arr,arr.length);
	display(arr);
	
	printf("\n");
	
	reverse2(&arr);
	display(arr);
	return 0;
}
