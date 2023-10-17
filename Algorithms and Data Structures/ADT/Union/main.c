#include <stdio.h>
#include <stdlib.h>

struct array{
	int a[10];
	int size;
	int length;
};


struct array *Union(struct array *arr1,struct array *arr2){
	int i,j,k;
	i=j=k=0;
	struct array *arr3=(struct array *)malloc(sizeof(struct array));
	
	while(i<arr1->length && j<arr2->length){
		if(arr1->a[i]<arr2->a[j])
			arr3->a[k++]=arr1->a[i++];
		else if(arr1->a[i]>arr2->a[j])
			arr3->a[k++]=arr2->a[j++];
		else{
			arr3->a[k++]=arr1->a[i++];
			j++;
		}
			
	}
	for(;i<arr1->a[i];)
		arr3->a[k++]=arr1->a[i++];
	for(;j<arr2->a[j];)
		arr3->a[k++]=arr2->a[j++];
		
	arr3->length=k;
	arr3->size=arr1->size;
	return arr3;
}

struct array *interSection(struct array *arr1,struct array *arr2){
	int i,j,k;
	i=j=k=0;
	struct array *arr3=(struct array *)malloc(sizeof(struct array));
	
	while(i<arr1->length && j<arr2->length){
		if(arr1->a[i]<arr2->a[j])
			i++;
		else if(arr1->a[i]>arr2->a[j])
			j++;
		else{
			arr3->a[k++]=arr1->a[i++];
			j++;
		}
			
	}
	arr3->length=k;
	arr3->size=arr1->size;
	return arr3;
}

struct array *difference(struct array *arr1,struct array *arr2){
	int i,j,k;
	i=j=k=0;
	struct array *arr3=(struct array *)malloc(sizeof(struct array));
	
	while(i<arr1->length && j<arr2->length){
		if(arr1->a[i]<arr2->a[j])
			arr3->a[k++]=arr1->a[i++];
		else if(arr1->a[i]>arr2->a[j])
			j++;
		else{
			i++;
			j++;
		}
			
	}
	for(;i<arr1->a[i];)
		arr3->a[k++]=arr1->a[i++];
		
	arr3->length=k;
	arr3->size=arr1->size;
	return arr3;
}


int main(int argc, char *argv[]) {
	struct array arr1={{5,13,14,14,15},10,4};
	struct array arr2={{5,12,14,36},10,4};
	struct array *arr3;
	
	arr3=Union(&arr1,&arr2);
	
	int i;
	for(i=0;i<arr3->length;i++)
		printf("%d ",arr3->a[i]);
	
	printf("\n");
	
	arr3=interSection(&arr1,&arr2);
	for(i=0;i<arr3->length;i++)
		printf("%d ",arr3->a[i]);
		
	printf("\n");
	
	arr3=difference(&arr1,&arr2);
	for(i=0;i<arr3->length;i++)
		printf("%d ",arr3->a[i]);
	
	free(arr3);
	return 0;
}
