#include<bits/stdc++.h>
using namespace std;

ifstream fcin("card.inp");
ofstream fcout("card.out");

class Card {
public:
	int num;
	int vec[1001]; // 입력 받는 벡터
	int cal_vec[3][1001]; // 계산을 위한 벡터
	void Input();
	void Sol();
};
void Card::Input() { // input 및 초기화
	fcin >> num;
	for (int i = 0; i < num; i++) fcin >> vec[i];
	for (int i = 0; i < 3; i++) {
		cal_vec[0][i] = cal_vec[1][i] = cal_vec[2][i] = vec[i];
	}
	cal_vec[0][2] = -999999;
	cal_vec[0][3] = vec[3] + cal_vec[0][1];
	cal_vec[1][3] = vec[3] + cal_vec[0][0];
	cal_vec[2][3] = -999999;
}
void Card::Sol() {
	for (int i = 4; i < num; i++) {
		cal_vec[0][i] = vec[i] + max(cal_vec[1][i - 2], cal_vec[2][i - 2]);
		cal_vec[1][i] = vec[i] + max(cal_vec[0][i - 3], max(cal_vec[1][i - 3], cal_vec[2][i - 3]));
		cal_vec[2][i] = vec[i] + max(cal_vec[0][i - 4], max(cal_vec[1][i - 4], cal_vec[2][i - 4]));
	}
}
int main() {

	Card card;
	int testcase;
	fcin >> testcase;

	while (testcase--) {
		card.Input();
		card.Sol();
		fcout << max(card.cal_vec[0][card.num-1], max(card.cal_vec[1][card.num-1], card.cal_vec[2][card.num-1])) << '\n';
	}
	return 0;
}