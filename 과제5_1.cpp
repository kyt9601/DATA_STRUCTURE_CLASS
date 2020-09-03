#include <stdio.h>
#include <stdlib.h>

#define SIZE 200 // 큐 크기 지정
#define CHECK(x) (((x)+SIZE)%SIZE) // 큐 인덱스 범위 검사

// 연결 이진 트리
typedef struct LinkedBinaryTree
{
	int		id;
	struct	LinkedBinaryTree *left;
	struct	LinkedBinaryTree *right;
} node;

// 환형 큐
typedef struct CircularQueue
{
	int front;
	int rear;
	node *q[SIZE]; // 노드들의 주소 저장
} queue;

// 트리 메소드
node *getNode();
void initRoot(node **pRoot);
node *findPrePos(node *p, int id);
void addNode(node *root,
			 int id, char lr, int child);

// 큐 메소드
void initQueue(queue *pQueue);
void push(queue *pQueue, node *p);
node *pop(queue *pQueue);
int isQueueEmpty(queue *pQueue);
int isQueueFull(queue *pQueue);

void printDepthNodes(node *root, int depth);
void cleanUp(node *p);

int main()
{
	int i;
	int n, d;
	int id, child;
	char lr;
	node *root;

	initRoot( &root );

	scanf("%d", &n);
	for (i=0; i<n-1; i++) {
		scanf("%d %c %d", &id, &lr, &child);
		addNode(root, id, lr, child);
	}

	scanf("%d", &d);
	printDepthNodes(root, d);

	cleanUp( root );

	return 0;
}

// 노드 할당과 초기화
node *getNode()
{
	node *nw = (node*)malloc( sizeof(node) );

	nw->id		= 0;
	nw->left	= NULL;
	nw->right	= NULL;

	return nw;
}

// 루트 초기화
void initRoot(node **pRoot)
{
	(*pRoot)		= getNode();
	(*pRoot)->id	= 1;
}

// 전위 순회로 해당 id 를 갖는 노드 검색 후 위치 반환
node *findPrePos(node *p, int id)
{
	node *t;

	if ( p == NULL ) // NULL 일 경우 NULL 반환
		return NULL;
	else if ( p->id == id ) // 찾으면 위치 반환
		return p;
	else if ( (t = findPrePos(p->left, id)) != NULL ) // 왼쪽 탐색 후 찾으면 위치 반환
		return t;
	else // 왼쪽에서 못찾았을 경우
		return findPrePos(p->right, id); // 오른쪽 탐색 후 위치 반환
}

// 노드 추가
void addNode(node *root,
			 int id, char lr, int child)
{
	node *p		= findPrePos(root, id); // 위치 검색
	node *childNode	= getNode();

	childNode->id	= child;

	(lr == 'L') ? (p->left = childNode) : (p->right = childNode);
}

// 큐 초기화
void initQueue(queue *pQueue)
{
	pQueue->front	= 0;
	pQueue->rear	= 0;
}

// 큐에 데이터 삽입
void push(queue *pQueue, node *p)
{
	node **q	= pQueue->q;
	int *pFront	= &( pQueue->front );
	int *pRear	= &( pQueue->rear );

	if ( !isQueueFull(pQueue) ) { // 큐가 가득차지 않았을 경우 삽입
		*pRear = CHECK( *pRear+1 );
		q[ *pRear ] = p;
	}
}

// 큐에서 데이터 반환
node *pop(queue *pQueue)
{
	node **q	= pQueue->q;
	int *pFront	= &( pQueue->front );
	int *pRear	= &( pQueue->rear );

	if ( !isQueueEmpty(pQueue) ) { // 빈 큐가 아닐 경우 반환
		*pFront = CHECK( *pFront+1 );
		return q[ *pFront ];
	}
}

// 빈 큐이면 참 반환
int isQueueEmpty(queue *pQueue)
{
	return ( pQueue->front == pQueue->rear );
}

// 가득찬 큐이면 참 반환
int isQueueFull(queue *pQueue)
{
	return ( CHECK( (pQueue->front)-1 ) == pQueue->rear );
}

// 큐를 이용하여 레벨 순회 순서로 해당 깊이의 노드들의 id 출력
void printDepthNodes(node *root, int depth)
{
	node *p;
	queue myQueue; // 레벨 순회를 위한 큐
	int curDepth = 0; // 순회하는 동안 현재 깊이

	initQueue( &myQueue );
	push(&myQueue, root); // 처음에 root 삽입

	if ( depth < 0 ) { // 깊이가 -1 이면
		while ( !isQueueEmpty(&myQueue) ) { // 모든 노드 출력
			p = pop( &myQueue );
			printf(" %d", p->id); // 반환과 출력

			if ( p->left != NULL )	{ push(&myQueue, p->left); } // 자식들 삽입
			if ( p->right != NULL )	{ push(&myQueue, p->right); }
		}
		puts(""); // 개행

		return;
	}

	/*	각 깊이의 노드들은 NULL 로 구분된다
		예시의 트리를 예로 들면,
		깊이가 0 인 노드들을 모두 큐에 삽입한 후의 큐는 1, NULL 을 갖는다
		깊이가 1 인 노드들을 모두 큐에 삽입한 후의 큐는 3, 9, NULL 을 갖는다
		... */
	push(&myQueue, NULL);

	while ( curDepth < depth ) {
		p = pop( &myQueue );

		if ( p == NULL ) { // 반환한 값이 NULL 이면 다음 깊이의 모든 노드들이 큐에 삽입된 상태이다
			push(&myQueue, NULL);
			curDepth++; // 현재 깊이 증가
			continue;
		}

		if ( p->left != NULL )	{ push(&myQueue, p->left); } // 자식들 삽입
		if ( p->right != NULL )	{ push(&myQueue, p->right); }
	}
	
	// 현재 큐에는 해당 깊이의 노드들과 마지막에 NULL 만 들어있으므로
	while ( (p = pop(&myQueue)) != NULL )
		printf(" %d", p->id); // NULL 이 아닌 동안 반환하며 출력
	puts(""); // 개행
}

// 후위 순회 순서로 동적 메모리 해제
void cleanUp(node *p)
{
	if (p->left != NULL)	{ cleanUp( p->left ); }
	if (p->right != NULL)	{ cleanUp( p->right ); }
	free(p);
}