#include <stdio.h>
#include <stdlib.h>

FILE *inp = fopen("hw4.inp", "rt");
FILE *out = fopen("hw4.out", "wt");

int num; char enter;
// ����ü ����
typedef struct AVL_Node {
	int key;
	struct AVL_Node *left, *right;
}AVL_Node;

// LL ȸ��
AVL_Node *LL(AVL_Node *parent){
	AVL_Node *child = parent->left;
	parent->left = child->right;
	child->right = parent;
	return child;
}
// RR ȸ��
AVL_Node *RR(AVL_Node *parent){
	AVL_Node *child = parent->right;
	parent->right = child->left;
	child->left = parent;
	return child;
}
// LR ȸ��
AVL_Node *LR(AVL_Node *parent){
	AVL_Node *child = parent->left;
	parent->left = RR(child);
	return LL(parent);
}
// RL ȸ��
AVL_Node *RL(AVL_Node *parent){
	AVL_Node *child = parent->right;
	parent->right = LL(child);
	return RR(parent);
}
//Ʈ�����̸� ��ȯ
int Get_Height(AVL_Node* node){
	int height = 0;
	// �ؿ� �ڽ��� ������
	if (node != NULL)
	{
		// ���� ���̰� �� ũ��
		if (Get_Height(node->left) > Get_Height(node->right)) {
			// 1�� ���ؾ� ��, index �����ϴ°Ŷ� ����ѵ�
			height = Get_Height(node->left) + 1;
		}
		else {
			height = Get_Height(node->right) + 1;
		}
		return height;
	}
	// �ڽ��� ������ ���̴� 0
	return 0;
}
//�����μ� ���ϱ�
int Balance_Factor(AVL_Node *node){
	if (node == NULL)return 0;
	// ���� ����Ʈ�� ���� - ������ ����Ʈ�� ����
	return Get_Height(node->left) - Get_Height(node->right);
}
// ���� ���߱�
AVL_Node *Balance(AVL_Node *node){
	// ���� ����
	int balance_difference = Balance_Factor(node);
	// 1�̻��̸�
	if (balance_difference > 1){
		// ���� ����Ʈ������ �����
		if (Balance_Factor((node)->left) > 0) node = LL(node);
		else node = LR(node);
	}
	// 1�����̸�
	else if (balance_difference < -1){
		// ������ ����Ʈ������ �����̸�
		if (Balance_Factor((node)->right) < 0) node = RR(node);
		else node = RL(node);
	}
	return node;
}
// AVLƮ���� ����
AVL_Node *Insert_AVL(AVL_Node *root, int new_key){
	// �ƹ��͵� ���� �ȵ�������
	if (root == NULL){
		root = (AVL_Node *)malloc(sizeof(AVL_Node));
		root->key = new_key;
		root->left = root->right = NULL;
	}
	// ���ʿ� ����
	else if (new_key < root->key){
		root->left = Insert_AVL(root->left, new_key);
		root = Balance(root);
	}
	// �����ʿ� ����
	else if (new_key > root->key){
		root->right = Insert_AVL(root->right, new_key);
		root = Balance(root);
	}
	return root;
}
// key�� ���� ���� Ʈ��
AVL_Node *Delete_AVL(AVL_Node *root, int new_key){ 
	AVL_Node *parent, *p, *succ, *succ_parent, *child;
	parent = NULL;
	p = root;
	// ������ ��带 ���� ��� // �����ؼ� �׋� ������ ���絵 ������ �������� ������ ��ͷ�
	if (root == NULL) // ������ ��尡 ���� ���
		return root;
	else if (new_key < root->key) // Ű���� ���� ���
		root->left = Delete_AVL(root->left, new_key);
	else if (new_key > root->key)// Ű���� Ŭ ���
		root->right = Delete_AVL(root->right, new_key);
	// Ű ���� ã�� ���
	else { 
		// ������ ��尡 �ܸ� ����� ���
		if ((p->left == NULL) && (p->right == NULL)) {
			// �θ� ������
			if (parent != NULL) {
				if (parent->right == p) parent->right = NULL;
				else parent->left = NULL;
				return parent;
			}
			// �θ� ������
			else {
				root = NULL;
				return root;
			}
		}
		// ������ ��尡 �Ѱ��� �ڽ� ��带 ���� ���
		else if ((p->left == NULL) || (p->right == NULL)) {

			if (p->left != NULL) child = p->left;
			else child = p->right;

			if (parent != NULL) {
				if (parent->left == p) parent->left = child;
				else parent->right = child;
				return parent;
			}
			else {
				root = child;
				return root;
			}
		}
		// ������ ��尡 �� ���� �ڽ� ��带 ���� ���
		else {
			succ_parent = p;
			succ = p->left;
			while (succ->right != NULL) {
				succ_parent = succ;
				succ = succ->right;
			}
			if (succ_parent->left == succ) succ_parent->left = succ->left;
			else succ_parent->right = succ->left;
			p->key = succ->key;
		}
	}

	root = Balance(root);
	return root;
}

void Preorder(AVL_Node *root) {

	if (root != NULL) {
		//�ڽ��� ����ϰ�
		fprintf(out, "%d ", root->key);
		//���� �湮
		Preorder(root->left);
		//���������� ������ �湮
		Preorder(root->right);
	}
}

int main() {

	if ((inp = fopen("hw4.inp", "rt")) == NULL) fprintf(stderr, "cant't open %s\n", "hw4.inp");
	if ((out = fopen("hw4.out", "wt")) == NULL) fprintf(stderr, "cant't open %s\n", "hw4.out");

	AVL_Node *root = NULL;

	while (1) {
		fscanf(inp, "%d%c", &num, &enter);
		root = Insert_AVL(root, num);
		if (enter == '\n') {
			Preorder(root);
			fprintf(out, "\n");
			break;
		}
	}

	while (1) {
		fscanf(inp, "%d%c", &num, &enter);
		root = Delete_AVL(root, num);
		if (enter == '\n') {
			Preorder(root);
			fprintf(out, "\n");
			break;
		}
	}

	fprintf(out, "*");
	fclose(inp);
	fclose(out);
	return 0;
}