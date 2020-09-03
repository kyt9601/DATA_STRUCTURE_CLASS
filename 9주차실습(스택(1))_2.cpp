#include <stdio.h>

#define MAX 1000

char stack[MAX];
int top;
int n;
int ok;

void init()
{
	top = -1;
	n = 0;
	ok = 1;
}

void push(char ch)
{
	if (top+1 < MAX)
	{
		stack[++top] = ch;
		n++;	// 괄호 개수 증가
	}
}

char pop()
{
	if (0 <= top)
		return stack[top--];
}

void check(char ch)
{
	if (0 <= top)
	{
		char tmp;

		if ((stack[top]=='('&&ch==')') || (stack[top]=='{'&&ch=='}') || (stack[top]=='['&&ch==']'))
			tmp = pop();	// 짝이 맞으면, pop()
		else
			ok = 0;	// 짝이 안맞으면 Wrong
	}
	else
	{
		ok = 0;	// stack 에 아무것도 없는데 ),},] 이 들어온 경우 Wrong
	}
	
	n++;	// 괄호 개수 증가
}

int main()
{
	char ch;

	init();

	while ((ch=getc(stdin))!='\n' && ch!=EOF)
	{
		switch (ch)
		{
		case '(' :
		case '{' :
		case '[' : push(ch); break;
		case ')' :
		case '}' :
		case ']' : check(ch); break;
		}
	}

	if (0 <= top)	// stack 에 남는 괄호가 있을 경우 (, {, [
		ok = 0;	// Wrong

	printf("%s_%d\n",ok?"OK":"Wrong",n);

	return 0;
}