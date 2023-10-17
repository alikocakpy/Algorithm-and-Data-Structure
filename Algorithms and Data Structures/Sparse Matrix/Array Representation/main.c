#include <stdio.h>
#include <stdlib.h>

struct element{
	int i;
	int j;
	int x;
};

struct sparse{
	int n;
	int m;
	int num;
	struct element *e;
};

void create(struct sparse *s){
	printf("enter number of diamention");
	scanf("%d %d",&s->m,&s->n);
	printf("enter numebr of non-zero element");
	scanf("%d",&s->num);
	s->e=(struct element *)  malloc(sizeof(struct element)*s->num);
	int i;
	for(i=0;i<s->num;i++){
		printf("enter %d. diamention kordinat and value :",i);
		scanf("%d %d %d",&s->e[i].i,&s->e[i].j,&s->e[i].x);
	}
}

void display(struct sparse s){
	int i,j,k=0;
	for(i=0;i<s.num;i++){
		for(j=0;j<s.num;j++){
			if(i==s.e[k].i && j==s.e[k].j)
				printf("%d ",s.e[k++].x);
			else
				printf("0 ");
		}
		printf("\n");
	}
}

int main(){
	struct sparse s;
	create(&s);
	display(s);
	return 0;
}
