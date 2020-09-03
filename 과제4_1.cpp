#include <stdio.h>
#include <stdlib.h>

typedef struct node // 노드 정의
{
	int col;
	int row;
	int value;
	struct node *prev;
	struct node *next;
} node;

typedef struct DoublyLinkedList_with_HT // 헤더와 트레일러를 가진 이중 연결 리스트 정의
{
	node *head;
	node *tail;
} List;

node *getNode();
void initList(List *L);
void addNodetoEnd(List *L, int _col, int _row, int _value);
void sumList(List *A, List *B, List *C);
void cleanUp(List *L);

node *getNode()
{
	return (node*)malloc(sizeof(node));
}

void initList(List *L) // 리스트 초기화
{
	L->head = getNode();
	L->tail = getNode();

	L->head->prev = NULL;
	L->head->next = L->tail;
	L->tail->prev = L->head;
	L->tail->next = NULL;
}

void addNodetoEnd(List *L, int _col, int _row, int _value) // 해당 리스트의 마지막에 원소 추가 (헤더, 트레일러 제외)
{
	if (_value) // 원소값이 0이 아닌 경우만 추가
	{
		node *nw = getNode();
		nw->col = _col;
		nw->row = _row;
		nw->value = _value;

		nw->next = L->tail;
		nw->prev = L->tail->prev;
		L->tail->prev->next = nw;
		L->tail->prev = nw;
	}
}

void sumList(List *A, List *B, List *C) // 행렬 A와 B 를 더한 결과를 C 에 저장
{
	node *i = A->head->next;
	node *j = B->head->next;

	// 행이 작은것부터 추가된다
	while (i!=A->tail && j!=B->tail)
	{
		if (i->col > j->col)
		{
			addNodetoEnd(C,j->col,j->row,j->value);
			j = j->next;
		}
		else if (i->col < j->col)
		{
			addNodetoEnd(C,i->col,i->row,i->value);
			i = i->next;
		}
		else
		{	// 행이 같을 경우, 열이 작은것부터 추가된다
			if (i->row > j->row)
			{
				addNodetoEnd(C,j->col,j->row,j->value);
				j = j->next;
			}
			else if (i->row < j->row)
			{
				addNodetoEnd(C,i->col,i->row,i->value);
				i = i->next;
			}
			else
			{	// 행과 열 모두 같을 경우, 원소값을 더하여 추가된다
				addNodetoEnd(C,i->col,i->row,i->value+j->value);
				i = i->next;
				j = j->next;
			}
		}
	}
/*
	아래 두 반복문은
	둘 중 하나만 실행되거나
	둘다 실행되지 않는다
*/
	while (i != A->tail)
	{
		addNodetoEnd(C,i->col,i->row,i->value);
		i = i->next;
	}

	while (j != B->tail)
	{
		addNodetoEnd(C,j->col,j->row,j->value);
		j = j->next;
	}
}

void cleanUp(List *L)
{
	node *p, *t;

	for (p=L->head; p!=NULL; p=t)
	{
		t = p->next;
		free(p);
	}
}

int main()
{
	int i;
	int a, b;
	int col, row, value;
	List A, B, C;
	node *p;

	// 리스트 초기화
	initList(&A);
	initList(&B);
	initList(&C);

	scanf("%d",&a);
	for (i=0; i<a; i++)
	{
		scanf("%d %d %d",&col,&row,&value);
		addNodetoEnd(&A,col,row,value);
	}

	scanf("%d",&b);
	for (i=0; i<b; i++)
	{
		scanf("%d %d %d",&col,&row,&value);
		addNodetoEnd(&B,col,row,value);
	}

	// 행렬 더하기
	sumList(&A,&B,&C);

	// 출력
	for (p=C.head->next; p!=C.tail; p=p->next)
	{
		printf("%d %d %d\n",p->col,p->row,p->value);
	}

	cleanUp(&A);
	cleanUp(&B);
	cleanUp(&C);

	return 0;
}