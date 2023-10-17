#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack{
	int *degree;
	int top;
	int size;
	char *s;
}pf;

int push(char a,int deg){
	if(pf.top==pf.size)
		return -1;
	else{
		if(deg>pf.degree[pf.top] || pf.top==-1){
			if(a=='+' || a=='-'){
			pf.s[++pf.top]=a;
			pf.degree[pf.top]=1;
			}
			else if(a=='*' || a=='/'){
				pf.s[++pf.top]=a;
				pf.degree[pf.top]=2;
			}
		}
		else{
			while(deg>pf.degree[pf.top] || pf.top!=-1){
				if(a=='+' || a=='-'){
					pop();
				}
				else if(a=='*' || a=='/'){
					pop();
				}
			}
			if(a=='+' || a=='-'){
			pf.s[++pf.top]=a;
			pf.degree[pf.top]=1;
			}
			else if(a=='*' || a=='/'){
				pf.s[++pf.top]=a;
				pf.degree[pf.top]=2;
			}
		}
	}
}

int pop(){
	if(pf.top==-1)
		return -1;
	printf("%c",pf.s[pf.top]);
	pf.s[pf.top]=0;
	pf.degree[pf.top--]=0;
}



int postfix(char a[]){
	int i;
	for(i=0;i<pf.size;i++){
		if(a[i]=='+' || a[i]=='-'){
			push(a[i],1);
		}
		else if(a[i]=='*' || a[i]=='/'){
			push(a[i],2);
		}
		else{
			printf("%c",a[i]);
		}
	}
	while(pf.top!=-1){
		pop();
	}
}

int main(int argc, char *argv[]) {
	char *c="a*b-d/e+f";
	pf.size=strlen(c);
	pf.s=(char *)malloc(sizeof(char)*pf.size);
	pf.degree=(int *)malloc(sizeof(int)*pf.size);
	pf.top=-1;
	postfix(c);
	return 0;
}
