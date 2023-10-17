#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack{
	char data;
	struct stack *next;
};

typedef struct stack s;
s *root=NULL;
s *last=NULL;
/*------ Struct ------*/

int isOperand(char c){
	if(c=='+' || c=='-' || c=='*' || c=='/' || c=='(' || c==')' || c=='^')
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

char push(char x){
	s *t;
	t=(s *)malloc(sizeof(s));
	if(t==NULL){
		printf("Memory full");
		return ;
	}
	t->data=x;
	t->next=NULL;
	last->next=t;
	last=t;
}

char pop(){
	if(last==root){
		printf("Memory is empty");
		return 0;
	}
	s *iter=root;
	while(iter->next!=last && iter)
		iter=iter->next;
	
	char c;
	c=last->data;
	free(last);
	last=iter;
	last->next=NULL;
	return c;
}


int convert(char infix[]){
	char *postfix;
	int i=0,j=0;
	postfix=(char *)malloc(sizeof(char)*strlen(infix));
	while(infix[i]!='\0'){
		if(isOperand(infix[i])){
			postfix[j++]=infix[i++];
		}
		else{
			if(last==NULL || pre(infix[i])>preStk(last->data)){
				push(infix[i++]);
			}
			else{
				if(infix[i]==')' && last->data=='('){
					pop();
					i++;
				}
				else{
					postfix[j++]=pop();
				}
			}
		}
	}
	while(last!=root)
		postfix[j++]=pop();
	postfix[j]='\0';
		
	printf("%s",postfix);
}


int main(int argc, char *argv[]) {
	root=(s *)malloc(sizeof(s));
	root->next=NULL;
	last=root;
	char *infix="a^(b/c)-d*e";
	convert(infix);
	return 0;
}
