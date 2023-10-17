#include <stdio.h>
#include <stdlib.h>

struct array{
	int a[10];
	int size;
	int length;
};

// THÝS ÝS VERY ÝMPORTANT THÝNG YOU LOOK UNTÝL UNDERSTAND

//this
//if we want to return any value from functions we have to declare funcitons return value type!!!
struct array *merge(struct array *arr1,struct array *arr2){
	int i,j,k;
	i=j=k=0;
	//this
	struct array *arr3=(struct array *)malloc(sizeof(struct array));
	
	while(i<arr1->length && j<arr2->length){
		if(arr1->a[i]<arr2->a[j])
			arr3->a[k++]=arr1->a[i++];
		else
			arr3->a[k++]=arr2->a[j++];
	}
	for(;i<arr1->a[i];)
		arr3->a[k++]=arr1->a[i++];
	for(;i<arr2->a[j];)
		arr3->a[k++]=arr2->a[j++];
		
	arr3->length=arr1->length + arr2->length;
	arr3->size=arr1->size;
	//this
	return arr3;
}


int main(int argc, char *argv[]) {
	struct array arr1={{2,4,6,8},10,4};
	struct array arr2={{1,3,5,7},10,4};
	struct array *arr3;
	
	//and this
	arr3=merge(&arr1,&arr2);
	
	int i;
	for(i=0;i<arr3->length;i++)
		printf("%d ",arr3->a[i]);
	
	
	
	
	free(arr3);
	return 0;
}

