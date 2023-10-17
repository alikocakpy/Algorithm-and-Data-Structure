#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *lchild;
	struct node *rchild;
};

//This is finding real shape of tree. a array can have a lot of shape and we found one which is real


int counter=0;
struct node *traversal(int preorder[],int inorder[],int start,int end){
	if(start>end)
		return NULL;
	
	struct node *t=(struct node *)malloc(sizeof(struct node));
	t->data=preorder[counter++];
	t->lchild=t->rchild=NULL;
	
	if(start==end)
		return t;
	
	
	int index=getIndex(inorder,start,end,t->data);
	t->lchild=traversal(preorder,inorder,start,index-1);
	t->rchild=traversal(preorder,inorder,index+1,end);
	
	return t;
	
}

int getIndex(int inorder[],int start,int end,int data){
	int i;
	for(i=start;i<=end;i++){
		if(inorder[i]==data)
			return i;
	}
	return 0;
}

void printInorder(struct node *p){
	if(p){
		printInorder(p->lchild);
		printf("%d ",p->data);
		printInorder(p->rchild);
	}
}

int main(int argc, char *argv[]) {
	int preorder[] = {4, 7, 9, 6, 3, 2, 5, 8, 1};
    int inorder[] = {7, 6, 9, 3, 4, 5, 8, 2, 1};
    struct node *root=traversal(preorder,inorder,0,(sizeof(preorder)/sizeof(preorder[0])-1));
    printInorder(root);
	return 0;
}
