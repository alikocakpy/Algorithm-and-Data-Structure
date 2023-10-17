#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *lchild;
	struct node *rchild;
}*root;

struct stack{
	int top;
	int size;
	struct node **s;
};

void createStk(struct stack *st,int size){
	st->size=size;
	st->top=-1;
	st->s=(struct node **)malloc(sizeof(struct node *));
}

void push(struct stack *st,struct node *p){
	if(st->top==st->size-1)
		printf("hata var");
	st->top++;
	st->s[st->top]=p;
}

struct node* pop(struct stack *st){
	if(st->top==-1)
		return 0;
	struct node *t=st->s[st->top];
	st->top--;
	return t;
}

int StkTop(struct stack st){
	if(st.top!=-1){
		struct node *x;
		x=st.s[st.top];
		int y=x->data;
		return y;
	}
	else{
		return 2222;
	}
}

//I have only pre or post order no inorder but not need. I add less than main number tree and main number stack
//and if bigger number came I check the number betwen last and before last if not I pop if yes I put the right side .
//So I dont use Ýnorder but I find True Tree Shape

void createPre(int pre[],int n){
	struct stack st;
	createStk(&st,n);
	struct node *t,*p;
	int i=0;
	root=(struct node *)malloc(sizeof(struct node));
	root->lchild=root->rchild=NULL;
	root->data=pre[i++];
	p=root;
	
	while(i<n){
		if(pre[i]<p->data){
			t=(struct node *)malloc(sizeof(struct node ));
			t->lchild=t->rchild=NULL;
			t->data=pre[i++];
			p->lchild=t;
			push(&st,p);
			p=t;
		}
		else{
			
			if(pre[i]>p->data && pre[i]<StkTop(st)){
				t=(struct node *)malloc(sizeof(struct node ));
				t->lchild=t->rchild=NULL;
				t->data=pre[i++];
				p->rchild=t;
				p=t;
			}
			else{
				p=pop(&st);
			}
		}
	}
	
}


void inOrder(struct node *p){
	if(p){
		inOrder(p->lchild);
		printf("%d ",p->data);
		inOrder(p->rchild);
	}
}


int main(int argc, char *argv[]) {
	int pre[]={5,2,1,3,8,7,9};
	
	createPre(pre,sizeof(pre)/sizeof(pre[0]));
	
	inOrder(root);
	
	return 0;
}
