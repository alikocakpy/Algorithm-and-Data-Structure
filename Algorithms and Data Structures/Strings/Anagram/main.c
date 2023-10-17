#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char a[]="decimal";
	char b[]="medical";
	int i,h[26]={0};
	
	for(i=0;a[i]!='\0';i++){
		h[a[i]-97]+=1;
	}

	for(i=0;b[i]!='\0';i++){
		h[b[i]-97]-=1;
		if(h[b[i]-97]<0){
			printf("Not anagram");
			return 0;
		}
	}
	
	for(i=0;i<26;i++){
		if(h[i]>0 || h[i]<0){
			printf("this is not anagram\n");
			return 0;
		}
	}

	for(i=0;b[i]!='\0';i++){
	}
	
	if(b[i]=='\0')
		printf("it is anagram");
	
	
	return 0;
}
