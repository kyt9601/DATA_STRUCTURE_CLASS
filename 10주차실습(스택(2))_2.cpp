/*
#include <stdio.h>

#define SIZE 100

char stack[SIZE];
int top;

void init();
void push(char ch);
void pop();
void postFix(char *str);
char convert(char op, char prev);
//void opCheck(char op, int *pi, char prev);
void print();
int rank(char op);

int main()
{
	int n, i;
	char str[101];

	scanf("%d",&n);

	for (i=0; i<n; i++)
	{
		init();

		scanf("%s",str);
		postFix(str);
		puts("");
	}

	return 0;
}

void init()
{
	top = -1;
}

void push(char ch)
{
	if (top+1 < SIZE)
		stack[++top] = ch;
}

void pop()
{
	if (0 <= top)
	{
		if (stack[top] == '$')
			printf("&&");
		else if (stack[top] == '#')
			printf("||");
		else if (stack[top] == 'a')
			putchar('+');
		else if (stack[top] == 'm')
			putchar('-');
		else if (stack[top] == '(')
			;
		else
			putchar(stack[top]);

		top--;
	}
}

char convert(char op, char prev)
{
	if (op == '&') { return '$'; }
	else if (op == '|') { return '#'; }
	else if (op=='+' && (prev<'A' || 'Z'<prev) && prev!=')') { return 'a'; }
	else if (op=='-' && (prev<'A' || 'Z'<prev) && prev!=')') { return 'm'; }
	else { return op; }
}

void postFix(char *str)
{
	int i = -1;
	char prev = '(';

	while (str[++i])
	{
		if ('A'<=str[i] && str[i]<='Z')
			putchar(str[i]);
		else
		{
			char op = convert(str[i],prev);
			if (op=='$' || op=='#') { i++; }
			
		//print();
			if (op == '(')
			{
				push(op);
			}
			else if (op == ')')
			{
				while (stack[top] != '(')
					pop();
				pop();
			}
			else
			{
				int opRank;
				int topRank;

				/*
				while (0 <= top)
				{
					opRank = rank(op);
					topRank = rank(stack[top]);

					if (topRank >= opRank)
						pop();
					else
						break;
				}
				*/
				/*
				while( 0 <= top && rank(op) <= rank(stack[top]) )
					pop();

				push(op);
			}
		}

		prev = str[i];
		//print();
	}

	while (0 <= top)
		pop();
}

void print()
{
	int i = 0;

	if (0 <= top)
		putchar(' ');
	for (i=0; i<=top; i++)
	{
		putchar(stack[i]);
	}
	puts("");
}

int rank(char op)
{
	switch (op)
	{
	case '!' :
	case 'a' :
	case 'm' : return 6;
	case '*' :
	case '/' : return 5;
	case '+' :
	case '-' : return 4;
	case '>' :
	case '<' : return 3;
	case '$' : return 2;
	case '#' : return 1;
	case '(' : return 0; // Stack 에 있을때 닫는 괄호 나올때 까지 pop 되면 안되므로
	}
}*/
/*
void opCheck(char op, int *pi, char prev)
{
	int opRank;
	int topRank;

	if (op == '(')
	{
		push(op);
	}
	else if (op == ')')
	{
		while (stack[top] != '(')
			pop();
		pop();
	}
	else
	{
		while (0 <= top)
		{
			opRank = rank(op);
			topRank = rank(stack[top]);

			if (topRank >= opRank)
				pop();
			else
				break;
		}

		push(op);
	}
}
*/

#include <stdio.h>

#define SIZE 100

int stack[SIZE];
int top;

int evaluate(char *str);

void init()
{
	top = -1;
}

void push(int num)
{
	if (top+1 < SIZE)
		stack[++top] = num;
}

int pop()
{
	if (0 <= top)
		return stack[top--];
}

int main()
{
	int n, i;
	char str[101];

	scanf("%d",&n);

	for (i=0; i<n; i++)
	{
		init();

		scanf("%s",str);
		printf("%d\n",evaluate(str));
	}

	return 0;
}

int evaluate(char *str)
{
	int i = -1;
	int sum = 0;

	while (str[++i])
	{
		if ('0'<=str[i] && str[i]<='9')
		{
			push(str[i]-'0');
		}
		else
		{
			int n1;
			int n2;
			
			n2 = pop();
			n1 = pop();

			switch (str[i])
			{
			case '+' : push(n1+n2); break;
			case '-' : push(n1-n2); break;
			case '*' : push(n1*n2); break;
			case '/' : push(n1/n2); break;
			}
		}
	}

	return pop();
}

