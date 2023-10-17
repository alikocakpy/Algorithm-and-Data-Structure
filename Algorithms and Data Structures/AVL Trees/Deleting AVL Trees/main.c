#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *lChild;
	struct node *rChild;
	int height;
}*root;


int NodeHeight(struct node *p){
	int hl,hr;
	
	hl=p && p->lChild?p->lChild->height:0;
	hr=p && p->rChild?p->rChild->height:0;
	
	return hl>hr?hl+1:hr+1;
	
}

int BalanceFactor(struct node *p){
	int hl,hr;
	
	hl=p && p->lChild?p->lChild->height:0;
	hr=p && p->rChild?p->rChild->height:0;
	
	return hl-hr;
	
}

struct node *LLRotation(struct node *p){
	struct node *pl,*plr;
	
	pl=p->lChild;
	plr=pl->rChild;
	
	pl->rChild=p;
	p->lChild=plr;
	p->height=NodeHeight(p);
	pl->height=NodeHeight(pl);
	
	if(root==p)
		root=pl;
	
	return pl;
	
}

struct node *RRRotation(struct node *p){
	struct node *pr=p->rChild;
	struct node *prl=pr->lChild;
	
	pr->lChild=p;
	p->rChild=prl;
	
	p->height=NodeHeight(p);
	pr->height=NodeHeight(pr);
	
	if(root==p)
		root=pr;
	
	return pr;
	
}

struct node *LRRotation(struct node *p){
	struct node *pl=p->lChild;
	struct node *plr=pl->rChild;
	
	p->lChild=plr->rChild;
	pl->rChild=plr->lChild;
	plr->rChild=p;
	plr->lChild=pl;
	
	p->height=NodeHeight(p);
	pl->height=NodeHeight(pl);
	plr->height=NodeHeight(plr);
	
	if(p==root)
		root=plr;
	
	return plr;
	
}

struct node *RLRotation(struct node *p){
	struct node *pr=p->rChild;
	struct node *prl=pr->lChild;
	
	p->rChild=prl->lChild;
	pr->lChild=prl->rChild;
	prl->lChild=p;
	prl->rChild=pr;
	
	p->height=NodeHeight(p);
	pr->height=NodeHeight(pr);
	prl->height=NodeHeight(prl);
	
	if(root==p)
		root=prl;
	
	return prl;
}


struct node *RCreate(struct node *p,int key){
	struct node *t=NULL;
	if(!p){
		t=(struct node *)malloc(sizeof(struct node));
		t->lChild=t->rChild=NULL;
		t->height=1;
		t->data=key;
		return t;
	}
	
	if(p->data>key)
		p->lChild=RCreate(p->lChild,key);
	else if(p->data<key)
		p->rChild=RCreate(p->rChild,key);
	else{
		printf("value already entired");
		return;
	}
		
		
	p->height=NodeHeight(p);
	
	if(BalanceFactor(p)==2 && BalanceFactor(p->lChild)==1)
		return LLRotation(p);
	else if(BalanceFactor(p)==2 && BalanceFactor(p->lChild)==-1)
		return LRRotation(p);
	else if(BalanceFactor(p)==-2 && BalanceFactor(p->rChild)==-1)
		return RRRotation(p);
	else if(BalanceFactor(p)==-2 && BalanceFactor(p->rChild)==1)
		return RLRotation(p);
		
		
	return p;
}

void inOrder(struct node *p){
	if(p){
		inOrder(p->lChild);
		printf("%d %d \n",p->data,p->height);
		inOrder(p->rChild);
	}
}

struct node *InPre(struct node *p){
	if(p && p->rChild)
		p=p->rChild;
	return p;
}

struct node *InSucc(struct node *p){
	if(p && p->lChild)
		p=p->lChild;
	return p;
}

struct node* deletee(struct node *p,int key){
	
	if(!p){
		return NULL;
	}
	if(!p->lChild && !p->rChild && p->data==key){
		if(p==root)
			root=NULL;
		free(p);
		return NULL;
	}
	
	struct node *q;
	if(p->data<key)
		p->rChild=deletee(p->rChild,key);
	else if(p->data>key)
		p->lChild=deletee(p->lChild,key);
	else if(p->data==key){
			q=(struct node *)malloc(sizeof(struct node));
		if((NodeHeight(p->lChild)>NodeHeight(p->rChild)) || !p->rChild){//	the lasts nodes for example left child valid but right invalid we send left and right child so left is valid but last right is invalid so give error.
			q=InPre(p->lChild);//	 and I add condition what is right child valid or not. if not enter.
			p->data=q->data;
			p->lChild=deletee(p->lChild,q->data);
		}
		else{
			q=InSucc(p->rChild);
			p->data=q->data;
			p->rChild=deletee(p->rChild,q->data);
		}
		
	}	
	else{
		printf("invalid value !!!");
		return;
	}
	
	p->height=NodeHeight(p);	
		
	if(BalanceFactor(p)==2 && BalanceFactor(p->lChild)==1)
		return LLRotation(p);
	else if(BalanceFactor(p)==2 && BalanceFactor(p->lChild)==-1)
		return LRRotation(p);
	else if(BalanceFactor(p)==-2 && BalanceFactor(p->rChild)==-1)
		return RRRotation(p);
	else if(BalanceFactor(p)==-2 && BalanceFactor(p->rChild)==1)
		return RLRotation(p);
	
	return p;
}

int main(int argc, char *argv[]) {
	root=RCreate(root,1);
	RCreate(root,5);
	RCreate(root,6);
	RCreate(root,7);
	RCreate(root,8);
	RCreate(root,40);
	
	inOrder(root);
	deletee(root,7);
	deletee(root,5);
	printf("\narray after deleting :\n\n");
	inOrder(root);
	
	
	return 0;
}
