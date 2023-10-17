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

void Imerge(int a[],int n){
	int p,l,h,m,i;
	for(p=2;p<=n;p=p*2){
		for(i=0;i+p-1<n;i=i+p){
			l=i;
			h=i+p-1;
			m=(h+l)/2;
			merge(a,l,m,h);
		}
	}
	if(p/2<n)
		merge(a,0,p/2-1,n-1);
}


int main(int argc, char *argv[]) {
	
	int a[]={5,3,7,9,1,6,8,2};
	
	Imerge(a,sizeof(a)/sizeof(a[0]));
	
	int i;
	for(i=0;i<8;i++)
		printf("%d ",a[i]);
	
	return 0;
}
