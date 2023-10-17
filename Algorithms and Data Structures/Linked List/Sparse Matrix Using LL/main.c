#include <stdio.h>
#include <stdlib.h>

struct node{
	int row;
	int col;
	int data;
	struct node *next;
}*root[];



void create(int size,int width,int height){
	int i=0,j=0;
	struct node *t=NULL,*iter=NULL;
	
	while(i<4 -1){
		t=(struct node *)malloc(sizeof(struct node));
		printf("Enter the %d. member row col and data information :",i+1);
		scanf("%d %d %d",&t->row,&t->col,&t->data);
		t->next=NULL;
		if(root[0]==NULL){
			root[0]=t;
			iter=root[0];
		}
		else if(i==t->row && root[i]){
			iter->next=t;
			iter=t;
		}
		else{
			i++;
			root[i]=t;
			iter=root[i];
		}
	}
	
}

void display(int size,int width,int height){
	int i,j,k=1;
	struct node *iter=root[0];
	for(i=0;i<height;i++){
		for(j=0;j<width;j++){
			if(k){
				if(root[i]->col==j){
				printf(" %d ",root[i]->data);
				if(root[i]->next)
					root[i]=root[i]->next;
				}
				else{
					printf(" 0 ");
				}
			}
			else{
				printf(" 0 ");
			}
		}
		printf("\n");
		if(i+1>=4){
			k=0;
		}
	}
}

int main(int argc, char *argv[]) {
	int size,width=5,height=6;
	printf("Enter the number of non-zero elements");
	scanf("%d",&size);
	create(size,width,height);
	display(size,width,height);
	return 0;
}
