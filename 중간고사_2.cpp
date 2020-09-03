int main()
{
	int i, j;
	int curI, curJ;
	int cnt, end;
	int arr[100][100];
	int n, m;

	scanf("%d %d",&n,&m);

	cnt = 1;
	end = n * m;
	curI = 0;
	curJ = 0;
	while (cnt <= end)
	{
		i = curI;
		j = curJ;

		while (i<n && 0<=j)
		{
			arr[i++][j--] = cnt++;
		}

		if (curJ < m-1)
			curJ++;
		else
			curI++;
	}

	for (i=0; i<n; i++)
	{
		for (j=0; j<m; j++)
			printf(" %d",arr[i][j]);
		puts("");
	}

	return 0;
}