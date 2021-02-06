#include <stdio.h>
#include <stdlib.h>

FILE *inp, *out;

typedef struct treeNode // Ʈ����� ����ü ����
{
	int key;
	struct treeNode *left;
	struct treeNode *right;
}treeNode;

treeNode* insertNode(treeNode *root, int x) // x�� ���� ���� Ʈ��
{
	if (root == NULL) // ��Ʈ�� ���
	{
		root = (treeNode*)malloc(sizeof(treeNode));
		root->key = x;
		root->left = NULL;
		root->right = NULL;
		return root;
	}
	else if (x > root->key) root->left = insertNode(root->left, x); // �����ϴ� ���� �� Ŭ��� ���� ����
	else if (x < root->key) root->right = insertNode(root->right, x); // �����ϴ� ���� �� ������� ������ ����

	return root;
}

void deleteNode(treeNode *root, int key) // key�� ���� ���� Ʈ��
{
	treeNode *parent, *p, *succ, *succ_parent, *child;
	parent = NULL;
	p = root;
	while ((p != NULL) && (p->key != key)) // ������ ����� ��ġ Ž��
	{
		parent = p;
		if (key < p->key) p = p->right;
		else p = p->left;
	}
	if (p == NULL) // ������ ��尡 ���� ���
	{
		return;
	}

	if ((p->left == NULL) && (p->right == NULL)) // ������ ��尡 �ܸ� ����� ���
	{
		if (parent != NULL)
		{
			if (parent->left == p) parent->left = NULL;
			else parent->right = NULL;
		}
		else root = NULL;
	}

	else if ((p->left == NULL) || (p->right == NULL)) // ������ ��尡 �Ѱ��� �ڽ� ��带 ���� ���
	{
		if (p->left != NULL) child = p->left;
		else child = p->right;

		if (parent != NULL)
		{
			if (parent->left == p) parent->left = child;
			else parent->right = child;
		}
		else root = child;
	}

	else // ������ ��尡 �� ���� �ڽ� ��带 ���� ���
	{
		succ_parent = p;
		succ = p->left;
		while (succ->right != NULL)
		{
			succ_parent = succ;
			succ = succ->right;
		}
		if (succ_parent->left == succ) succ_parent->left = succ->left;
		else succ_parent->right = succ->left;
		p->key = succ->key;
		p = succ;
	}
	free(p);
}

treeNode *searchBST(treeNode *root, int x) // Ű���� x�� ��� ��ġ Ž��
{
	treeNode *p;
	p = root;
	while (p != NULL)
	{
		if (x < p->key)
		{
			fprintf(out, "%d ", p->key);
			p = p->right;
			if (p == NULL) fprintf(out, "\nNo");
		}
		else if (x == p->key)
		{
			fprintf(out, "%d\nYes",p->key);
			return p;
		}
		else if (x > p->key)
		{
			fprintf(out, "%d ", p->key);
			p = p->left;
			if (p == NULL) fprintf(out, "\nNo");
		}
	}
	return p;
}

void preorder(treeNode *root) // ���� ��ȸ ���
{
	if (root)
	{
		fprintf(out, "%d ", root->key);
		preorder(root->left);
		preorder(root->right);
	}
}

int main()
{
	inp = fopen("hw4.inp", "rt");
	out = fopen("hw4.out", "wt");

	treeNode *root = NULL;
	int num;
	char ch;
	
	while (1) // ����
	{
		fscanf(inp, "%d", &num);
		fscanf(inp, "%c", &ch);
		if (ch == '\n')
		{
			root = insertNode(root, num);
			break;
		}
		root = insertNode(root, num);
	}
	preorder(root);
	fprintf(out, "\n");

	while (1) // ����
	{
		fscanf(inp, "%d", &num);
		fscanf(inp, "%c", &ch);
		if (ch == '\n')
		{
			deleteNode(root, num);
			break;
		}
		deleteNode(root, num);
	}
	preorder(root);
	fprintf(out, "\n");

	fscanf(inp, "%d", &num); // Ž��
	searchBST(root, num);

	fprintf(out, "\n*");

	fclose(inp);
	fclose(out);

	return 0;
}