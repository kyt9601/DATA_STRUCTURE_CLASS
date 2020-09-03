#include<stdio.h>

struct student
{
	char name[10];
	int n;
};

int main()
{
	int i;
	double avg = 0;
	struct student arr[5];

	for (i=0; i<5; i++)
	{
		scanf("%s %d",arr[i].name,&(arr[i].n));
		avg += (double) arr[i].n / (double) 5;
	}

	for (i=0; i<5; i++)
	{
		if (arr[i].n < avg)
		{
			puts(arr[i].name);
		}
	}

	return 0;
}