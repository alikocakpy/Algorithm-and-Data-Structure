#include <stdio.h>
#include <stdlib.h>
#define size 10
#include "header.h"

void insert(int key){
	SortedInsert(key);
}



int main(int argc, char *argv[]) {
	arr=(struct node **)malloc(sizeof(struct node *)*10);
	initilize();
	int a[]={2,22,3,6,9,87,14,5,66,145,23};
	int n=sizeof(a)/sizeof(a[0]);
	int i;
	for(i=0;i<n;i++)
		SortedInsert(a[i]);
	
	insert(999);
	
	struct node *t;
	t=search(989);
	t=search(145);
	if(t==NULL)
		printf("value is not found");
	else
		printf("%d finded ",t->data);
	
	return 0;
}
