#include <stdio.h>
#include <stdlib.h>

int find(int c[],int size){
	int i,max=0;
	for(i=0;i<size;i++){
		if(max<c[i])
			max=c[i];
	}
	return max;
}


int main(int argc, char *argv[]) {
	int c[]={25,6,9,14,37,6,3,2,19,3,6,5};
	
	int max=find(c,sizeof(c)/sizeof(c[0]));
	
	int *a=(int *) malloc(sizeof(int)*(max+1));
	
	int i;
	for(i=0;i<max+1;i++)
		a[i]=0;
	
	for(i=0;i<sizeof(c)/sizeof(c[0]);i++)
		a[c[i]]++;
	i=0;
	int j=0;
	while(i<max+1){
		if(a[i]>0){
			c[j++]=i;
			a[i]--;
		}
		else
			i++;
		
	}
	
	for(i=0;i<sizeof(c)/sizeof(c[0]);i++)
		printf("%d ",c[i]);
	
	return 0;
}
