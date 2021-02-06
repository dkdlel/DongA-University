#include<bits/stdc++.h>
using namespace std;

ifstream fcin("pandora.inp");
ofstream fcout("pandora.out");
// 0 : �Ʒ�, 1 : ������, 2 : ��, 3 : ����
class Pandora {
public:
	int x_axis, y_axis, dir; // x��, y��, dir : ����
	string str;
	void Sol();
};
//void Pandora::Sol() {
//	fcin >> str;
//	x_axis = y_axis = 1; dir = 0; // �ʱ�ȭ
//	// ����� R�� ��� ���� �� �� �ֱ� ������
//	str += str[0];
//	str += str[1];
//	for (int i = 0; i < str.size() - 1; i++) {
//		if (str[i] == 'R' && str[i + 1] == 'R') {
//			if (dir & 1) x_axis = 0; // ��������� ���� �������̰�, ������ 270���� ��� x ������ ����
//			else y_axis = 0; // ��������� ���� �Ʒ����̰�, ������ 270���� ��� y ������ ����
//		}
//		dir = str[i] == 'L' ? (dir + 3) % 4 : (dir + 1) % 4;
//		// +3�� �ϸ� ��������(90��) ȸ��, +1�� �ϸ� �ٱ�������(270��) ȸ��
//	}
//}
void Pandora::Sol() {
	fcin >> str;
	x_axis = y_axis = 1; dir = 0; // �ʱ�ȭ
	for (int i = 0; i < str.size(); i++) {
		int j = (i + 1) % str.size(); // ����� R�� ��� ���� �� �� �ֱ� ������
		if (str[i] == 'R' && str[j] == 'R') {
			if (dir & 1) x_axis = 0; // ��������� ���� �������̰�, ������ 270���� ��� x ������ ����
			else y_axis = 0; // ��������� ���� �Ʒ����̰�, ������ 270���� ��� y ������ ����
		}
		dir = str[i] == 'L' ? (dir + 3) % 4 : (dir + 1) % 4;
		// +3�� �ϸ� ��������(90��) ȸ��, +1�� �ϸ� �ٱ�������(270��) ȸ��
	}
}
int main() {

	Pandora pan;
	int testcase, j;
	fcin >> testcase;
	while (testcase--) {
		pan.Sol();
		fcout << pan.x_axis + pan.y_axis << '\n';
	}
	return 0;
}