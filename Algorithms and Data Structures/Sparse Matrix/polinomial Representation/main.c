#include <stdio.h>
#include <stdlib.h>

struct pol{
	int n;
	struct key *x;
};

struct key{
	int exp;
	int coeff;
};

void create(struct pol *p){
	int i,j,k;
	printf("Enter number of polynomial :");
	scanf("%d",&p->n);
	p->x=(struct key *) malloc(p->n*sizeof(struct key));
	for(i=0;i<p->n;i++){
		printf("%d. value information(coeff/exponent) :",i+1);
		scanf("%d %d",&p->x[i].coeff,&p->x[i].exp);
	}
}

void display(struct pol p){
	int i=0;
	for(i=0;i<p.n;i++){
		if(p.x[i].exp == 0){
			printf("%d",p.x[i].coeff);
		}
		else
			printf("%d.X^%d + ",p.x[i].coeff,p.x[i].exp);
	}
	printf("\n\n");
}

struct pol *sum(struct pol p1,struct pol p2){
	int i=0,j=0,k=0;
	struct pol *p3;
	p3=(struct pol *) malloc(sizeof(struct pol));
	p3->x=(struct key *) malloc((p1.n+p2.n)*sizeof(struct pol));
	
	while(p1.n>i && p2.n>j){
		if(p1.x[i].exp > p2.x[j].exp)
			p3->x[k++]=p1.x[i++];
		else if(p1.x[i].exp < p2.x[j].exp)
			p3->x[k++]=p2.x[j++];
		else{
			p3->x[k]=p2.x[j];
			p3->x[k++].coeff = p1.x[i++].coeff + p2.x[j++].coeff;
		}
	}
	for(;i<p1.n;i++)
		p3->x[k++]=p1.x[i];
	for(;j<p2.n;j++)
		p3->x[k++]=p2.x[j];
	
	p3->n=k;
	return p3;
}


int main(int argc, char *argv[]) {
	struct pol p1,p2,*p3;
	create(&p1);
	display(p1);
	create(&p2);
	display(p2);
	p3=sum(p1,p2);
	display(*p3);
	return 0;
}
