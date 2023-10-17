#include <stdio.h>
#include <stdlib.h>

int fact(int n){
	if(n==0){
		return 1;
	}
	else{
		return fact(n-1)*n;
	}
}


int main(int argc, char *argv[]) {
	int sonuc=fact(5);
	printf("%d",sonuc);
	return 0;
}
