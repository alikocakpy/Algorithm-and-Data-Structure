#ifndef stack
#define stack

struct stk{
	int top;
	int size;
	long int *S;
};

void createStk(struct stk *s,int size);
void push(struct stk *s,long int p);
long int pop(struct stk *s);
int isEmptyStk(struct stk s);

#endif

