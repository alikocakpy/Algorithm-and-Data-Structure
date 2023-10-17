#include <stdio.h>
#include <stdlib.h>

void merge(int a[],int l,int m,int h){
	int i=l,j=m+1,k=l;
	int b[20];
	while(i<=m && j<=h){
		if(a[i]<a[j])
			b[k++]=a[i++];
		else if(a[i]>a[j])
			b[k++]=a[j++];
		else{
			b[k++]=a[i++];
			j++;
		}
	}
	for(;i<=m;i++)
		b[k++]=a[i++];
	for(;j<=h;j++)
		b[k++]=a[j++];
	
	for(i=l;i<=h;i++)
		a[i]=b[i];
	
}

void Rmerge(int a[],int l,int h){
	int mid;
	if(l<h){
		mid=(l+h)/2;
		Rmerge(a,l,mid);
		Rmerge(a,mid+1,h);
		merge(a,l,mid,h);
	}
}


int main(int argc, char *argv[]) {
	
	int a[]={5,3,7,9,1,6,8,2};
	
	Rmerge(a,0,sizeof(a)/sizeof(a[0]));
	
	int i;
	for(i=0;i<8;i++)
		printf("%d ",a[i]);
	
	return 0;
}
