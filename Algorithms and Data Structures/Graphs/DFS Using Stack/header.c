#include <stdio.h>
#include <stdlib.h>
#include "header.h"


void create(int size){
	st=(struct stk *)malloc(sizeof(struct stk));
	st->top=1;
	st->size=size;
	st->S=(int *)malloc(sizeof(int)*st->size);
}

void push(int key){
	if(st->top==st->size)
		printf("hata!!!");
	else
		st->S[++st->top]=key;
}

int stkEmpty(){
	return st->top!=0?0:1;
}
int stTop(){
	return st->S[st->top];
}

int pop(){
	if(st->top==0)
		printf("stack is empty");
	else
		return st->S[--st->top];
}
