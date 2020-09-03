#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, i, j;
	int arr[100];
	int x, *info;
	int tmp;

	scanf("%d",&n);

	for (i=0; i<n; i++)
		scanf("%d",arr+i);

	scanf("%d",&x);
	info = (int*)malloc(sizeof(int)*x*2);

	for (i=0; i<x*2; i++)
		scanf("%d",info+i);

	for (i=0; i<x*2; i+=2)
	{
		for (j=0; j<(info[i+1]-info[i]+1)/2; j++)
		{
			tmp = arr[info[i]+j];
			arr[info[i]+j] = arr[info[i+1]-j];
			arr[info[i+1]-j] = tmp;
		}
	}

	for (i=0; i<n; i++)
		printf(" %d",arr[i]);

	puts("");

	free(info);

	return 0;
}