#include <stdio.h>

int main()
{
	int arr[100][100];
	int n, m;
	int i, j;
	int h, k;
	int x = 1;

	scanf("%d %d",&n,&m);

	for (j=0; j<m; j++)
	{
		h = 0;

		for (k=j; h<n && 0<=k; h++,k--)
		{
			arr[h][k] = x++;
		}
	}

	for (i=1; i<n; i++)
	{
		k = m-1;

		for (h=i; h<n && 0<=k; h++,k--)
		{
			arr[h][k] = x++;
		}
	}

	for (i=0; i<n; i++)
	{
		for (j=0; j<m; j++)
			printf(" %d",arr[i][j]);

		puts("");
	}

	return 0;
}