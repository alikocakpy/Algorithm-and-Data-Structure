#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
	int a[]={8,5,6,7,5,3,6,5,8,5};
	int b[9]={0};
	int n=10,i,j,count,choice;
	
	//here more efficent method second method but I want to show both of and test myself.
	//note: be care second method because array size must be first arrays max value 
	
	
	printf("choose the solution way : 1/2");
	scanf("%d",&choice);
	if(choice==1){
		for(i=0;i<n-1;i++){
		count=1;
		if(a[i]!=-1){
			for(j=i+1;j<n;j++){
				if(a[i]==a[j]){
					count++;
					a[j]=-1;
				}
			}
			if(count>1)
				printf("%d times %d\n",count,a[i]);
			}
		}
	}
	else if(choice==2){
		for(i=0;i<n;i++){
			b[a[i]]++;
		}
		for(i=0;i<9;i++){
			if(b[i]>1){
				printf("%d times %d repeat\n",b[i],i);
			}
		}
	}
	else 
		printf("default situation");
	
	
	return 0;
}
