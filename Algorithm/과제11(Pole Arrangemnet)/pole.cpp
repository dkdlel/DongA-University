//#include <bits/stdc++.h>
//#define MAX 21
//using namespace std;
//
//ifstream fcin("pole.inp");
//ofstream fcout("pole.out");
//
//class Pole {
//public:
//	long long int pole[21][21][21] = { 0 }; // ����� �迭
//	void Sol(int num, int left, int right);
//};
//void Pole::Sol(int num, int left, int right) {
//	if (num == 1) { // pole = 1
//		if (left == 1 && right == 1) fcout << "1\n";
//		else fcout << "0\n";
//		return;
//	}
//	else {
//		if (left == 1 && right == 1) { // ����Ⱑ �������δ� �Ѱ��� ���ϼ� ����
//			fcout << "0\n";
//			return;
//		}
//		if (left + right >= num + 2) { // ���� �Ұ�
//			fcout << "0\n";
//			return;
//		}
//
//		for (int i = 1; i <= num; i++) {
//			pole[i][i][1] = 1;
//			pole[i][1][i] = 1;
//		}
//
//		for (int i = 2; i <= num; i++) {
//			for (int j = 1; j <= left; j++) {
//				for (int k = 1; k <= right; k++) {
//					pole[i][j][k] = (pole[i - 1][j][k] * (i - 2)) + pole[i - 1][j - 1][k] + pole[i - 1][j][k - 1];
//					// (pole[i - 1][j][k] * (i - 2)) : ���̿� ���� �� �ִ� ���
//					// pole[i - 1][j - 1][k] : ���ʿ� �߰� �� �� �ִ� ���
//					// pole[i - 1][j][k - 1] : �����ʿ� �߰� �� �� �ִ� ���
//				}
//			}
//		}
//		fcout << pole[num][left][right] << '\n';
//	}
//}
//int main() {
//
//	Pole pole;
//	int testcase;
//	fcin >> testcase;
//	for(int i = 0 ; i < testcase ; i++) {
//		int num, left, right; // num : ����� ��, left : ���ʿ��� ������, right : �����ʿ��� ������
//		fcin >> num >> left >> right;
//		pole.Sol(num, left, right);
//	}
//	return 0;
//}

#include <bits/stdc++.h>
#define MAX 21
using namespace std;

ifstream fcin("pole.inp");
ofstream fcout("pole.out");

long long int pole[MAX][MAX][MAX] = { 0 }; // ����� �迭

void Sol(int num, int left, int right) {
	if (num == 1) { // pole = 1
		if (left == 1 && right == 1) fcout << "1\n";
		else fcout << "0\n";
		return;
	}
	else {
		if (left == 1 && right == 1) { // ����Ⱑ �������δ� �Ѱ��� ���ϼ� ����
			fcout << "0\n";
			return;
		}
		if (left + right >= num + 2) { // ���� �Ұ�
			fcout << "0\n";
			return;
		}

		for (int i = 1; i <= num; i++) {
			pole[i][i][1] = 1;
			pole[i][1][i] = 1;
		}

		for (int i = 2; i <= num; i++) {
			for (int j = 1; j <= left; j++) {
				for (int k = 1; k <= right; k++) {
					pole[i][j][k] = (pole[i - 1][j][k] * (i - 2)) + pole[i - 1][j - 1][k] + pole[i - 1][j][k - 1];
					// (pole[i - 1][j][k] * (i - 2)) : ���̿� ���� �� �ִ� ���
					// pole[i - 1][j - 1][k] : ���ʿ� �߰� �� �� �ִ� ���
					// pole[i - 1][j][k - 1] : �����ʿ� �߰� �� �� �ִ� ���
				}
			}
		}
		fcout << pole[num][left][right] << '\n';
	}
}
int main() {

	int testcase;
	fcin >> testcase;
	while (testcase--) {
		int num, left, right; // num : ����� ��, left : ���ʿ��� ������, right : �����ʿ��� ������
		fcin >> num >> left >> right;
		Sol(num, left, right);
	}
	return 0;
}