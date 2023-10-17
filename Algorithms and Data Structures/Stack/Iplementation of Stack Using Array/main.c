#include <stdio.h>
#include <stdlib.h>

struct stack{
	int size;
	int top;
	int *s;
}st;

/* This is stack ADT */

int push(int x){
	if(st.top==-1){
		st.s=(int *)malloc(sizeof(int)*st.size);
	}
	else if(st.size-1==st.top){
		printf("Memory is full!!!\n");
		return 0;
	}
	
	st.s[++st.top]=x;
	return 0;
}


int pop(){
	if(st.top<0){
		printf("There is no element");
		return 0;
	}
	int x;
	x=st.s[st.top];
	st.s[st.top]=0;
	st.top--;
	return x;
	
}

int peek(int index){
	if(st.top-index+1>st.top || st.top-index+1<0){
		printf("hata");
		return -1;
	}
	return st.s[st.top-index+1];
}

int stackTop(){
	if(st.top==-1)
		return -1;
	else 
		return st.s[st.top];
}

int isEmpty(){
	if(st.top==-1){
		printf("This array is empty");
		return 1;
	}
	else {
		printf("This array is not empty");
		return 0;
	}
}

int isFull(){
	if(st.top==st.size-1){
		printf("this array is FUll");
		return 1;
	}
	else{
		printf("This array is not full");
		return 0;
	}
}

void display(){
	printf("\n");
	int i;
	for(i=0;i<=st.top;i++){
		printf("%d ",st.s[i]);
	}
	printf("\n");
}




int main(int argc, char *argv[]) {
	int secim=1;
	st.size=4;
	st.top=-1;
	int x;
	while(secim){
		printf("Yapmak istediginiz secimi giriniz :\n[1]Push\n[2]POP\n[3]Peek\n[4]stack top \n[5]is empty \n[6]is full\n[0]Cikis");
		scanf("%d",&secim);
		if(secim==1){
			printf("Enter value");
			scanf("%d",&x);
			push(x);
			display();
		}
		else if(secim==2){
			x=pop();
			printf("%d deleted",x);
			display();
		}
		else if(secim==3){
			printf("Enter want to find element's index");
			scanf("%d",&x);
			x=peek(x);
			printf("\nelement is %d",x);
		}
		else if(secim==4){
			printf("\n%d\n",stackTop());
		}
		else if(secim==5){
			isEmpty();
		}
		else if(secim==6){
			isFull();
		}
		else{
			return 0;
		}
	}
	return 0;
}
