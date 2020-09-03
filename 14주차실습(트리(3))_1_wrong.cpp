#include <stdio.h>
#include <stdlib.h>

typedef struct BinaryTree
{
	int id;
	struct BinaryTree *left;
	struct BinaryTree *right;
} node;

node *root;
node *arr[3000];
int cnt;

node *getNode();
node*find(int id);
void addNode(int x, int y, int z);
void print(char *course);

int main()
{
	int i;
	int n, s;
	int x, y, z;
	char course[101];

	root = NULL;

	scanf("%d",&n);

	for (i=0; i<n; i++) {
		scanf("%d %d %d",&x,&y,&z);
		addNode(x,y,z);
	}

	scanf("%d",&s);

	for (i=0; i<s; i++) {
		getchar();
		scanf("%s",course);

		print(course);
		puts("");
	}

	return 0;
}

node *getNode()
{
	node *nw = (node*)malloc(sizeof(node));

	nw->id = 0;
	nw->left = NULL;
	nw->right = NULL;

	return nw;
}

node *find(int id)
{
	int i;

	for (i=0; i<cnt; i++)
		if (arr[i]->id == id)
			return arr[i];
}

void addNode(int x, int y, int z)
{
	node *left = NULL;
	node *right = NULL;

	if (y) {
		left = getNode();
		left->id = y;
		arr[cnt++] = left;
	}

	if (z) {
		right = getNode();
		right->id = z;
		arr[cnt++] = right;
	}

	if (root == NULL)
	{
		root = getNode();
		root->id = x;
		root->left = left;
		root->right = right;
		arr[cnt++] = root;
	}
	else
	{
		node *p = find(x);
		p->left = left;
		p->right = right;
	}
}

void print(char *course)
{
	int i = 0;
	node* p=root;

if (p!=NULL)
	printf(" %d",p->id);

	while (p!= NULL && course[i])
	{
		if (course[i] == 'R')
			p = p->right;
		else if (course[i] == 'L')
			p = p->left;

		if (p != NULL)
		printf(" %d",p->id);

		i++;
	}
}