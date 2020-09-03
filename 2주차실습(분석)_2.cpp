#include <stdio.h>

int mostOnes(int A[][100], int n);

int main()
{
	int A[100][100];
	int i, j;
	int n;

	scanf("%d",&n);

	for (i=0; i<n; i++)
	{
		for (j=0; j<n; j++)
		{
			scanf("%d",&(A[i][j]));
		}
	}

	printf("%d\n",mostOnes(A,n));

	return 0;
}

int mostOnes(int A[][100], int n)
{
	int i = 0, j = 0;
	int max = 0;

	do
	{
		if (A[i][j])
		{
			j++;
		}
		else
		{
			i++;

			if (i!=n && A[i][j])
				max=i;
		}
	}
	while (i!=n && j!=n);

	return max;
}