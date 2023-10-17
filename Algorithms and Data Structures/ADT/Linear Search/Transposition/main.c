#include <stdio.h>
#include <stdlib.h>

//Linear Search Method of Transposition

struct arr{
	int *a;
	int length;
	int size;
};

//in here I swap the searching number and before so I faster program each searching time.
void swap(struct arr *a,int i){
	int temp;
	temp=a->a[i];
	a->a[i]=a->a[i-1];
	a->a[i-1]=temp;
}

int search(struct arr *a,int key){
	int i;
	if(a->length<a->size)	{
		for(i=0;i<a->length;i++){
			if(key==a->a[i]){
				swap(a,i);
				return i-1;
			}
		}
	}
	return -1;
}

int main(int argc, char *argv[]) {
	struct arr ar;
	ar.size=10;
	ar.a=(int *) malloc(ar.size*sizeof(int));
	ar.length=8;
	
	int i;
	for(i=0;i<ar.length;i++){
		scanf("%d",&ar.a[i]);
	}
	
	int b=search(&ar,4);
	
	printf("%d by store %d. index",ar.a[b],b);
	
	
	for(i=0;i<ar.length;i++){
		printf("%d ",ar.a[i]);
	}
	
	return 0;
}
