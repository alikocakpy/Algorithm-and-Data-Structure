#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack{
	int size;
	int top;
	char *s;
}st;

int isOperand(char c){
	if(c=='+' || c=='-' ||c=='/' || c=='*')
		return 0;
	else 
		return 1;
}

int pre(char c){
	if(c=='+' || c=='-')
		return 1;
	else if(c=='/' || c=='*')
		return 2;
	else
		return 0;
}

void push(char c){
	st.s[++st.top]=c;
}

char pop(){
	char c=st.s[st.top--];
	return c;
}

isEmpty(){
	if(st.top==-1)
		return 1;
	else
		return 0;
}


void convert(char infix[]){
	char *postfix=(char *)malloc(sizeof(char)*st.size+1);
	int i=0,j=0;
	while(infix[i]!='\0'){
		if(isOperand(infix[i])){
			postfix[j++]=infix[i++];
		}
		else{
			if(pre(infix[i])>pre(st.s[st.top])){
				push(infix[i++]);
			}
			else{
				postfix[j++]=pop();
			}
		}
	}
	while(!isEmpty()){
		postfix[j++]=pop();
	}
	postfix[j]='\0';
	
	printf("%s",postfix);
}


int main(int argc, char *argv[]) {
	char *infix="a+b*c-d/e-p*g";
	st.size=strlen(infix);
	st.top=-1;
	st.s=(char *)malloc(sizeof(char)*(st.size));
	convert(infix);
	
	return 0;
}
