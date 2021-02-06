#include <stdio.h>
#include <stdlib.h>

FILE *inp, *out;

typedef struct treeNode // 트리노드 구조체 선언
{
	int key;
	struct treeNode *left;
	struct treeNode *right;
}treeNode;

treeNode* insertNode(treeNode *root, int x) // x값 삽입 연산 트리
{
	if (root == NULL) // 루트일 경우
	{
		root = (treeNode*)malloc(sizeof(treeNode));
		root->key = x;
		root->left = NULL;
		root->right = NULL;
		return root;
	}
	else if (x > root->key) root->left = insertNode(root->left, x); // 삽입하는 값이 더 클경우 왼쪽 삽입
	else if (x < root->key) root->right = insertNode(root->right, x); // 삽입하는 값디 더 작을경우 오른쪽 삽입

	return root;
}

void deleteNode(treeNode *root, int key) // key값 삭제 연산 트리
{
	treeNode *parent, *p, *succ, *succ_parent, *child;
	parent = NULL;
	p = root;
	while ((p != NULL) && (p->key != key)) // 삭제할 노드의 위치 탐색
	{
		parent = p;
		if (key < p->key) p = p->right;
		else p = p->left;
	}
	if (p == NULL) // 삭제할 노드가 없는 경우
	{
		return;
	}

	if ((p->left == NULL) && (p->right == NULL)) // 삭제할 노드가 단말 노드인 경우
	{
		if (parent != NULL)
		{
			if (parent->left == p) parent->left = NULL;
			else parent->right = NULL;
		}
		else root = NULL;
	}

	else if ((p->left == NULL) || (p->right == NULL)) // 삭제할 노드가 한개의 자식 노드를 가진 경우
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

	else // 삭제할 노드가 두 개의 자식 노드를 가진 경우
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

treeNode *searchBST(treeNode *root, int x) // 키값이 x인 노드 위치 탐색
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

void preorder(treeNode *root) // 전위 순회 출력
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
	
	while (1) // 삽입
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

	while (1) // 삭제
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

	fscanf(inp, "%d", &num); // 탐색
	searchBST(root, num);

	fprintf(out, "\n*");

	fclose(inp);
	fclose(out);

	return 0;
}