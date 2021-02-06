//#include <bits/stdc++.h>
//#define MAX 21
//using namespace std;
//
//ifstream fcin("pole.inp");
//ofstream fcout("pole.out");
//
//class Pole {
//public:
//	long long int pole[21][21][21] = { 0 }; // 계산할 배열
//	void Sol(int num, int left, int right);
//};
//void Pole::Sol(int num, int left, int right) {
//	if (num == 1) { // pole = 1
//		if (left == 1 && right == 1) fcout << "1\n";
//		else fcout << "0\n";
//		return;
//	}
//	else {
//		if (left == 1 && right == 1) { // 막대기가 여러개인대 한개만 보일수 없음
//			fcout << "0\n";
//			return;
//		}
//		if (left + right >= num + 2) { // 성립 불가
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
//					// (pole[i - 1][j][k] * (i - 2)) : 사이에 들어올 수 있는 경우
//					// pole[i - 1][j - 1][k] : 왼쪽에 추가 될 수 있는 경우
//					// pole[i - 1][j][k - 1] : 오른쪽에 추가 될 수 있는 경우
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
//		int num, left, right; // num : 블록의 수, left : 왼쪽에서 봤을때, right : 오른쪽에서 봤을때
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

long long int pole[MAX][MAX][MAX] = { 0 }; // 계산할 배열

void Sol(int num, int left, int right) {
	if (num == 1) { // pole = 1
		if (left == 1 && right == 1) fcout << "1\n";
		else fcout << "0\n";
		return;
	}
	else {
		if (left == 1 && right == 1) { // 막대기가 여러개인대 한개만 보일수 없음
			fcout << "0\n";
			return;
		}
		if (left + right >= num + 2) { // 성립 불가
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
					// (pole[i - 1][j][k] * (i - 2)) : 사이에 들어올 수 있는 경우
					// pole[i - 1][j - 1][k] : 왼쪽에 추가 될 수 있는 경우
					// pole[i - 1][j][k - 1] : 오른쪽에 추가 될 수 있는 경우
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
		int num, left, right; // num : 블록의 수, left : 왼쪽에서 봤을때, right : 오른쪽에서 봤을때
		fcin >> num >> left >> right;
		Sol(num, left, right);
	}
	return 0;
}