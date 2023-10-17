#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
//	int a[4][3]={{1,2,3,4},{5,6,7,8},{9,10,11,14}};
	/*int *a[3];
	a[0]=(int *) malloc(4*sizeof(int));
	a[1]=(int *) malloc(4*sizeof(int));
	a[2]=(int *) malloc(4*sizeof(int));*/
	
	//double pointer
	int **a;
	a=(int **) malloc(3*sizeof(int *));
	a[0]=(int *) malloc(4*sizeof(int));
	a[1]=(int *) malloc(4*sizeof(int));
	a[2]=(int *) malloc(4*sizeof(int));
	a[0][3]=142;
	int i,j;
	for(i=0;i<3;i++){
		for(j=0;j<4;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
