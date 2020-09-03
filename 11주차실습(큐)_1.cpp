#include <stdio.h>
#include <stdlib.h>

int *queue, q;
int front, rear;

#define CHECK(x) (((x)+q)%q)

void push(int data);
int pop();
void print();

int main()
{
	int n, i;
	int data;
	char op;

	scanf("%d",&q);
	queue = (int*)calloc(q,sizeof(int));

	scanf("%d",&n);

	for (i=0; i<n; i++)
	{
		getchar();
		op = getchar();

		switch (op)
		{
		case 'I' : scanf("%d",&data); push(data); break;
		case 'D' : pop(); break;
		case 'P' : print(); break;
		}
	}

	free(queue);

	return 0;
}

void push(int data)
{
	if (CHECK(rear+1) != front)
	{
		rear = CHECK(rear+1);
		queue[rear] = data;
	}
	else
	{
		printf("overflow");
		print();
		exit(0);
	}
}

int pop()
{
	if (front != rear)
	{
		int data = queue[ (front = CHECK(front+1)) ];

		queue[front] = 0;

		return data;
	}
	else
	{
		puts("underflow");
		exit(0);
	}
}

void print()
{
	int i;

	for (i=0; i<q; i++)
	{
		printf(" %d",queue[i]);
	}
	puts("");
}