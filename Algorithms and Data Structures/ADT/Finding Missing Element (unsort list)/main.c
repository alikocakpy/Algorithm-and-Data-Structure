#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a[]={2,7,9,4,1,6,10,12,11};
	int b[12]={0};
	int i,j=1;
	
	for(i=0;i<9;i++){
			b[a[i]]=1;
	}
	i=1;
	while(i<=12){
		if(b[i]!=1){
			printf("%d. indis eksiktir\n",i);
		}
		i++;
	}
		
	
	return 0;
}
