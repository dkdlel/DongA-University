#include<bits/stdc++.h>
using namespace std;

ifstream fcin("coinmove.inp");
ofstream fcout("coinmove.out");

class CoinMove {
public:
	int testcase, pass, move, start; // pass : 못밟는 위치(P), move : 움직일수 있는 거리(K), start : 시작위치(S)
	vector< vector < bool > > vec;
	void Set();
	bool Sol(int pre, int ignore); // pre : 몇번째 전을 확일 할 것이냐, ignore : 무시해야할 위치
	void Print();
};
void CoinMove::Set() {
	vec.resize(start + 1);
	for (int i = 0; i < vec.size(); i++) vec[i].resize(move + 1);
}
bool CoinMove::Sol(int pre, int ignore) {
	if (pre < 0) return false; // 0밑으로는 무조건 짐
	else if (pre != 0 && pre % pass == 0) return false; // pass 자리를 만날경우 짐
	for (int i = 1; i <= move; i++)
		if (i != ignore && vec[pre][i]) return false; // 무시해야할 자리는 무시하고 true가 하나라도 있다면 짐
	return true; // 위의 경우들이 아닐경우 이김
}
void CoinMove::Print() {
	for (int i = 1; i <= move; i++) {
		if (vec[start][i]) { // 가장 가까운 true를 만날경우 승리
			fcout << start - i << '\n';
			return;
		}
	}
	fcout << "-1\n"; // 전부다 패배할 경우 -1
}
int main() {

	CoinMove CM;

	fcin >> CM.testcase;
	while (CM.testcase--) {
		fcin >> CM.pass >> CM.move >> CM.start;
		CM.Set();
		for (int i = 1; i <= CM.start; i++)
			for (int j = 1; j <= CM.move; j++)
				CM.vec[i][j] = CM.Sol(i - j, j);
		CM.Print();
	}
	return 0;
}