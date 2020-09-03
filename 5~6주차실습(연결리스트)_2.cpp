#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	struct node *next;
	int coef;
	int exp;
} node;

node *getNode();
node *appendTerm(node *p, int coef, int exp);
node *addPoly(node *head1, node *head2);
void cleanUp(node *head);

node *getNode()
{
	return (node*)malloc(sizeof(node));
}

node *appendTerm(node *p, int coef, int exp)
{
	node *nw = getNode();
	nw->coef = coef;
	nw->exp = exp;

	nw->next = p->next;
	p->next = nw;

	return p->next;
}

node *addPoly(node *head1, node *head2)
{
	node *cur_h1 = head1->next;
	node *cur_h2 = head2->next;
	node *nw_head;
	node *p;

	nw_head = getNode();
	nw_head->next = NULL;
	p = nw_head;

	while (cur_h1!=NULL && cur_h2!=NULL)
	{
		if (cur_h1->exp > cur_h2->exp)
		{
			p = appendTerm(p,cur_h1->coef,cur_h1->exp);
			cur_h1 = cur_h1->next;
		}
		else if (cur_h1->exp < cur_h2->exp)
		{
			p = appendTerm(p,cur_h2->coef,cur_h2->exp);
			cur_h2 = cur_h2->next;
		}
		else
		{
			if (cur_h1->coef+cur_h2->coef)
			{
				p = appendTerm(p,cur_h1->coef+cur_h2->coef,cur_h1->exp);
			}

			cur_h1 = cur_h1->next;	
			cur_h2 = cur_h2->next;
		}
	}

	while (cur_h1 != NULL)
	{
		p = appendTerm(p,cur_h1->coef,cur_h1->exp);
		cur_h1 = cur_h1->next;
	}

	while (cur_h2 != NULL)
	{
		p = appendTerm(p,cur_h2->coef,cur_h2->exp);
		cur_h2 = cur_h2->next;
	}

	return nw_head;
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
	int i;
	int e1, e2;
	int coef, exp;
	node *head1;
	node *head2;
	node *p;
	node *nw_head;

	head1 = getNode();
	head2 = getNode();
	head1->next = NULL;
	head2->next = NULL;

	scanf("%d",&e1);

	p = head1;
	for (i=0; i<e1; i++)
	{
		scanf("%d %d",&coef,&exp);

		if (coef)
			p = appendTerm(p,coef,exp);
	}

	scanf("%d",&e2);

	p = head2;
	for (i=0; i<e2; i++)
	{
		scanf("%d %d",&coef,&exp);

		if (coef)
			p = appendTerm(p,coef,exp);
	}

	nw_head = addPoly(head1,head2);

	for (p=nw_head->next; p!=NULL; p=p->next)
	{
		printf(" %d %d",p->coef,p->exp);
	}
	puts("");

	cleanUp(head1);
	cleanUp(head2);
	cleanUp(nw_head);

	return 0;
}