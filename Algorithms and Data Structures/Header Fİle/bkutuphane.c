#include <stdio.h>
#include <stdlib.h>
#include "bkutuphane.h"

struct array *merge(struct array *arr1,struct array *arr2){
	int i,j,k;
	i=j=k=0;
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
	return arr3;
}
