#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int value;
	struct node *next;
} node;

node *getNode()
{
	return (node*)malloc(sizeof(node));
}

node *addNode(node *p, int _value)
{
	node *nw = getNode();
	nw->value = _value;
	nw->next = NULL;

	if (p != NULL)
		p->next = nw;

	return nw;
}

int subset(node *A, node *B)
{
	if (A == NULL)
	{
		return 0;
	}
	else
	{
		node *p, *q;

		q = A;
		for (p=B; p!=NULL && q!=NULL; p=p->next)
		{
			if (p->value == q->value)
				q = q->next;
		}

		if (q == NULL)
			return 0;
		else
			return q->value;
	}
}

void cleanUp(node *n)
{
	node *p, *t;

	for (p=n; p!=NULL; p=t)
	{
		t = p->next;
		free(p);
	}
}

int main()
{
	int i, value;
	int a, b;
	node *A = NULL;
	node *B = NULL;
	node *p;

	scanf("%d",&a);
	for (i=0; i<a; i++)
	{
		scanf("%d",&value);

		if (A == NULL)
			p = A = addNode(NULL,value);
		else
			p = addNode(p,value);
	}

	scanf("%d",&b);
	for (i=0; i<b; i++)
	{
		scanf("%d",&value);

		if (B == NULL)
			p = B = addNode(NULL,value);
		else
			p = addNode(p,value);
	}

	printf("%d\n",subset(A,B));

	cleanUp(A);
	cleanUp(B);

	return 0;
}