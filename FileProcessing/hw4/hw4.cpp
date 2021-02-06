#include <stdio.h>
#include <stdlib.h>

FILE *inp = fopen("hw4.inp", "rt");
FILE *out = fopen("hw4.out", "wt");

int num; char enter;
// 구조체 선언
typedef struct AVL_Node {
	int key;
	struct AVL_Node *left, *right;
}AVL_Node;

// LL 회전
AVL_Node *LL(AVL_Node *parent){
	AVL_Node *child = parent->left;
	parent->left = child->right;
	child->right = parent;
	return child;
}
// RR 회전
AVL_Node *RR(AVL_Node *parent){
	AVL_Node *child = parent->right;
	parent->right = child->left;
	child->left = parent;
	return child;
}
// LR 회전
AVL_Node *LR(AVL_Node *parent){
	AVL_Node *child = parent->left;
	parent->left = RR(child);
	return LL(parent);
}
// RL 회전
AVL_Node *RL(AVL_Node *parent){
	AVL_Node *child = parent->right;
	parent->right = LL(child);
	return RR(parent);
}
//트리높이를 반환
int Get_Height(AVL_Node* node){
	int height = 0;
	// 밑에 자식이 있으면
	if (node != NULL)
	{
		// 왼쪽 높이가 더 크면
		if (Get_Height(node->left) > Get_Height(node->right)) {
			// 1씩 더해야 함, index 참조하는거랑 비슷한듯
			height = Get_Height(node->left) + 1;
		}
		else {
			height = Get_Height(node->right) + 1;
		}
		return height;
	}
	// 자식이 없으면 높이는 0
	return 0;
}
//균형인수 구하기
int Balance_Factor(AVL_Node *node){
	if (node == NULL)return 0;
	// 왼쪽 서브트리 높이 - 오른쪽 서브트리 높이
	return Get_Height(node->left) - Get_Height(node->right);
}
// 균형 맞추기
AVL_Node *Balance(AVL_Node *node){
	// 균형 차이
	int balance_difference = Balance_Factor(node);
	// 1이상이면
	if (balance_difference > 1){
		// 왼쪽 서브트리에서 양수면
		if (Balance_Factor((node)->left) > 0) node = LL(node);
		else node = LR(node);
	}
	// 1이하이면
	else if (balance_difference < -1){
		// 오른쪽 서브트리에서 음수이면
		if (Balance_Factor((node)->right) < 0) node = RR(node);
		else node = RL(node);
	}
	return node;
}
// AVL트리에 삽입
AVL_Node *Insert_AVL(AVL_Node *root, int new_key){
	// 아무것도 삽입 안되있으면
	if (root == NULL){
		root = (AVL_Node *)malloc(sizeof(AVL_Node));
		root->key = new_key;
		root->left = root->right = NULL;
	}
	// 왼쪽에 삽입
	else if (new_key < root->key){
		root->left = Insert_AVL(root->left, new_key);
		root = Balance(root);
	}
	// 오른쪽에 삽입
	else if (new_key > root->key){
		root->right = Insert_AVL(root->right, new_key);
		root = Balance(root);
	}
	return root;
}
// key값 삭제 연산 트리
AVL_Node *Delete_AVL(AVL_Node *root, int new_key){ 
	AVL_Node *parent, *p, *succ, *succ_parent, *child;
	parent = NULL;
	p = root;
	// 삭제할 노드를 위해 재귀 // 삭제해서 그떄 균형을 맞춰도 위에가 깨질수도 있으니 재귀로
	if (root == NULL) // 삭제할 노드가 없는 경우
		return root;
	else if (new_key < root->key) // 키값이 작을 경우
		root->left = Delete_AVL(root->left, new_key);
	else if (new_key > root->key)// 키값이 클 경우
		root->right = Delete_AVL(root->right, new_key);
	// 키 값을 찾은 경우
	else { 
		// 삭제할 노드가 단말 노드인 경우
		if ((p->left == NULL) && (p->right == NULL)) {
			// 부모가 있으면
			if (parent != NULL) {
				if (parent->right == p) parent->right = NULL;
				else parent->left = NULL;
				return parent;
			}
			// 부모가 없으면
			else {
				root = NULL;
				return root;
			}
		}
		// 삭제할 노드가 한개의 자식 노드를 가진 경우
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
		// 삭제할 노드가 두 개의 자식 노드를 가진 경우
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
		//자신을 출력하고
		fprintf(out, "%d ", root->key);
		//왼쪽 방문
		Preorder(root->left);
		//마지막으로 오른쪽 방문
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