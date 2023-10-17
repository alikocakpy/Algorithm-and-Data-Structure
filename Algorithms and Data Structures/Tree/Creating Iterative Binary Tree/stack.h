#ifndef stack
#define stack

struct stk{
	int top;
	int size;
	struct node **S;
};

void createStk(struct stk *s,int size);
void push(struct stk *s,struct node *p);
struct node *pop(struct stk *s);
int isEmptyStk(struct stk s);

#endif
