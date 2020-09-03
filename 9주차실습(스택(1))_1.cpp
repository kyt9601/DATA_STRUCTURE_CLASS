#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *stack;
int max;
int top;

void init()
{
	scanf("%d",&max);
	stack= (char*)malloc(sizeof(char)*max);
	top = -1;
}

void push(char ch)
{
	if (top+1 < max)
		stack[++top] = ch;
	else
		puts("Stack FULL");
}

char pop()
{
	if (0 <= top)
		return stack[top--];
	else
		puts("Stack Empty");
}

void peek()
{
	if (0 <= top)
		printf("%c\n",stack[top]);
	else
		puts("Stack Empty");
}

void duplicate()
{
	if (top+1 == max)
	{
		puts("Stack FULL");	
	}
	else
	{
		char ch = pop();

		push(ch);
		push(ch);
	}
}

void upRotate(int n)
{
	if (0<=top && n-1<=top)
	{
		int i;
		char tmp = stack[top];

		for (i=top; i>top-n+1; i--)
			stack[i] = stack[i-1];
		stack[i] = tmp;
	}
}

void downRotate(int n)
{	
	if (0<=top && n-1<=top)
	{
		int i;
		char tmp = stack[top-n+1];

		for (i=top-n+1; i<top; i++)
			stack[i] = stack[i+1];
		stack[i] = tmp;
	}
}

void print()
{
	int i;

	for (i=top; 0<=i; i--)
		putchar(stack[i]);

	if (0 <= top)
		puts("");
}

int main()
{
	int i, op_count;
	char op_name[10], tmp;

	init();

	scanf("%d",&op_count);

	for (i=0; i<op_count; i++)
	{
		scanf("%s",op_name); getchar();

		if (!strcmp(op_name,"PUSH"))
			push(getchar());
		else if (!strcmp(op_name,"POP"))
			tmp = pop();
		else if (!strcmp(op_name,"PEEK"))
			peek();
		else if (!strcmp(op_name,"DUP"))
			duplicate();
		else if (!strcmp(op_name,"UpR"))
			upRotate(getchar()-'0');
		else if (!strcmp(op_name,"DownR"))
			downRotate(getchar()-'0');
		else
			print();
	}

	free(stack);

	return 0;
}