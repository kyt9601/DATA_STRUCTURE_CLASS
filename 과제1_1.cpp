#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, k;
	int i;
	int *arr;
	int sum = 0, cnt = 0;

	scanf("%d %d",&n,&k);	// n, k 입력
	arr = (int*)malloc(sizeof(int)*n);	// 배열 동적 할당

	for (i=0; i<n; i++)
	{
		scanf("%d",arr+i);	// 정수 입력

		if (i < k)
			cnt++;	// cnt 는 1 씩 증가하다가 i >= k 가 되면 그 후로는 k 로 고정
		else
			sum -= arr[i-k];	// 현재 위치보다 k 칸 앞에 있는 수를 sum 에서 뺌

		sum += arr[i];	// 현재 입력받은 정수를 sum 에 더함

		printf("%d",(int)((float)sum/(float)cnt+0.5));	// 반올림과 출력

		if (i != n-1)
			printf(" ");
		else
			printf("\n");
	}

	free(arr);

	return 0;
}