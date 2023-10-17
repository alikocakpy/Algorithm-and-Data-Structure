#include <stdio.h>
#include <stdlib.h>

void prmt(char s[],int k){
	static int a[10]={0};
	static char res[10];
	int i;
	if(s[k]=='\0'){
		res[k]='\0';
		printf("%s\n",res);
	}
	else{
		for(i=0;s[i]!='\0';i++){
			if(a[i]==0){
				res[k]=s[i];
				a[i]=1;
				prmt(s,k+1);
				a[i]=0;
			}
		}
	}
}

int main(int argc, char *argv[]) {
	char s[]="ABC";
	int k=0;
	prmt(s,k);
	return 0;
}



//methpd swap

/*
void swap(char *x,char *y){
	char t;
	t=*x;
	*x=*y;
	*y=t;
}

void perm(char s[],int l,int h){
	int i;
	if(l==h)
		printf("%s\n",s);
	
	else{
		for(i=l;i<=h;i++){
			swap(&s[l],&s[i]);
			perm(s,l+1,h);
			swap(&s[l],&s[i]);
		}
	}
}


int main(){
	char s[]="abc";
	perm(s,0,2);
	return 0;
}

*/
