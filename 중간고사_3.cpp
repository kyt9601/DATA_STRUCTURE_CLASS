#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int value;
	struct node *next;
} node;

node *head;
node *tail;

node *getNode();
void init();
void addtoFirst(int _value);
void print();
void cleanUp();

node *getNode()
{
	return (node*)malloc(sizeof(node));
}

void init()
{
	head = getNode();
	tail = getNode();

	head->next = tail;
	tail->next = NULL;
}

void addtoFirst(int _value)
{
	node *nw = getNode();
	nw->value = _value;
	
	nw->next = head->next;
	head->next = nw;
}

void print()
{
	node *p;

	for (p=head->next; p!=tail; p=p->next)
		printf(" %d",p->value);
	puts("");
}

void cleanUp()
{
	node *p, *t;

	for (p=head; p!=NULL; p=t)
	{
		t = p->next;
		free(p);
	}
}

int main()
{
	int n, i;
	int value;

	init();

	scanf("%d",&n);

	for (i=0; i<n; i++)
	{
		scanf("%d",&value);

		addtoFirst(value);
		print();
	}

	cleanUp();

	return 0;
}