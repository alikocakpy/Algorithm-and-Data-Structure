#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a[]={6,7,9,10,14,15,16,17};
	int l,h,i=0;
	h=8;
	int dif=a[0]-i;
	for(i=0;i<h;i++){
		if(dif!=a[i]-i){
			while(dif!=a[i]-i){
				printf("%d missing\n",i+dif);
				dif++;
			}
		}
	}
	return 0;
}
