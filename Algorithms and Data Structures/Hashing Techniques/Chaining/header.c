#include <stdio.h>
#include <stdlib.h>
#include "header.h"

#define size 10;

int index(int key){
	return key%size;
}

void initilize(){
	int i;
	for(i=0;i<10;i++)
		arr[i]=NULL;
}

void SortedInsert(int key){
	struct node *q,*t,*p;
	t=(struct node *)malloc(sizeof(struct node));
	t->data=key;
	t->next=NULL;
	
	int i=index(key);
	
	if(arr[i]==NULL)
		arr[i]=t;
	else{
		p=arr[i];
		while(p && p->data<key){
			q=p;
			p=p->next;
		}
		if(p==NULL){
			q->next=t;
		}
		else{
			t->next=p;
			q->next=t;
		}
	}
}

struct node *search(int key){
	int i=index(key);
	struct node *p=arr[i];
	while(p!=NULL){
		if(key==p->data){
			return p;
		}
		p=p->next;
	}
	return NULL;
}


