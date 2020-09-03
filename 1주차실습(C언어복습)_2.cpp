#include<stdio.h>

void ABC(int arr[], int k);

int main()
{
	int i;
	int arr[10];

	for (i=0; i<10; i++)
	{
		scanf("%d",arr+i);
	}

	for (i=0; i<10; i++)
	{
		ABC(arr,i);
		printf(" %d",arr[i]);
	}

	puts("");

	return 0;
}

void ABC(int arr[], int k)
{
	int i;
	int max = arr[k], max_i = k;

	for (i=k; i<10; i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
			max_i = i;
		}
	}

	arr[max_i] = arr[k];
	arr[k] = max;
}