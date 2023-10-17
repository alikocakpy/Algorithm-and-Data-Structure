#include <stdio.h>
#include <stdlib.h>

int find(int key){
	return key%10;
}

int freeSpace(int h[],int key,int i){
	int j=0;
	int h2=7-(key%7);
	while(h[(i+j*h2)%10]!=0){
		j++;
	}
	
	return (i+j*h2)%10;
}

void insert(int h[],int key){
	int idx=find(key);
	
	if(h[idx]!=0){
		idx=freeSpace(h,key,idx);	
	}
	
	h[idx]=key;
	
}

int search(int h[],int key){
	int i=find(key);
	int j=0;
	int h2=7-(key%7);
	while(h[(i+j*h2)%10]!=key){
		j++;
		if(h[(i+j*h2)%10]==0){
			return -1;
		}
	}
	
	return (i+j*h2)%10;
	
}

int main(int argc, char *argv[]) {
	int h[10]={0};
	insert(h,15);
	insert(h,25);
	insert(h,16);
	insert(h,62);
	insert(h,45);
	
	int i;
	for(i=0;i<10;i++)
		printf("%d ",h[i]);
	
	int idx=search(h,26);
	printf("\n");
	if(idx==-1)
		printf("value is not valid");
	else
		printf("%d valid and stay %d. index",h[idx],idx);
	
	return 0;
}
