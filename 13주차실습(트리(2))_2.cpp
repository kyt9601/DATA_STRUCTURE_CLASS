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
node *makeTree();
node *findPrePos(node *p, int _id);
node *addNode(node *p, char ch, int id, int volume);
void print(node *p);
int postOrder(node *p);
void cleanUp(node *p);

int main()
{
	int id;
	node *root = makeTree();

	scanf("%d",&id);

	print(findPrePos(root,id));

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
void print(node *p)
{
	if (p != NULL)
		printf("%d\n",postOrder(p));
	else
		printf("-1\n");
}

// 후위 순회
int postOrder(node *p)
{
	if (p != NULL)
		return postOrder(p->left) + postOrder(p->right) + p->data;
	else
		return 0;
}

// 후위 순회로 동적 메모리 해제
void cleanUp(node *p)
{
	if (p->left != NULL)	{ cleanUp(p->left); }
	if (p->right != NULL)	{ cleanUp(p->right); }
	
	free(p);
}