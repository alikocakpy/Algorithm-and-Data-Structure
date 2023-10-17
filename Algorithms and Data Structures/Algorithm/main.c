#include <stdio.h>
#include <stdlib.h>


void atama(int dizi[4][4]){
	int i,j;
	for(i = 1; i<4;i++){
		for(j = i+1; j<=4;j++){
			dizi[i][j]=i+j;
			dizi[j][i]=j+i;
		}
	}
}

int main(int argc, char *argv[]) {
	int dizi[4][4];
	atama(dizi);
	
	int toplam =0,counter = 0;
	int i,j;
	for(i=1;i<4;i++){
		for(j=i+1;j<=4;j++){
			toplam = dizi[i][j]+dizi[j][i];
			printf("%d %d = %d \n",i,j,dizi[i][j]+dizi[j][i]);
			counter++;
		}
	}
	
	printf("\n%d\n",counter);
	
	
	
	return 0;
}
