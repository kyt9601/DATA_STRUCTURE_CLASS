#include <stdio.h>

int main()
{
	int n, m;
	int N, M;
	int i, j, k;
	int arr[100][100];
	int x = 1;

	scanf("%d %d",&n,&m);
	N = n-1;
	M = m;

	i = 0;
	j = -1;

	while (1)
	{
		for (k=0; k<M; k++)
		{
			arr[i][++j] = x++;
		}
		M--;

		if (N<0 || M<0) { break; }

		for (k=0; k<N; k++)
		{
			arr[++i][j] = x++;
		}
		N--;

		if (N<0 || M<0) { break; }

		for (k=0; k<M; k++)
		{
			arr[i][--j] = x++;
		}
		M--;

		if (N<0 || M<0) { break; }

		for (k=0; k<N; k++)
		{
			arr[--i][j] = x++;
		}
		N--;

		if (N<0 || M<0) { break; }
	}

	for (i=0; i<n; i++)
	{
		for (j=0; j<m; j++)
			printf(" %d",arr[i][j]);
		puts("");
	}

	return 0;
}