#include<bits/stdc++.h>
#define MAX 1001
using namespace std;

ifstream fcin("card.inp");
ofstream fcout("card.out");

int card[MAX];
int DP[MAX][MAX];

class Card {
public:
	int num;
	void Input();
	int Sol(int start, int end, bool turn);
};
void Card::Input() {
	fcin >> num;
	for (int i = 0; i < num; i++) {
		fcin >> card[i];
		for (int j = 0; j < num; j++) {
			DP[i][j] = -1;
		}
	}
}
int Card::Sol(int start, int end, bool turn) {
	int& result = DP[start][end];
	if (result != -1) {
		return result;
	}
	else if (start == end) {
		return result = turn ? card[start] : 0;
	}
	if (turn) {
		result = max(card[start] + Sol(start + 1, end, !turn), card[end] + Sol(start, end - 1, !turn));
	}
	else {
		result = min(Sol(start + 1, end, !turn), Sol(start, end - 1, !turn));
	}
	return result;
}
int main() {
	
	Card ca;
	int testcase;
	fcin >> testcase;
	while (testcase--) {
		ca.Input();
		fcout << ca.Sol(0, ca.num - 1, true) << '\n';
	}
	return 0;
}