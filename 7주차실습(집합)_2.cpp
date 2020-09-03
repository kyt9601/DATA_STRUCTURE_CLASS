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
	nw->next = p->next;
	p->next = nw;

	return nw;
}

node *Union(node *headA, node *headB)
{
	node *i = headA->next;
	node *j = headB->next;

	node *p;
	node *nwHead = getNode();
	nwHead->next = NULL;

	p = nwHead;

	if (headA->next==NULL && headB->next==NULL)
	{
		return nwHead;
	}

	while (i!=NULL && j!=NULL)
	{
		if (i->value < j->value)
		{
			p = addNode(p,i->value);
			i = i->next;
		}
		else if (i->value > j->value)
		{
			p = addNode(p,j->value);
			j = j->next;			
		}
		else
		{
			p = addNode(p,i->value);
			i = i->next;			
			j = j->next;			
		}
	}

	while (i != NULL)
	{
		p = addNode(p,i->value);
		i = i->next;
	}

	while (j != NULL)
	{
		p = addNode(p,j->value);
		j = j->next;
	}

	return nwHead;
}

node *Intersect(node *headA, node *headB)
{
	node *i, *j;
    node *t = headB->next;

	node *p;
	node *nwHead = getNode();
	nwHead->next = NULL;

	p = nwHead;

	if (headA->next==NULL || headB->next==NULL)
	{
		return nwHead;
	}
	else
		for (i=headA->next; i!=NULL; i=i->next)
			for (j=t; j!=NULL; j=j->next)
				if (i->value == j->value)
				{
					p = addNode(p,i->value);
					t = j->next;
					break;
				}

	return nwHead;	
}

void cleanUp(node *head)
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
	int i, value;
	int a, b;
	node *headA;
	node *headB;
	node *headU;
	node *headI;
	node *p;

	headA = getNode();
	headB = getNode();
	headA->next = NULL;
	headB->next = NULL;

	scanf("%d",&a);
	p = headA;
	for (i=0; i<a; i++)
	{
		scanf("%d",&value);
		p = addNode(p,value);
	}

	scanf("%d",&b);
	p = headB;
	for (i=0; i<b; i++)
	{
		scanf("%d",&value);
		p = addNode(p,value);
	}

	headU = Union(headA,headB);
	headI = Intersect(headA,headB);

    if (headU->next == NULL)
        printf(" 0");
    else
    	for (p=headU->next; p!=NULL; p=p->next)
    		printf(" %d",p->value);
	puts("");

    if (headI->next == NULL)
        printf(" 0");
    else
    	for (p=headI->next; p!=NULL; p=p->next)
    		printf(" %d",p->value);
	puts("");

	cleanUp(headA);
	cleanUp(headB);
	cleanUp(headU);
	cleanUp(headI);

	return 0;
}