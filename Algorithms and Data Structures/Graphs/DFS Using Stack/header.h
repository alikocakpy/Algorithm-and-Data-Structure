#ifndef header
#define header
struct stk{
	int top;
	int size;
	int *S;
}*st;

void create(int size);
void push(int key);
int stkEmpty();
int stTop();
int pop();
#endif
