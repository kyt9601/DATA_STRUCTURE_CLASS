#include <stdio.h>

int gcd(int a, int b);

int main()
{
	int a, b;

	scanf("%d %d",&a,&b);

	printf("%d\n",gcd(a,b));

	return 0;
}

int gcd(int a, int b)
{
	if (!a)
		return b;

	if (!b)
		return a;

	if (a < b)
	{
		int t=a;
		a=b;
		b=t;
	}

	gcd(b,a%b);
}