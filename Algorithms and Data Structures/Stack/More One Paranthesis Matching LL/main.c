#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
	int size;
	int top;
	char *c;
}st;

int push(char x){
	if(st.top==st.size){
		printf("Stack is full");
		return -1;
	}
	st.c[++st.top]=x;	
	
}
int pop(){
	if(st.top==-1){
		printf("Stack is empty");
		return -1;
	}
	st.c[st.top]=0;
	st.top--;
}

int isEmpty(){
	if(st.top==-1){
		return 1;
	}
	else{
		return 0;
	}
}
int peek(){
	return st.c[st.top];
}
void display(){
	int i=0;
	while(i<=st.top){
		printf("%c ",st.c[i]);
		i++;
	}
	printf("\n");
}

int isBalanced(char a[]){
	int i;
	for(i=0;i<st.size;i++){
		if(a[i]=='{' || a[i]=='(' || a[i]=='['){
			push(a[i]);
		}
		else if(a[i]=='}' || a[i]==')' || a[i]==']'){
			if(isEmpty())return 0;
			char s=peek();
			if(s+1==a[i] && a[i]<42)
				pop();
			else if(s+2==a[i] && a[i]>90  && a[i]<95 )
				pop();
			else if(s+2==a[i] && a[i]<126 && a[i]>120)
				pop();
			else{
				printf("hata");
				return 0;
			}	
		}
		display();
	}
	
	isEmpty()?printf("dogru"):printf("hata");
	return 1;
}


int main(int argc, char *argv[]) {
	char *a="{([a+b]*[c-d])/e}";
	st.top=-1;
	st.size=strlen(a);
	st.c=(char *)malloc(sizeof(char)*st.size);
	
	int x=isBalanced(a);
	if(x==1)
		printf("dogru");
	else
		printf("hatali");
	
	return 0;
}
