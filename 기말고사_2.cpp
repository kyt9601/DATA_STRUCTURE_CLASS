#include <stdio.h>
#include <stdlib.h>

typedef struct BinaryTree
{
	int id;
	struct BinaryTree *left;
	struct BinaryTree *right;
} node;

void addNode(node *root, int _id, char *way);
void visit(node *p);
void inOrder(node *p);
void postOrder(node *p);
void cleanUp(node *p);

node *getNode()
{
	node *nw = (node*)malloc(sizeof(node));

	nw->id = 0;
	nw->left = NULL;
	nw->right = NULL;

	return nw;
}

int main()
{
	int n, i;
	int _id;
	char way[101];
	node *root;

	root = getNode();
	root->id = 1;

	scanf("%d",&n);

	for (i=0; i<n-1; i++)
	{
		scanf("%d %s",&_id,way);

		addNode(root,_id,way);
	}

	inOrder(root); puts("");
	postOrder(root); puts("");

	cleanUp(root);

	return 0;
}

void addNode(node *root, int _id, char *way)
{
	int i;
	node *p = root;

	node *nw = getNode();
	nw->id = _id;

	for (i=0; way[i+1]; i++)
	{
		if (way[i] == 'L')
			p = p->left;
		else
			p = p->right;
	}

	if (way[i] == 'L')
		p->left = nw;
	else
		p->right = nw;
}

void visit(node *p)
{
	printf(" %d",p->id);
}

void inOrder(node *p)
{
	if (p->left != NULL) { inOrder(p->left); }
	visit(p);
	if (p->right != NULL) { inOrder(p->right); }
}

void postOrder(node *p)
{
	if (p->left != NULL) { postOrder(p->left); }
	if (p->right != NULL) { postOrder(p->right); }
	visit(p);
}

void cleanUp(node *p)
{
	if (p->left != NULL) { cleanUp(p->left); }
	if (p->right != NULL) { cleanUp(p->right); }
	free(p);
}