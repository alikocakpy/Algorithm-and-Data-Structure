#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a[]={1,3,4,6,7,8,9,10,12,14};
	int i,j,k=10;
	for(i=0;i<k-1;i++){
		for(j=i+1;j<k;j++){
			if(a[i]+a[j]==k){
				printf("%d+%d=%d \n",a[i],a[j],k);
			}
				
		}
	}
	printf("\n");
	
	//this method can make this because list is sorted
	
	i=0,j=10;
	while(i<j){
		if(a[i]+a[j]==k){
			printf("%d+%d=%d \n",a[i],a[j],k);
		}
		if(a[i]+a[j]<10)
			i++;
		else
			j--;
			
	}
	
	return 0;
}
