#include <stdio.h>

int main()
{
	int n;
	int i, j;
	int h, k;
	int x = 1;
	int arr[100][100];

	scanf("%d",&n);

	h = 0;
	k = -1;
	for (i=0; i<n; i++,h++)
	{
		for (j=0; j<n; j++)
		{
			if (i%2)
				arr[h][k--] = x++;
			else
				arr[h][++k] = x++;
		}
	}

	for (i=0; i<n; i++)
	{
		for (j=0; j<n; j++)
			printf(" %d",arr[i][j]);

		puts("");
	}
	
	return 0;
	
}