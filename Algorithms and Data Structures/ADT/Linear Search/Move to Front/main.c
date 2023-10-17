#include <stdio.h>
#include <stdlib.h>

//linear Search Move to Head/Front

struct array{
	int a[10];
	int size;
	int length;
};


void swap(int *x,int *y){
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}

int search(struct array *arr,int key){
	if(arr->length<arr->size){
		int i;
		for(i=0;i<arr->length;i++){
			if(key==arr->a[i]){
				swap(&arr->a[i],&arr->a[0]);
			return 0;
			}
			
		}
	}
	return -1;
}

int main(int argc, char *argv[]) {
	struct array arr={{5,6,7,8,9,1,2,3},10,8};
	
	printf("%d. index \n",search(&arr,2));
	
	int i;
	for(i=0;i<arr.length;i++){
		printf("%d ",arr.a[i]);
	}
	
	return 0;
}
