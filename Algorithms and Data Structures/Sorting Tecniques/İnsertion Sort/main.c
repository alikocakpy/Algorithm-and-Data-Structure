#include <stdio.h>
#include <stdlib.h>

//I want to give you idea for understand aim of code first you know this code what do you do
//after that you drow algorithm and formula of math later you already understand.
//last advice dont forgot to transform code Adaptive and Stable code 

//sorry but this is last this code more useful Linked list. designed for its.

int insertion(int a[],int size){
	int i,j,x;
	for(i=1;i<size;i++){
		j=i-1;
		x=a[i];
		while(j>-1 && a[j]>x){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=x;
	}
}

int main(int argc, char *argv[]) {
	int a[]={5,9,3,1,7,2,4,6,7};
	insertion(a,sizeof(a)/sizeof(a[0]));
	
	int i;
	for(i=0;i<sizeof(a)/sizeof(a[0]);i++)
		printf("%d ",a[i]);
	return 0;
}
