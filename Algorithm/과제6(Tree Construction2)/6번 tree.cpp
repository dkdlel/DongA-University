#include <fstream>
#define MAX 10001
using namespace std;

ifstream fcin("tree2.inp");
ofstream fcout("tree2.out");
enum Traversal { preorder = -1, inorder, postorder }; // preorder : ����(-1), inorder : ����(0), postorder : ����(1)

typedef struct inf {
	int node_num;
	bool check;
}inf;

inf inorder_traversal[MAX]; // ���� ��ȸ
inf traversal[MAX]; // ���� or ���� ��ȸ

int node_cnt, traversal_type, node_num, check_traversal; // �Է¿�
int left_cnt, right_cnt, index; // ����

void Preorder(int root, int right_cnt, int left_cnt) {
	// ������ �Ѿ�� �׳� ����
	if (root < 0) return;
	for (int i = 1; i <= node_cnt; i++) {
		// ������ȸ���� ���� ��Ʈ�� ���� ������ȸ�� ��� ��ġ �ϴ°�
		if (inorder_traversal[i].node_num == traversal[root].node_num) {
			index = i;
			inorder_traversal[index].check = true;
			break;
		}
	}

	// ��������̸�
	if (inorder_traversal[index - 1].check == true && inorder_traversal[index + 1].check == true) {
		inorder_traversal[index].check = true;
		fcout << traversal[root].node_num << '\n';
		return;
	}

	left_cnt = 0;
	// ���� ����
	for (int i = index - 1; i >= 0; i--) {
		if (inorder_traversal[i].check == true) break;
		left_cnt++;
	}

	right_cnt = 0;
	// ������ ����
	for (int i = index + 1; i <= node_cnt; i++) {
		if (inorder_traversal[i].check == true) break;
		right_cnt++;
	}

	fcout << traversal[root].node_num << '\n';

	if (left_cnt != 0)
		// ���� ��ȸ
		Preorder(root - right_cnt - 1, right_cnt, left_cnt);
	if (right_cnt != 0)
		// ������ ��ȸ
		Preorder(root - 1, right_cnt, left_cnt);

	return;

}

void Postorder(int root, int left_cnt, int right_cnt) {

	// ������ �Ѿ�� �׳� ����
	if (root > node_cnt) return;
	for (int i = 1; i <= node_cnt; i++) {
		// ������ȸ���� ���� ��Ʈ�� ���� ������ȸ�� ��� ��ġ �ϴ°�
		if (inorder_traversal[i].node_num == traversal[root].node_num) {
			index = i;
			inorder_traversal[index].check = true;
			break;
		}
	}

	// ��������̸�
	if (inorder_traversal[index - 1].check == true && inorder_traversal[index + 1].check == true) {
		inorder_traversal[index].check = true;
		fcout << traversal[root].node_num << '\n';
		return;
	}

	left_cnt = 0;
	// ���� ����
	for (int i = index - 1; i >= 0; i--) {
		if (inorder_traversal[i].check == true) break;
		left_cnt++;
	}

	right_cnt = 0;
	// ������ ����
	for (int i = index + 1; i <= node_cnt; i++) {
		if (inorder_traversal[i].check == true) break;
		right_cnt++;
	}

	if (left_cnt != 0)
		// ���� ��ȸ
		Postorder(root + 1, left_cnt, right_cnt);
	if (right_cnt != 0)
		// ������ ��ȸ
		Postorder(root + left_cnt + 1, left_cnt, right_cnt);

	fcout << traversal[root].node_num << '\n';
	return;
}

int main() {

	fcin >> node_cnt;

	for (int t = 0; t < 2; t++) {

		fcin >> traversal_type;
		// 0 �̸� 
		if (traversal_type == inorder) {
			for (int i = 1; i <= node_cnt; i++) {
				fcin >> node_num;
				inorder_traversal[i].node_num = node_num;
			}
		}
		// 1, -1 �̸�
		else {
			check_traversal = traversal_type;
			for (int i = 1; i <= node_cnt; i++) {
				fcin >> node_num;
				traversal[i].node_num = node_num;
			}
		}
	}
	inorder_traversal[0].check = true; inorder_traversal[node_cnt + 1].check = true;
	// ���� ��ȸ�� �Է� �޾����� ���� ��ȸ
	if (check_traversal == preorder) Postorder(1, 0, 0);
	// ���� ��ȸ�� �Է� �޾����� ���� ��ȸ
	else if (check_traversal == postorder) Preorder(node_cnt, 0, 0);



	fcin.close();
	fcout.close();
	return 0;
}