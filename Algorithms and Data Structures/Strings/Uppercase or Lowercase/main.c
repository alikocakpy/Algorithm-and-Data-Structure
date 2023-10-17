#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	char c[]="How are you";
	printf("%s\n",c);
	

	printf("enter a string\n");
	char a[20];
	gets(a);
	int secim;
	printf("1.Uppercase\n2.Lowercase\n");
	scanf("%d",&secim);
	int i=0;
	if(secim==1){
		while(a[i]!='\0'){
			printf("%c",a[i]-32);
			i++;
			
		}
	}
	else{
		while(a[i]!='\0'){
			printf("%c",a[i]+32);
			i++;
			
		}
	}
	
	
	printf("\n");
	fflush(stdin);
	char b[]="aliKO5ak";
	i=0;
	while(b[i]!='\0'){
		if(b[i]>='a' && b[i]<=122)
			b[i]-=32;
		else if(b[i]>=65 && b[i]<=90)
			b[i]+=32;
		
		i++;
	}
	printf("%s",b);
	
	
	
	return 0;
}
