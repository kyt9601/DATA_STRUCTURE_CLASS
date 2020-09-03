#include <stdio.h>
#include <stdlib.h>

#define SIZE 8
#define CHECK(x) (((x)+SIZE)%SIZE)

typedef struct BinaryTree
{
	int data;
	struct BinaryTree *left;
	struct BinaryTree *right;

} node;

typedef struct
{
	node *q[SIZE];
	int front;
	int rear;
} queue;

node* getNode();
node *addRoot(int _data, node *_left, node *_right);
node *addNode(int _data);
node *makeTree();
node *findLevelPos(node *root, int n);
void print(node *p);
void cleanUp(node *p);

int main()
{
	int n;
	node *root = makeTree();

	scanf("%d",&n);

	print(findLevelPos(root,n));

	cleanUp(root);

	return 0;
}

// 노드 동적 할당
node* getNode()
{
	node *nw = (node*)malloc(sizeof(node));

	nw->data = 0;
	nw->left = NULL;
	nw->right = NULL;

	return nw;
}

// 루트 추가
node *addRoot(int _data, node *_left, node *_right)
{
	node *nwRoot = getNode();
	nwRoot->data = _data;

	if (_left != NULL)	{ nwRoot->left = _left; }
	if (_right != NULL)	{ nwRoot->right = _right; }

	return nwRoot;
}

// 노드 추가
node *addNode(int _data)
{
	node *nwNode = getNode();
	nwNode->data = _data;

	return nwNode;	
}

// 트리 초기화
node *makeTree()
{
	node *rootRight;
	node *rootLeft;

	rootRight = addRoot(120,addNode(130),addNode(80));
	rootRight = addRoot(50,NULL,rootRight);

	rootLeft = addRoot(30,addNode(70),addNode(90));

	return addRoot(20,rootLeft,rootRight);	
}

// 레벨 순회로 위치 찾기 위한 큐 삽입 메소드
void push(queue *pQueue, node *p)
{
	if (CHECK(pQueue->rear+1) != pQueue->front	&&	p != NULL)
		(pQueue->q)[ CHECK(++(pQueue->rear)) ] = p;
}

// 레벨 순회로 위치 찾기 위한 큐 삭제 메소드
node *pop(queue *pQueue)
{
	if (pQueue->rear != pQueue->front)
		return (pQueue->q)[ CHECK(++(pQueue->front)) ];
	else
		return NULL;
}

// 레벨 순회로 위치 찾은 후 포인터 반환
node *findLevelPos(node *root, int n)
{
	queue myQueue;
	node *p = NULL;

	if (1<=n && n<=SIZE)
	{
		myQueue.front = 0;
		myQueue.rear = 0;
		push(&myQueue,root);
	}

	while (0<n && n<=SIZE)
	{
		p = (myQueue.q)[ CHECK(myQueue.front+1) ];

		push(&myQueue,p->left);
		push(&myQueue,p->right);
		
		pop(&myQueue);
		n--;
	}
	
	return p;
}

// 해당 노드와 자식 노드들의 값 출력
void print(node *p)
{
	if (p != NULL)
	{
		printf(" %d",p->data);
		(p->left!=NULL) ? printf(" %d",p->left->data) : printf("");
		(p->right!=NULL) ? printf(" %d",p->right->data) : printf("");
	}
	else
	{
		printf(" -1");
	}
	puts("");
}

// 후위 순회로 동적 메모리 해제
void cleanUp(node *p)
{
	if (p->left != NULL)	{ cleanUp(p->left); }
	if (p->right != NULL)	{ cleanUp(p->right); }
	
	free(p);
}