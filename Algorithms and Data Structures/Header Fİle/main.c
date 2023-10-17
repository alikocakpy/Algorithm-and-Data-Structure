#include <stdio.h>
#include <stdlib.h>

#include "bkutuphane.h"


int main(int argc, char *argv[]) {
	struct array arr1={{2,4,6,8},10,4};
	struct array arr2={{1,3,5,7},10,4};
	struct array *arr3;
	
	arr3=merge(&arr1,&arr2);
	
	int i;
	for(i=0;i<arr3->length;i++)
		printf("%d ",arr3->a[i]);
	
	free(arr3);
	return 0;
}

