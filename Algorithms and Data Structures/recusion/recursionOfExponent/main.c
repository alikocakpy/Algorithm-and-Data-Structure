#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int asd(int m,int n){
	if(n==0)
		return 1;
	else
		return pow(m,n-1)*m;
}

int power(int m,int n){
	if(n==0){
		return 1;
	}
	if(n%2==0){
		return power(m*m,n/2);
	}
	else
		return m*power(m*m,(n-1)/2);
}

int main(int argc, char *argv[]) {
	int n= asd(2,9);
	printf("%d ",n);
	
	//this recursive function will be very useful and strong 2^8 == (2*2)^4
	printf("jsdgjdsf");
	int m=power(2,9);
	printf("%d",m);
	
	return 0;
}
