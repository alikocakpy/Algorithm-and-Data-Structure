#ifndef header
#define header

struct node{
	int data;
	struct node *next;
}**arr;

void initilize();
int index(int key);
void SortedInsert(int key);
struct node *search(int key);


#endif
