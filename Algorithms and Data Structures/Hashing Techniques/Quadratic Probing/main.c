#include <stdio.h>
#include <stdlib.h>

int take(int key){
	return key%10;
}

int freeSpace(int h[],int i){
	int j=0;
	while(h[(i+j*j)%10]!=0)
		j++;
	return (i+j*j)%10;
}

void insert(int h[],int key){
	int i=take(key);
	
	if(h[i]==0){
		h[i]=key;
	}
	else{
		int j=freeSpace(h,i);
		h[j]=key;
	}
	
}

int search(int h[],int key){
	int i=take(key);
	int j=0;
	while(h[(i+j*j)%10]!=key){
		j++;
		if( h[(i+j*j)%10]==0)
			return -1;
	}
		
	return (i+j*j)%10;
	
}

int main(int argc, char *argv[]) {
	int h[10]={0};
	insert(h,15);
	insert(h,25);
	insert(h,35);
	insert(h,75);
	insert(h,96);
	
	int i;
	for(i=0;i<10;i++)
		printf("%d ",h[i]);
	
	printf("\n");
	int data=search(h,75);
	if(data==-1)
		printf("data not valid");
	else
		printf("%d find %d. index",h[data],data);
	
	return 0;
}
