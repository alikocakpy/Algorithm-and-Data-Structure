#include <stdio.h>
#include <stdlib.h>

int getMax(int a[],int n){
	int i,max=0;
	for(i=0;i<n;i++){
		if(max<a[i])
			max=a[i];
	}
	return max;
}

void count(int a[],int n,int exp){
	int output[n],count[10]={0},i;
	
	for(i=0;i<n;i++)
		count[(a[i]/exp)%10]++;
	
	for(i=1;i<10;i++)
		count[i]+= count[i-1];
	
	for(i=n-1;i>=0;i--){
		output[count[(a[i]/exp)%10]-1]=a[i];
		count[(a[i]/exp)%10]--;
	}
	
	for(i=0;i<n;i++){
		a[i]=output[i];
	}
}

int radix(int a[],int n){
	int m=getMax(a,n);
	
	int i;
	for(i=1;i<m;i*=10)
		count(a,n,i);
	
}

void prnt(int a[],int n){
	int i;
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
}

int main(int argc, char *argv[]) {
	
	int a[]={251,365,245,312,652,23,14,85,96,75};
	int n=sizeof(a)/sizeof(a[0]);
	
	radix(a,n);
	prnt(a,n);
	
	return 0;
}
