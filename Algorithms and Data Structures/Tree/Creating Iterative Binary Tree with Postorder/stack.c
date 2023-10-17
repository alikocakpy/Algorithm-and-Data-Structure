#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


void createStk(struct stk *s,int size){
	s->size=size;
	s->top=-1;
	s->S=(long int *)malloc(sizeof(long int *)*s->size);
}

void push(struct stk *s,long int p){
	if(s->top==(s->size-1))
		printf("Stack is full");
	else{
		s->top++;
		s->S[s->top]=p;
	}
}

long int pop(struct stk *s){
	long int x;
	if(s->top==-1)
		printf("stack is empty");
	else
		x=s->S[s->top--];
	return x;
}

int isEmptyStk(struct stk s){
	if(s.top==-1)
		return 1;
	else
		return 0;
}

