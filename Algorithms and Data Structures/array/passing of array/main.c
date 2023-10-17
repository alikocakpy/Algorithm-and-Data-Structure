#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a[5];
	int *p;
	p=(int *) malloc(5*sizeof(int));
	free(p);
	return 0;
}
