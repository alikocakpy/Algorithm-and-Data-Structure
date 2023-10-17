#include <stdio.h>
#include <stdlib.h>

int find(int x){
	return x%10;
}

int freeSpace(int h[],int key){
	int i=0;
	while(h[(key + i) % 10]!=0)
		i++;
	
	return (i+key)%10;
		
}

int insert(int h[],int key){
	int i=find(key);
	
	if(h[i]!=0){
		int area=freeSpace(h,i);
		h[area]=key;
	}
	else
		h[i]=key;	
	
}


int search(int h[],int key){
	int i=find(key);
	int j=0;
	while(h[(i+j)%10]!=key && h[(i+j)%10]!=0)
		j++;
	
	if(h[(i+j)%10]==key)
		return (i+j)%10;
	else
		return -1;
	
}

int main(int argc, char *argv[]) {
	
	int h[10]={0};
	
	insert(h,34);
	insert(h,45);
	insert(h,52);
	insert(h,65);
	
	int i=search(h,65);
	
	if(i<0)
		printf("error. number does not found");
	else
		printf("%d founded %d. find",h[i],i);
	
	return 0;
}
