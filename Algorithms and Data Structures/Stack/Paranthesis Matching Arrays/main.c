#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
	int size;
	int top;
	char *s;
}st;

int push(char c){
	if(st.top==st.size)
		return -1;
	else{
		st.s[++st.top];
	}
}

int pop(){
	if(st.top==-1)
		return -1;
	else
		st.s[--st.top];
	
}

int isEmpty(){
	if(st.top==-1)
		return 1;
	else
		return 0;
}


int main(int argc, char *argv[]) {
//	char a[]={'(','(','a','+','b',')','*','(','c','-','d',')',')'};	//method 1
	char *a="((a+b)*(c-d))";		//method 2
	st.size=strlen(a);
	st.s=(char *)malloc(sizeof(char)*st.size);
	st.top=-1;
	int i;
	
	for(i=0;i<st.size;i++){
		if(a[i]=='(')
			push(a[i]);
		else if(a[i]==')'){
			if(isEmpty()){
				printf("hata!!!");
				return 0;
			}
			pop();
		}
	}
	isEmpty()?printf("dogru"):printf("hatali");
	return 0;
}
