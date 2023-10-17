#include <stdio.h>
#include <stdlib.h>


void bubble(int a[],int size){
	int i=0,j=0,flag=0;
	int temp;
	for(i;i<size-1;i++){
		for(j=0;j<size-1-i;j++){
			if(a[j+1]<a[j]){
				temp=a[j+1];
				a[j+1]=a[j];
				a[j]=temp;
				flag=1;
			}
		}
		if(flag==0)
			break; //this control for check array already sorted or not so stop waste time
	}
	
}//and according to algorithm sutructure this build comply stable struct. so double value is sorted between itself

int main(int argc, char *argv[]) {
	
	int a[]={5,9,3,4,6,7,1,6,0};
	bubble(a,sizeof(a)/sizeof(a[0]));
	
	int i=0;
	for(i;i<sizeof(a)/sizeof(a[0]);i++)
		printf("%d ",a[i]);
	
	return 0;
}
