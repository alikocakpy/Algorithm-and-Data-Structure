#include <stdio.h>
#include <stdlib.h>

/*
This code using huge array size.
code simple and effective nlogn. not use extra space change do it same array 
*/

int shell(int a[],int n){
	int i,j,temp,gap;
	for(gap=n/2;gap>=1;gap/=2){
		
		for(i=gap;i<n;i++){
			temp=a[i];
			j=i-gap;
			while(j>=0 && a[j]>temp){
				a[j+gap]=a[j];
				j=j-gap;
			}
			a[j+gap]=temp;
		}
	}
}

void prnt(int a[],int n){
	int i;
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
}

int main(int argc, char *argv[]) {
	int a[]={25,36,74,91,2,85,66,32,41,126,254,175};
	int n=sizeof(a)/sizeof(a[0]);
	shell(a,n);
	
	prnt(a,n);
	
	return 0;
}
