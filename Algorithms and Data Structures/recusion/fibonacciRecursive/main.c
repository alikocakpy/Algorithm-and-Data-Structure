#include <stdio.h>
#include <stdlib.h>

int f[5];


int fib(int n){
	if(n<=1){
		return n;
	}
	return fib(n-1)+fib(n-2);
}

/*we create for this an array for doesnt repeat same operation*/
/*This is more ifficent than before*/
int fibo(int n){
	if(n<=1){
		f[n]=n;
		return n;
	}
	else{
		if(f[n-2]==-1)
			f[n-2]=fibo(n-2);
		if(f[n-1]==-1)
			f[n-1]=fibo(n-1);
		return f[n-2]+f[n-1];
	}
}

int main(){
	int a=fib(6);
	printf("%d ",a);
	f[0]=-1;
	f[1]=-1;
	f[2]=-1;
	f[3]=-1;
	f[4]=-1;
	int b=fibo(5);
	printf("%d",b);
}
