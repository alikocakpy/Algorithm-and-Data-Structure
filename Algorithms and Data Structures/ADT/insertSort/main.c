#include <stdio.h>
#include <stdlib.h>

struct array{
	int a[10];
	int length;
	int size;
};

int insertSort(struct array *arr,int x){
	int i=arr->length-1;
	if(arr->length == arr->size)
		return;
	while(i>=0 && arr->a[i]>x){
		arr->a[i+1]=arr->a[i];
		i--;
	}
	arr->a[i+1]=x;
	arr->length++;
}

int main(int argc, char *argv[]) {
	struct array arr={{2,3,7,8,9,10,12,35,46},9};
	
	insertSort(&arr,23);
	
	int i;
	for(i=0;i<arr.length;i++)
		printf("%d ",arr.a[i]);
	
	return 0;
}
