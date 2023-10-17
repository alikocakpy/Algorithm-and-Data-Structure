#include <stdio.h>
#include <stdlib.h>

int sum(int n){
	if(n==0){
		return 0;
	}
	else
		return sum(n-1)+n;
}



int main(int argc, char *argv[]) {
	int a=sum(5);
	printf("%d",a);
	return 0;
}
