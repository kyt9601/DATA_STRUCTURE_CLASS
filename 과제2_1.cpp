#include <stdio.h>
#include <stdlib.h>

int recMax(int *start, int *end);

int main()
{
	int n, i;
	int *arr;

	scanf("%d",&n);
	arr = (int*)malloc(sizeof(int)*n);

	for (i=0; i<n; i++)
		scanf("%d",arr+i);

	printf("%d\n",recMax(arr,arr+n-1));

	free(arr);

	return 0;
}

// 최댓값을 구할 구간의 시작 주소와 마지막 주소를 인자로 받는다
int recMax(int *start, int *end)
{
	int frontMax; // 받은 구간의 앞부분의 최댓값
	int backMax; // 받은 구간의 뒷부분의 최댓값

	if (start == end) // 구간에 원소가 1개 뿐일때
		return *start; // 그 원소를 반환
/*
	구간의 크기가 4인 경우 (end = start + 3)
	frontMax = recMax(start,start+1);
	backMax = recMax(start+2,end);

	구간의 크기가 5인 경우 (end = start + 4)
	frontMax = recMax(start,start+2);
	backMax = recMax(start+3,end);
*/
	frontMax = recMax(start,start+(end-start)/2);
	backMax = recMax(start+(end-start)/2+1,end);

	return frontMax>backMax ? frontMax : backMax;
}