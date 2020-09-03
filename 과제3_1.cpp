#include <stdio.h>

int main()
{
	int n, m;
	int i, j;
	int start, end;
	int arr[100][100];

	scanf("%d %d",&n,&m); // 배열 크기 입력

	start = 1; // 1부터 1씩 증가하는 변수
	end = n * m; // n*m 의 값을 저장하는 변수
	i = j = 0;
	while (start <= end)
	{
		while (i!=n && j!=-1)
			arr[i++][j--] = start++; // ↙ 방향으로 이동
		i--;
		j++; // 현재 위치가 입력한 배열을 벗어나므로, 전 위치로 이동

		if (i == n-1) // 아래가 막힌 경우
			j++; // 우측으로 이동
		else if (j == 0) // 좌측이 막힌 경우
			i++; // 아래로 이동
		
		while (i!=-1 && j!=m)
			arr[i--][j++] = start++; // ↗ 방향으로 이동
		i++;
		j--; // 현재 위치가 입력한 배열을 벗어나므로, 전 위치로 이동

		if (j == m-1) // 우측이 막힌 경우
			i++; // 아래로 이동
		else if (i == 0) // 위가 막힌 경우
			j++; // 우측으로 이동
	}

	for (i=0; i<n; i++) // 출력
	{
		for (j=0; j<m; j++)
			printf(" %d",arr[i][j]);
		puts("");
	}

	return 0;
}