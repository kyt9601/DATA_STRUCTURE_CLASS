#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	struct node *next;
	struct node *prev;
	char ch;
} node;

node *head = NULL;
node *tail = NULL;
int count = 0;

node *getNode();
void init();
node *mov(int pos);
void add(int pos, char ch);
void delete(int pos);
void get_entry(int pos);
void print();
int invalidPos(int pos);
void cleanUp();

node *getNode()
{
	return (node*)malloc(sizeof(node));
}

void init()
{
	head = getNode();
	tail = getNode();

	head->prev = NULL;
	head->next = tail;
	tail->prev = head;
	tail->next = NULL;
}

node *mov(int pos)
{
	node *p;

	for (p=head->next; 1<pos; p=p->next, pos--);

	return p;
}

void add(int pos, char ch)
{
	if (invalidPos(pos))
		return;

	{
		node *p = mov(pos);
		node *nw = getNode();
		nw->ch = ch;

		nw->next = p;
		nw->prev = p->prev;
		p->prev->next = nw;
		p->prev = nw;

		count++;
	}
}

void delete(int pos)
{
	if (invalidPos(pos+1))
		return;

	{
		node *p = mov(pos);

		p->next->prev = p->prev;
		p->prev->next = p->next;

		free(p);

		count--;
	}
}

void get_entry(int pos)
{
	if (invalidPos(pos+1))
		return;

	{
		node *p = mov(pos);

		printf("%c\n",p->ch);
	}
}

void print()
{
	node *p;

	for (p=head->next; p!=tail; p=p->next)
		putchar(p->ch);

	puts("");
}

int invalidPos(int pos)
{
	if (pos<=0 || count+1<pos)
	{
		puts("invalid position");
		return 1;
	}
	else
		return 0;
}

void cleanUp()
{
	node *p;

	for (p=head->next->next; p!=NULL; p=p->next)
		free(p->prev);
}

int main()
{
	int n, i;

	int pos;
	char op, ch;

	init();

	scanf("%d",&n);

	for (i=0; i<n; i++)
	{
		getchar();
		scanf("%c",&op);

		switch (op)
		{
		case 'A' : scanf("%d %c",&pos,&ch); add(pos,ch); break;
		case 'D' : scanf("%d",&pos); delete(pos); break;
		case 'G' : scanf("%d",&pos); get_entry(pos); break;
		case 'P' : print(); break;
		}
	}

	cleanUp();

	return 0;
}