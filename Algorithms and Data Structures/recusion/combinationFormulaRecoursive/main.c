#include <stdio.h>
#include <stdlib.h>

int c(int n,int r){
	if(n==r || r==0){
		return 1;
	}
	else
		return c(n-1,r-1)+c(n-1,r);
}

/*This is anothor way to find the result*/
int control(int n){
	if(n<=1)
		return 1;
	return control(n-1)*n;
}

int com(int n,int r){
	int fact=0;
	int asd=0;
	
	fact=control(n);
	asd=control(r)*control(n-r);
	
	return fact/asd;
}

int main(int argc, char *argv[]) {
	printf("%d",c(6,3));
	
	
	printf(" %d",com(8,3));
	
	
	return 0;
}
