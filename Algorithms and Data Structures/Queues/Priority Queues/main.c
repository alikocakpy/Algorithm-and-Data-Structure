#include <stdio.h>
#include <stdlib.h>

struct queue{
	int rear;
	int front;
	int size;
	char *c;
};

typedef struct queue que;
que *q1;
que *q2;
que *q3;

/*------ Struct -------*/

void create(que *qu){
	qu->size=4;
	qu->rear=qu->front=0;
	qu->c=(char *)malloc(sizeof(char)*qu->size);
}

void resize(que *qu){
	int i=0;
	char *c;
	if((qu->rear-qu->front)>qu->size/2){
		c=(char *)malloc(sizeof(char)*(qu->size*2));
		i=qu->front;
		while(i<=qu->rear){
			c[i]=qu->c[i];
			i++;
		}
		qu->size*=2;
		free(qu->c);
		qu->c=c;
	}
}

void pri(char dizi[]){
	int i=0,j=0,k=0,l=0;
	while(dizi[i]!='\0'){
		if(dizi[i]=='a' || dizi[i]=='d' || dizi[i]=='g'){
		resize(q1);
		q1->c[j++]=dizi[i++];
		}
		else if(dizi[i]=='b' || dizi[i]=='c' || dizi[i]=='f'){
			resize(q2);
			q2->c[k++]=dizi[i++];
		}
		else{
			resize(q3);
			q3->c[l++]=dizi[i++];
		}
	}
	q1->c[j]='\0';
	q2->c[k]='\0';
	q3->c[l]='\0';
}

void display(que *qu){
	int i=0;
	while(qu->c[i]!='\0'){
		printf("%c \n",qu->c[i++]);
	}
}

void delete(){
	int i=0;
	if(q1->c[q1->front]!='\0'){
		printf("%c deleted\n",q1->c[q1->front++]);
	}
	else if(q2->c[q2->front]!='\0'){
		printf("%c deleted\n",q2->c[q2->front++]);
	}
	else if(q3->c[q3->front]!='\0'){
		printf("%c deleted\n",q3->c[q3->front++]);
	}
	else{
		printf("Memory is empty");
	}
}


int main(){
	char *dizi="abcdefghjklmn";
	q1=(que *)malloc(sizeof(que));
	q2=(que *)malloc(sizeof(que));
	q3=(que *)malloc(sizeof(que));
	create(q1);
	create(q2);
	create(q3);
	pri(dizi);
	display(q1);
	printf("\n\n");
	display(q2);
	printf("\n\n");
	display(q3);
	printf("\n\n");
	delete();
	delete();
	delete();
	delete();
	delete();
	delete();
	delete();
	
	
	
}
