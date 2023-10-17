#include <stdio.h>
#include <stdlib.h>

struct array{
	int a[10];
	int size;
	int length;
};

//Binary Search 
//most important thing at binary search elements must already sorted
//and second important thing at recursive func. we have to use return otherwise func. use return -1;


int binarySearch(struct array arr,int key){
	int l,h,mid;
	l=0;
	h=arr.length-1;
	
	while(l<=h){
		mid=(l+h)/2;
		if(arr.a[mid]==key){
			return mid;
		}
		else if(arr.a[mid]>key){
			h=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	return -1;
	
}


int rbinary(int a[],int key,int l,int h){
	int mid;
	
	if(l<=h){
		mid=(l+h)/2;
		if(key==a[mid])
			return mid;
		else if(key<a[mid])
			return rbinary(a,key,l,mid-1);
		else
			return rbinary(a,key,mid+1,h);
	}
	return -1;
}



int main(int argc, char *argv[]) {
	struct array arr={{2,3,4,5,7,8,9},10,7};
	
	printf("%d",binarySearch(arr,7));
	
	printf("\n");
	
	printf("%d",rbinary(arr.a,8,0,arr.length));
	
	return 0;
}
