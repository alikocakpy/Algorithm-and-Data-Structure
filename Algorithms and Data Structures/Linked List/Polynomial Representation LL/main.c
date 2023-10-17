#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node{
	int coeff;
	int exp;
	struct node *next;
}*root1,*root2,*root3;

void create(int n,struct node *root){
	printf("0. nodes coeff and exp :");
	scanf("%d %d",&root->coeff,&root->exp);
	
	struct node *iter=root,*t;
	int i=1;
	while(i<n){
		t=(struct node *)malloc(sizeof(struct node));
		printf("1.nodes coeff and exp :");
		scanf("%d %d",&t->coeff,&t->exp);
		t->next=NULL;
		iter->next=t;
		iter=t;
		i++;
	}
	
}

void display(struct node *root){
	struct node *iter;
	iter=root;
	while(iter->next){
		printf("%d X^%d + ",iter->coeff,iter->exp);
		iter=iter->next;
	}
	printf("%d X^%d",iter->coeff,iter->exp);
}
/*
double pol(){
	double sum=0;
	struct node *iter=root;
	int x;
	printf("\nEnter x variable value :");
	scanf("%d",&x);
	while(iter){
		sum+=iter->coeff*pow(x,iter->exp);
		iter=iter->next;
	}
	return sum;
}
*/
void add(struct node *root3){
	struct node *iter,*t;
	if(root1->exp>root2->exp){
		root3->coeff=root1->coeff;
		root3->exp=root1->exp;
		root3->next=NULL;
		root1=root1->next;
	}
	else if(root1->exp<root2->exp){
		root3->coeff=root2->coeff;
		root3->exp=root2->exp;
		root3->next=NULL;
		root2=root2->next;
	}
	else{
		t->coeff=root2->coeff+root1->coeff;
		t->exp=root2->exp+root1->exp;
		t->next=NULL;
		iter->next=t;
		iter=t;
		root2=root2->next;
		root1=root1->next;
		}
	iter=root3;
	
	while(root1!=NULL && root2!=NULL ){
		t=(struct node *)malloc(sizeof(struct node));
		if(root1->exp>root2->exp){
			t->coeff=root1->coeff;
			t->exp=root1->exp;
			t->next=NULL;
			iter->next=t;
			iter=t;
			root1=root1->next;
		}
		else if(root1->exp<root2->exp){
			t->coeff=root2->coeff;
			t->exp=root2->exp;
			t->next=NULL;
			iter->next=t;
			iter=t;
			root2=root2->next;
		}
		else{
			t->coeff=root2->coeff+root1->coeff;
			t->exp=root2->exp+root1->exp;
			t->next=NULL;
			iter->next=t;
			iter=t;
			root2=root2->next;
			root1=root1->next;
		}
	}
}


int main(int argc, char *argv[]) {
	root1=(struct node *)malloc(sizeof(struct node));
	root2=(struct node *)malloc(sizeof(struct node));
	root3=(struct node *)malloc(sizeof(struct node));
	int n;
	printf("How many value will you entering first polynomial ?");
	scanf("%d",&n);
	
	create(n,root1);
	display(root1);
	printf("\nHow many value will you entering second polynomial?");
	scanf("%d",&n);
	create(n,root2);
	display(root2);
//	printf("%lf",pol());
	add(root3);
	display(root3);
	return 0;
}
