#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	/*
	char a[]="finding";
	int b[26]={0};
	int i,j,count=1;
	for(i=0;a[i]!='\0';i++){
		for(j=i+1;a[j]!='\0';j++){
			if(a[i]==a[j]){
				count++;
			}
		}
		if(count>1)
			printf("%c repeat %d\n",a[i],count);
		count=1;
	}
	printf("\n\n");
	i=0,j=0;
	
	for(i=0;a[i]!='\0';i++){
		b[a[i]-97]++;
	}
	for(i=0;i<26;i++){
		if(b[i]>1){
			printf("\n%c repeat %d",i+97,b[i]);
		}
	}
	*/
	
	char a[]="AliKocak";
	
	int i,j,count=1;
	int b[26];
	
	
	
	for(i=0;i<26;i++){
		b[i]=0;
	}
	
	for(i=0;a[i]!='\0';i++){
		if(a[i]>=65 && a[i]<=90)
			b[a[i]-65]++;
		else if(a[i]>=97 && a[i]<=122)
			b[a[i]-97]++;
	}
	for(i=0;i<26;i++){
		if(b[i]>1){
			printf("%c repeat %d\n",(i+97),b[i]);
		}
	}
	printf("\n\n");
	for(i=0;a[i]!='\0';i++){
		for(j=i+1;a[j]!='\0';j++){
			if(a[i]!=-1){
				if(a[i]==a[j] || a[i]==a[j]+32 || a[i]==a[j]-32){
				a[j]=-1;
				count++;
				}
			}
		}
		if(count>1)
			printf("%c repeat %d\n",a[i],count);
		count=1;
	}
	
	
	
	
	return 0;
}
