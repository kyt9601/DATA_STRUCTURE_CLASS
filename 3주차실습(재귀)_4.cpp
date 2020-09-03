#include <stdio.h>

int _max(int arr[], int n, int max);

int main()
{
	int arr[20];
	int n;
	int i;

	scanf("%d",&n);

	for (i=0; i<n; i++)
		scanf("%d",arr+i);

	printf("%d\n",_max(arr,n,arr[n-1]));
	
	return 0;
}

int _max(int arr[], int n, int max)
{
	if (n == 1)
		return max;

	if (max < arr[n-2])
		return _max(arr,n-1,arr[n-2]);
	else
		return _max(arr,n-1,max);
}