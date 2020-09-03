#include <stdio.h>

void Hanoi(int n, char from, char aux, char to);

int main()
{
	int n;

	scanf("%d",&n);

	Hanoi(n,'A','B','C');

	return 0;
}

void Hanoi(int n, char from, char aux, char to)
{
	if (n == 1)
	{
		printf("%c %c\n",from,to);
		return;
	}

	Hanoi(n-1,from,to,aux);

	printf("%c %c\n",from,to);
	
	Hanoi(n-1,aux,from,to);
}