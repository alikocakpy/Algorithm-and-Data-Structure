#include <stdio.h>
#include <stdlib.h>

struct stack{
	char c;
	struct stack *next;
};

typedef struct stack stck;
stck *st=NULL;
stck *root;
stck *last;


char peek(){
	return last->c;
}

void pop(){
	if(last==st && st->next==NULL){
		free(st);
		return ;
	}
	while(root->next!=last){
		root=root->next;
	}
	free(last);
	last=root;
	last->next=NULL;
	root=st;
	
}

void push(char c){
	if(st==NULL){
		st=(stck *)malloc(sizeof(stck));
		st->c=c;
		st->next=NULL;
		root=last=st;
	}
	else{
		stck *t=NULL;
		t=(stck *)malloc(sizeof(stck));
		if(t==NULL){
			printf("Memory is full!!");
			return ;
		}
		t->next=NULL;
		t->c=c;
		last->next=t;
		last=t;
	}
	
}

int isOperand(char c){
	if(c=='(' || c=='{' || c=='[' || c==')' || c==']' || c=='}')
		return 0;
	else
		return 1;
}

int balance(char p[]){
	int i=0;
	while(p[i]!='\0'){
		if(isOperand(p[i])){
			i++;
		}
		else{
			if(p[i]=='(' || p[i]=='{' || p[i]=='['){
				push(p[i++]);
			}
			else{
				if(peek()==p[i]-1){
					pop();
					i++;
				}
				else if(peek()==p[i]-2 && p[i]<95 && p[i]>90){
					pop();
					i++;
				}
				else if(peek()==p[i]-2 && 120<p[i]){
					pop();
					i++;
				}
				else{
					printf("Paranthesis is not matching!!!");
					return 0;
				}
			}
		}
	}
	if(st->next==NULL)
		return 0;
	else
		return 1;
}


int main(int argc, char *argv[]) {
	char *p="{([a+b]+c/(d*[e-g])}";
	balance(p)?printf("Basarili"):printf("hatali");
	return 0;
}
