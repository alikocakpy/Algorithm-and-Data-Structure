#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	//hastable
	
	char a[]="python";
	char b[10];
	int i,j;
	
	for(i=0;a[i]!='\0';i++){
	}
	i--;
	for(j=0;i>=0;j++,i--){
		b[j]=a[i];
	}
	b[j]='\0';
	printf("%s\n",b);
	
	
	//swap char
	i=0,j=0;
	for(i=0;a[i]!='\0';i++){
	}
	i--;
	char t;
	for(j=0;j<i;j++,i--){
		t=a[i];
		a[i]=a[j];
		a[j]=t;
	}
	printf("%s\n",a);
	
	
	
	
	i=0,j=0;
	for(i=0;a[i]!='\0';i++){
	}
	i--;
	t;
	for(j=0;j<i;j++,i--){
		t=a[i];
		a[i]=a[j];
		a[j]=t;
	}
	printf("%s",a);
	return 0;
}
