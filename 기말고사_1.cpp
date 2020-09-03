#include <stdio.h>
#include <stdlib.h>

typedef struct SinglyLinkedList_without_TH
{
	int data;
	struct SinglyLinkedList_without_TH *next;
} node;

node *getNode();
int result(char *exp);
void push(node **pStack, int c);
int pop(node **pStack);

int main()
{
	char exp[101];

	gets(exp);

	printf("%d\n",result(exp));

	return 0;
}

node *getNode()
{
	return (node*)malloc(sizeof(node));
}

int result(char *exp)
{
	node *stack = NULL;
	int i;

	for (i=0; exp[i]; i++)
	{
		if ('0'<=exp[i] && exp[i]<='9')
		{
			push(&stack,exp[i]-'0');
		}
		else
		{
			int n2;
			int n1;

			switch (exp[i])
			{
			case '+' : n2=pop(&stack); n1=pop(&stack); push(&stack,n1+n2); break;
			case '-' : n2=pop(&stack); n1=pop(&stack); push(&stack,n1-n2); break;
			case '*' : n2=pop(&stack); n1=pop(&stack); push(&stack,n1*n2); break;
			case '/' : n2=pop(&stack); n1=pop(&stack); push(&stack,n1/n2); break;
			case '~' : n1=pop(&stack); push(&stack,-n1); break;
			}
		}
	}

	return pop(&stack);
}

void push(node **pStack, int c)
{
	node *nw = getNode();
	nw->data = c;

	if (*pStack != NULL)
		nw->next = *pStack;
	else
		nw->next = NULL;

	*pStack = nw;
}

int pop(node **pStack)
{
	int c = (*pStack)->data;
	node *p = *pStack;

	*pStack = (*pStack)->next;

	free(p);

	return c;
}