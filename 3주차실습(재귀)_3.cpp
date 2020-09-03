#include <stdio.h>

void position(int n);

int main()
{
	int n;

	scanf("%d",&n);

	position(n);
	
	return 0;
}

void position(int n)
{
	printf("%d\n",n%10);

	if (10 <= n)
		position(n/10);
}