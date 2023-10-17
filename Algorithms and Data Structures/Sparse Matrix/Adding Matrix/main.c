#include <stdio.h>
#include <stdlib.h>

struct sparse {
	int m;
	int n;
	int num;
	struct element *e;
};

struct element{
	int i;
	int j;
	int x;
};


void create(struct sparse *s){
	printf("enter number of diamention and number of non-zero element :");
	scanf("%d %d %d",&s->m,&s->n,&s->num);
	s->e=(struct element *) malloc(s->num*sizeof(struct element));
	int i;
	for(i=0;i<s->num;i++){
		printf("%d. rows values :",i+1);
		scanf("%d %d %d",&s->e[i].i,&s->e[i].j,&s->e[i].x);
	}
	free(s);
}

void display(struct sparse s){
	int i,j,k=0;
	for(i=0;i<s.m;i++){
		for(j=0;j<s.n;j++){
			if(i==s.e[k].i && j==s.e[k].j)
				printf("%d ",s.e[k++].x);
			else
				printf("0 ");
		}
		printf("\n");
	}
}

struct sparse * add(struct sparse *s1,struct sparse *s2){
	
	struct sparse *s3;
	
	s3=(struct sparse *) malloc(sizeof(struct sparse));
	
	s3->e=(struct element *) malloc((s1->num+s2->num)*sizeof(struct element));
	
	int i=0,j=0,k=0;
	
	while(i<s1->num && j<s2->num){
		if(s1->e[i].i < s2->e[j].i)
			s3->e[k++]=s1->e[i++];
		else if(s1->e[i].i > s2->e[j].i)
			s3->e[k++]=s2->e[j++];
		else{
			if(s1->e[i].j < s2->e[j].j)
				s3->e[k++]=s1->e[i++];
			else if(s1->e[i].j > s2->e[j].j)
				s3->e[k++]=s2->e[j++];
			else{
				s3->e[k]=s1->e[i];
				s3->e[k++].x = s2->e[j++].x + s1->e[i++].x;
			}
		}
	}
	
	for(;i<s1->num;i++)
		s3->e[k++]=s1->e[i];
	for(;j<s2->num;j++)
		s3->e[k++]=s2->e[j];
		
	s3->num=k;
	s3->m=s1->m;
	s3->n=s2->n;
	
	return s3;
	free(s3);
}


int main(){
	struct sparse s1;
	struct sparse s2;
	struct sparse *s4;
	create(&s1);
	display(s1);
	create(&s2);
	display(s2);
	s4=add(&s1,&s2);
	display(*s4);
	
	free(s4);
}
