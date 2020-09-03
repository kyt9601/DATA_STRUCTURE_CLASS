#include<stdio.h>
#include <stdlib.h>

struct student
{
	char name[8];
	int kor;
	int eng;
	int math;
};

void Judge(struct student *p);

int main()
{
	int n;
	int i;
	struct student *arr;

	scanf("%d",&n);

	arr = (struct student*)malloc(sizeof(struct student)*n);

	for (i=0; i<n; i++)
	{
		scanf("%s %d %d %d",arr[i].name,&(arr[i].kor),&(arr[i].eng),&(arr[i].math));
	}

	for (i=0; i<n; i++)
	{
		printf("%s %.1lf",arr[i].name,(double) (arr[i].kor + arr[i].eng + arr[i].math) / (double) 3);

		Judge(arr+i);		
	}

	return 0;
}

void Judge(struct student *p)
{
	if (p->kor>=90 || p->eng>=90 || p->math>=90)
	{
		printf(" GREAT");
	}

	if (p->kor<70 || p->eng<70 || p->math<70)
	{
		printf(" BAD");
	}

	puts("");
}