#include <fstream>
#define MAX 10001
using namespace std;

ifstream fcin("tree2.inp");
ofstream fcout("tree2.out");
enum Traversal { preorder = -1, inorder, postorder }; // preorder : 전위(-1), inorder : 중위(0), postorder : 후위(1)

typedef struct inf {
	int node_num;
	bool check;
}inf;

inf inorder_traversal[MAX]; // 중위 순회
inf traversal[MAX]; // 전위 or 후위 순회

int node_cnt, traversal_type, node_num, check_traversal; // 입력용
int left_cnt, right_cnt, index; // 계산용

void Preorder(int root, int right_cnt, int left_cnt) {
	// 범위가 넘어가면 그냥 리턴
	if (root < 0) return;
	for (int i = 1; i <= node_cnt; i++) {
		// 전위순회에서 나온 루트의 값이 중위순회에 어디에 위치 하는가
		if (inorder_traversal[i].node_num == traversal[root].node_num) {
			index = i;
			inorder_traversal[index].check = true;
			break;
		}
	}

	// 리프노드이면
	if (inorder_traversal[index - 1].check == true && inorder_traversal[index + 1].check == true) {
		inorder_traversal[index].check = true;
		fcout << traversal[root].node_num << '\n';
		return;
	}

	left_cnt = 0;
	// 왼쪽 길이
	for (int i = index - 1; i >= 0; i--) {
		if (inorder_traversal[i].check == true) break;
		left_cnt++;
	}

	right_cnt = 0;
	// 오른쪽 길이
	for (int i = index + 1; i <= node_cnt; i++) {
		if (inorder_traversal[i].check == true) break;
		right_cnt++;
	}

	fcout << traversal[root].node_num << '\n';

	if (left_cnt != 0)
		// 왼쪽 순회
		Preorder(root - right_cnt - 1, right_cnt, left_cnt);
	if (right_cnt != 0)
		// 오른쪽 순회
		Preorder(root - 1, right_cnt, left_cnt);

	return;

}

void Postorder(int root, int left_cnt, int right_cnt) {

	// 범위가 넘어가면 그냥 리턴
	if (root > node_cnt) return;
	for (int i = 1; i <= node_cnt; i++) {
		// 전위순회에서 나온 루트의 값이 중위순회에 어디에 위치 하는가
		if (inorder_traversal[i].node_num == traversal[root].node_num) {
			index = i;
			inorder_traversal[index].check = true;
			break;
		}
	}

	// 리프노드이면
	if (inorder_traversal[index - 1].check == true && inorder_traversal[index + 1].check == true) {
		inorder_traversal[index].check = true;
		fcout << traversal[root].node_num << '\n';
		return;
	}

	left_cnt = 0;
	// 왼쪽 길이
	for (int i = index - 1; i >= 0; i--) {
		if (inorder_traversal[i].check == true) break;
		left_cnt++;
	}

	right_cnt = 0;
	// 오른쪽 길이
	for (int i = index + 1; i <= node_cnt; i++) {
		if (inorder_traversal[i].check == true) break;
		right_cnt++;
	}

	if (left_cnt != 0)
		// 왼쪽 순회
		Postorder(root + 1, left_cnt, right_cnt);
	if (right_cnt != 0)
		// 오른쪽 순회
		Postorder(root + left_cnt + 1, left_cnt, right_cnt);

	fcout << traversal[root].node_num << '\n';
	return;
}

int main() {

	fcin >> node_cnt;

	for (int t = 0; t < 2; t++) {

		fcin >> traversal_type;
		// 0 이면 
		if (traversal_type == inorder) {
			for (int i = 1; i <= node_cnt; i++) {
				fcin >> node_num;
				inorder_traversal[i].node_num = node_num;
			}
		}
		// 1, -1 이면
		else {
			check_traversal = traversal_type;
			for (int i = 1; i <= node_cnt; i++) {
				fcin >> node_num;
				traversal[i].node_num = node_num;
			}
		}
	}
	inorder_traversal[0].check = true; inorder_traversal[node_cnt + 1].check = true;
	// 전위 순회를 입력 받았으면 후위 순회
	if (check_traversal == preorder) Postorder(1, 0, 0);
	// 후위 순회를 입력 받았으면 전위 순회
	else if (check_traversal == postorder) Preorder(node_cnt, 0, 0);



	fcin.close();
	fcout.close();
	return 0;
}