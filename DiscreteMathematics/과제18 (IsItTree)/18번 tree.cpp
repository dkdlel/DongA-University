#include <fstream>
#include <algorithm>
#define MAX 1000001
using namespace std;

ifstream fcin("tree.inp");
ofstream fcout("tree.out");

int Parent[MAX];
int Child[MAX];
int P_cnt = 0, C_cnt = 0, R_cnt = 0;
int start_node, end_node, root = -1; // start_node : ���� �Է°�, start_node : ������ �Է°�, root ��
int T = 1;

void check() {
	int cnt = 0; R_cnt = 0;
	// Parent �迭�� �ִ� ���� Child �迭�� �ִ��� Ȯ��
	for (int i = cnt; i < P_cnt; i++) {
		// �������� ���
		if (Parent[i + 1] == 0) {
			// �� ���� child �迭�� ���� �ϴ°�?
			// ���� ���� �ʴ� �ٸ�
			if (!binary_search(Child, Child + C_cnt, Parent[i])) {
				root = Parent[i];
				R_cnt++;
			}
		}
		// Parent �迭 ���� ���� ��
		else if (Parent[i] == Parent[i + 1]) {
			cnt++;
			continue;
		}
		// Parent �迭�� ���� Child �迭�� ���� ���� ������
		// root�� �� �� ����
		else if (!binary_search(Child, Child + C_cnt, Parent[i])) {
			root = Parent[i];
			R_cnt++;
		}
	}
}
void tree() {

	int check_num = 0;
	// �ΰ��� �迭 ����
	sort(Parent, Parent + P_cnt);
	sort(Child, Child + C_cnt);

	// Child �迭�� �ߺ��� ���� �ִ��� Ȯ��
	for (int i = 0; i < C_cnt - 1; i++) {
		// ������ ������ -1 ���
		if (Child[i] == Child[i + 1]) {
			check_num++;
			fcout << "Test Case " << T << ": " << "-1" << endl;
		}
	}
	if (check_num != 1) {
		// Parent �迭�� Child �迭 ��
		check();
		// ��Ʈ ��尡 �ϳ��� ���
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
			break; // while�� break
		else if (start_node == 0 && end_node == 0) {
			// ���� ����
			tree();
			for (int j = 0; j < P_cnt; j++) {
				Parent[j] = 0;
				Child[j] = 0;
			}
			i = 0; P_cnt = 0; C_cnt = 0; root = -1; T++;
		}
		// �ΰ��� ������ ���
		else {
			Parent[i] = start_node;
			Child[i] = end_node;
			i++; P_cnt++; C_cnt++;
		}
	}
	return 0;
}