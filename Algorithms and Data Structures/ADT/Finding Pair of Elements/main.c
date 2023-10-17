#include <stdio.h>
#include <stdlib.h>



int main(int argc, char *argv[]) {
	int a[10]={6,3,8,10,16,7,5,2,9,4};
	
	int i,j,choice;
	
	printf("Enter your choice\n1. Normal \n2. Hashing");
	scanf("%d",&choice);
	
	if(choice==1){
		for(i=0;i<9;i++){
			for(j=i+1;j<10;j++){
				if(a[i]+a[j]==10)
					printf("%d+%d=10\n",a[i],a[j]);
			}
		}
	}
	else if(choice==2){
		int b[17];
		for(i=0;i<17;i++){
			b[i]=0;
		}
		
		for(j=0;j<17;j++){
			if(b[10-a[j]]!=0  && a[j]<=10){
				printf("%d + %d = 10\n",a[j],10-a[j]);
			}
			b[a[j]]++;
		}
		
	}
	return 0;
}
