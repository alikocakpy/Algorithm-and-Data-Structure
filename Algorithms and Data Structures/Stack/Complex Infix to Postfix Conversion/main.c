#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack{
	int size;
	int top;
	char *s;
}st;

int isOperand(char c){
	if(c=='+' || c=='-' ||c=='*' ||c=='/' ||c==')' ||c=='(' || c=='^')
		return 0;
	else
		return 1;
}

int pre(char c){
	if(c=='-' || c=='+')
		return 1;
	else if(c=='*' || c=='/')
		return 3;
	else if(c=='^')
		return 6;
	else if(c=='(')
		return 7;
	else if(c==')')
		return 0;
	else
		return 0;
}

int preStk(char c){
	if(c=='-' || c=='+')
		return 2;
	else if(c=='*' || c=='/')
		return 4;
	else if(c=='^')
		return 5;
	else if(c=='(')
		return 0;
	else
		return 0;
}

int push(char c){
	st.s[++st.top]=c;
}

int pop(){
	return st.s[st.top--];
}

int convert(char infix[]){
	int i=0,j=0;
	char *postfix=(char *)malloc(sizeof(char)*(st.size+1));
	while(infix[i]!='\0'){
		if(isOperand(infix[i])){
			postfix[j++]=infix[i++];
		}
		else{
			if(pre(infix[i])>preStk(st.s[st.top])){
				push(infix[i++]);
			}
			else{
				if(infix[i]==')' && st.s[st.top]=='('){
					pop();
					i++;
				}
				else{
					postfix[j++]=pop();
				}
			}
		}
	}
	while(st.top!=-1)
		postfix[j++]=pop();
	postfix[j]='\0';
	printf("%s",postfix);
}


int main(){
	char *infix="(a+b)*c-d^e^f";
	st.size=strlen(infix);
	st.top=-1;
	st.s=(char *)malloc(sizeof(char )*st.size);
	convert(infix);
	return 0;
}
