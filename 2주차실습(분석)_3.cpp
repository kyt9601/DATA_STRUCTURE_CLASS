#include <stdio.h>
#include <stdlib.h>

void prefixAverages1(int X[], int A[], int n);
void prefixAverages2(int X[], int A[], int n);

int main()
{
	int *X;
	int *A;
	int n;
	int i;

//	clock_t s;
//	clock_t e;

	scanf("%d",&n);

	X = (int*)malloc(sizeof(int)*n);
	A = (int*)malloc(sizeof(int)*n);

//	srand(time(NULL));

	for (i=0; i<n; i++)
//		X[i] = rand() % 10001;
		scanf("%d",X+i);

//	s = clock();
	prefixAverages1(X,A,n);
//	e = clock();

	for (i=0; i<n; i++)
	{
		printf("%d",A[i]);

		if (i != n-1)
			putchar(' ');
	}
//	printf("%d\n",e-s);
	puts("");

//	s = clock();
	prefixAverages2(X,A,n);
//	e = clock();

	for (i=0; i<n; i++)
	{
		printf("%d",A[i]);

		if (i != n-1)
			putchar(' ');
	}
//	printf("%d\n",e-s);
	puts("");

	free(X);
	free(A);

	return 0;
}

void prefixAverages1(int X[], int A[], int n)
{
	int i, j;
	int sum;
	double tmp;

	for (i=0; i<n; i++)
	{
		sum = 0;

		for (j=0; j<=i; j++)
			sum += X[j];

		tmp = (double) sum / (double) (i+1);

		if (tmp - (int) tmp >= 0.5)
			A[i] = (int) tmp + 1;
		else
			A[i] = (int) tmp;
	}
}

void prefixAverages2(int X[], int A[], int n)
{
	int i;
	int sum = 0;
	double tmp;

	for (i=0; i<n; i++)
	{
		sum += X[i];

		tmp = (double) sum / (double) (i+1);

		if (tmp - (int) tmp >= 0.5)
			A[i] = (int) tmp + 1;
		else
			A[i] = (int) tmp;
	}
}