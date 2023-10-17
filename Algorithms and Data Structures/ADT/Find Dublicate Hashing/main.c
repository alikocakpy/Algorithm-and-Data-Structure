#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a[]={3,4,4,4,5,5,6,7,7,8};
	int b[9];
	int i=0;
	
	for(i=0;i<9;i++){
		b[i]=0;
	}
	for(i=0;i<9;i++){
		b[a[i]]++;
	}
	for(i=0;i<9;i++){
		if(b[i]>1){
			printf("%d times %d \n",b[i],i);
		}
	}
	
	return 0;
}
