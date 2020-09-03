#include <stdio.h>
#include <stdlib.h>

typedef struct BinaryTree
{
	int data;
	int id;
	struct BinaryTree *left;
	struct BinaryTree *right;

} node;

node* getNode();
node *findPrePos(node *p, int _id);
node *addNode(node *p, char ch, int id, int volume);
node *makeTree();
void print(int order, node *p);
void visit(node *p);
void preOrder(node *p);
void inOrder(node *p);
void postOrder(node *p);
void cleanUp(node *p);

int main()
{
	int order, id;
	node *root = makeTree();

	scanf("%d %d",&order,&id);

	print(order,findPrePos(root,id));

	cleanUp(root);

	return 0;
}

// 노드 동적 할당
node* getNode()
{
	node *nw = (node*)malloc(sizeof(node));

	nw->data = 0;
	nw->id = 0;
	nw->left = NULL;
	nw->right = NULL;

	return nw;
}

node *findPrePos(node *p, int _id)
{
	if (p == NULL)
		return NULL;
	else if (p->id == _id)
		return p;

	if (findPrePos(p->left,_id) != NULL)
		return findPrePos(p->left,_id);
	else if (findPrePos(p->right,_id) != NULL)
		return findPrePos(p->right,_id);
}

// 노드 추가
node *addNode(node *p, char ch, int id, int volume)
{
	node *nw = getNode();
	nw->id = id;
	nw->data = volume;

	if (ch == 'S')
		return nw;
	else if (ch == 'L')
		p->left = nw;
	else
		p->right = nw;
}

// 트리 초기화
node *makeTree()
{
	node *root;

	root = addNode(NULL,'S',1,20);
	addNode(findPrePos(root,1),'L',2,30);
	addNode(findPrePos(root,1),'R',3,50);
	addNode(findPrePos(root,2),'L',4,70);
	addNode(findPrePos(root,2),'R',5,90);
	addNode(findPrePos(root,3),'R',6,120);
	addNode(findPrePos(root,6),'L',7,130);
	addNode(findPrePos(root,6),'R',8,80);

	return root;
}

// 해당 노드와 자식 노드들의 값 출력
void print(int order, node *p)
{
	if (p != NULL)
		switch (order)
		{
		case 1 : preOrder(p); break;
		case 2 : inOrder(p); break;
		case 3 : postOrder(p); break;
		}
	else
		printf(" -1");

	puts("");
}

// 노드 방문
void visit(node *p)
{
	printf(" %d",p->data);
}

// 전위 순회
void preOrder(node *p)
{
	if (p != NULL)
	{
		visit(p);
		preOrder(p->left);
		preOrder(p->right);
	}
}

// 중위 순회
void inOrder(node *p)
{
	if (p != NULL)
	{
		inOrder(p->left);
		visit(p);
		inOrder(p->right);
	}
}

// 후위 순회
void postOrder(node *p)
{
	if (p != NULL)
	{
		postOrder(p->left);
		postOrder(p->right);
		visit(p);
	}
}

// 후위 순회로 동적 메모리 해제
void cleanUp(node *p)
{
	if (p->left != NULL)	{ cleanUp(p->left); }
	if (p->right != NULL)	{ cleanUp(p->right); }
	
	free(p);
}