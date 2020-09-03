#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct DoubleLinkedList_without_HT
{
	int data;
	struct DoubleLinkedList_without_HT *prev;
	struct DoubleLinkedList_without_HT *next;
} node;

node *getNode();
void add_front(node **front, node **rear, int _data);
void add_rear(node **front, node **rear, int _data);
void delete_front(node **front, node **rear);
void delete_rear(node **front, node **rear);
void print(node *front, node *rear);
void cleanUp(node **front, node **rear);

int main()
{
	int n, i;
	char op[3];
	node *front = NULL;
	node *rear = NULL;

	scanf("%d",&n);

	for (i=0; i<n; i++)
	{
		scanf("%s",op);

		if (!strcmp("AF",op))		{ int data; scanf("%d",&data); add_front(&front,&rear,data); }
		else if (!strcmp("AR",op))	{ int data; scanf("%d",&data); add_rear(&front,&rear,data); }
		else if (!strcmp("DF",op))	{ delete_front(&front,&rear); }
		else if (!strcmp("DR",op))	{ delete_rear(&front,&rear); }
		else						{ print(front,rear); }
	}

	cleanUp(&front,&rear);

	return 0;
}

node *getNode()
{
	return (node*)malloc(sizeof(node));
}

void add_front(node **front, node **rear, int _data)
{
	node *nw = getNode();	
	nw->data = _data;

	if (*front==NULL && *rear==NULL)
	{
		*front = *rear = nw;

		nw->prev = NULL;
		nw->next = NULL;
	}
	else
	{
		nw->prev = NULL;
		nw->next = (*front);
		(*front)->prev = nw;
		*front = nw;
	}
}

void add_rear(node **front, node **rear, int _data)
{
	node *nw = getNode();	
	nw->data = _data;

	if (*front==NULL && *rear==NULL)
	{
		*front = *rear = nw;

		nw->prev = NULL;
		nw->next = NULL;
	}
	else
	{
		nw->next = NULL;
		nw->prev = (*rear);
		(*rear)->next = nw;
		*rear = nw;
	}
}

void delete_front(node **front, node **rear)
{
	if (*front==NULL && *rear==NULL)
	{
		puts("underflow");
		exit(0);
	}
	else if (*front == *rear)
	{
		free(*front);
		*front = *rear = NULL;
	}
	else
	{
		node *t = (*front)->next;
		free(*front);
		*front = t;
		(*front)->prev = NULL;
	}
}

void delete_rear(node **front, node **rear)
{
	if (*front==NULL && *rear==NULL)
	{
		puts("underflow");
		exit(0);
	}
	else if (*front == *rear)
	{
		free(*rear);
		*front = *rear = NULL;
	}
	else
	{
		node *t = (*rear)->prev;
		free(*rear);
		*rear = t;
		(*rear)->next = NULL;
	}
}

void print(node *front, node *rear)
{
	node *p;

	for (p=front; p!=NULL; p=p->next)
	{
		printf(" %d",p->data);
	}
	puts("");
}

void cleanUp(node **front, node **rear)
{
	node *p, *t;

	for (p=*front; p!=NULL; p=t)
	{
		t = p->next;
		free(p);
	}

	*front = *rear = NULL;
}