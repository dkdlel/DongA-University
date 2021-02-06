#include <fstream>
#include <algorithm>
#define MAX 1000001
using namespace std;

ifstream fcin("tree.inp");
ofstream fcout("tree.out");

int Parent[MAX];
int Child[MAX];
int P_cnt = 0, C_cnt = 0, R_cnt = 0;
int start_node, end_node, root = -1; // start_node : 왼쪽 입력값, start_node : 오른쪽 입력값, root 값
int T = 1;

void check() {
	int cnt = 0; R_cnt = 0;
	// Parent 배열에 있는 값이 Child 배열에 있는지 확인
	for (int i = cnt; i < P_cnt; i++) {
		// 마지막일 경우
		if (Parent[i + 1] == 0) {
			// 그 수가 child 배열에 존재 하는가?
			// 존재 하지 않는 다면
			if (!binary_search(Child, Child + C_cnt, Parent[i])) {
				root = Parent[i];
				R_cnt++;
			}
		}
		// Parent 배열 값이 같을 때
		else if (Parent[i] == Parent[i + 1]) {
			cnt++;
			continue;
		}
		// Parent 배열의 값이 Child 배열에 존재 하지 않으면
		// root가 될 수 있음
		else if (!binary_search(Child, Child + C_cnt, Parent[i])) {
			root = Parent[i];
			R_cnt++;
		}
	}
}
void tree() {

	int check_num = 0;
	// 두개의 배열 정렬
	sort(Parent, Parent + P_cnt);
	sort(Child, Child + C_cnt);

	// Child 배열에 중복된 값이 있는지 확인
	for (int i = 0; i < C_cnt - 1; i++) {
		// 같은게 있으면 -1 출력
		if (Child[i] == Child[i + 1]) {
			check_num++;
			fcout << "Test Case " << T << ": " << "-1" << endl;
		}
	}
	if (check_num != 1) {
		// Parent 배열과 Child 배열 비교
		check();
		// 루트 노드가 하나일 경우
		if (R_cnt == 1) {
			fcout << "Test Case " << T << ": " << root << endl;
		}
		else {
			fcout << "Test Case " << T << ": " << "-1" << endl;
		}
	}
}
int main() {
	
	int i = 0;

	while (1) {

		fcin >> start_node >> end_node;
		if (start_node == -1 && end_node == -1) 
			break; // while문 break
		else if (start_node == 0 && end_node == 0) {
			// 연산 시작
			tree();
			for (int j = 0; j < P_cnt; j++) {
				Parent[j] = 0;
				Child[j] = 0;
			}
			i = 0; P_cnt = 0; C_cnt = 0; root = -1; T++;
		}
		// 두개의 숫자일 경우
		else {
			Parent[i] = start_node;
			Child[i] = end_node;
			i++; P_cnt++; C_cnt++;
		}
	}
	return 0;
}