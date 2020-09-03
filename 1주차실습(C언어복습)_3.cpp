#include<stdio.h>

void swap(int *x, int *y);

int main()
{
	int n, i;
	int a, b;
	int arr[50];

	scanf("%d",&n);

	for (i=0; i<n; i++)
	{
		scanf("%d",arr+i);
	}

	scanf("%d %d",&a,&b);

	swap(arr+a,arr+b);

	for (i=0; i<n; i++)
	{
		printf(" %d",arr[i]);
	}

	puts("");
	
	return 0;
}
void swap(int *x, int *y)
{
	int t = *x;
	*x = *y;
	*y = t;
}