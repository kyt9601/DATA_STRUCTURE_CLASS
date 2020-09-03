#include <stdio.h>

int main()
{
	int n, i;
	int arr[100];
	int x, *info;
	int tmp1, tmp2;

	scanf("%d",&n);

	for (i=0; i<n; i++)
		scanf("%d",arr+i);
	
	scanf("%d",&x);
	info = (int*)malloc(sizeof(int)*x);

	for (i=0; i<x; i++)
		scanf("%d",info+i);

	tmp1 = arr[info[x-1]];
	for (i=0; i<x-1; i++)
	{
		tmp2 = arr[info[i]];
		arr[info[i]] = tmp1;
		tmp1 = tmp2;
	}

	arr[info[0]] = tmp1;

	for (i=0; i<n; i++)
		printf(" %d",arr[i]);
	puts("");

	free(info);

	return 0;
}