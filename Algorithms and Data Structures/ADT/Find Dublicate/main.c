#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a[]={1,1,2,3,4,5,5,6,8,8,8};
	int n=11;
	int i,j,lastDublicate=-1;
	for(i=0;i<n;i++){
		if(lastDublicate!=a[i] && a[i]==a[i+1]){
			lastDublicate=a[i];
			j=i+1;
			while(lastDublicate==a[j]){
				j++;
			}
			printf("%d %d times repeated\n",a[i],j-i);
		}
	}
	return 0;
}
