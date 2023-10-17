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

char *convert(char infix[]){
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
	return postfix;
}

int Eval(char postfix[]){
	int i,x1,x2,r;
	for(i=0;postfix[i]!='\0';i++){
		if(isOperand(postfix[i])){
			push(postfix[i]-'0');
		}
		else{
			x2=pop();
			x1=pop();
			switch(postfix[i]){
				case '+': r=x1+x2;break;
				case '-': r=x1-x2;break;
				case '*': r=x1*x2;break;
				case '/': r=x1/x2;break;
				default: printf("hata var");
			}
			push(r);
		}
	}
	
	return pop();
}

int main(){
	char *infix="9/3+6*2-5";
	char *postfix;
	st.size=strlen(infix);
	st.top=-1;
	st.s=(char *)malloc(sizeof(char )*st.size);
	postfix=convert(infix);
	printf("%s",postfix);
	int x=Eval(postfix);
	printf("\nResult: %d",x);
	return 0;
}
