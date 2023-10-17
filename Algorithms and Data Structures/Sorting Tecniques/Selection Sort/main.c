#include <stdio.h>
#include <stdlib.h>

// Selection Sort is not Adaptive and Stable.

void selection(int a[],int size){
	int i,j,k,temp;
	for(i=0;i<size-1;i++){
		for(j=k=i;j<size;j++){
			if(a[k]>a[j])
				k=j;
		}
		temp=a[i];
		a[i]=a[k];
		a[k]=temp;
	}
}

int main(int argc, char *argv[]) {
	int a[]={6,9,7,3,1,0,2,4,8};
	selection(a,sizeof(a)/sizeof(a[0]));
	int i;
	for(i=0;i<8;i++)
		printf("%d ",a[i]);
	return 0;
}
