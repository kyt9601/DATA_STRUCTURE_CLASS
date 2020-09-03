#include <stdio.h>

int sum(int n);

int main()
{
	int i, n;
	int _sum = 0;

	scanf("%d",&n);

	for (i=1; i<=n; i++)
	{
		_sum += sum(i);
	}

	printf("%d\n",_sum);

	return 0;
}

int sum(int n)
{
	int i;
	int sum = 0;

	for (i=1; i<=n; i++)
	{
		sum += i;
	}
	
	return sum;
}