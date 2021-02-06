#include<bits/stdc++.h>
using namespace std;

ifstream fcin("coinmove.inp");
ofstream fcout("coinmove.out");

class CoinMove {
public:
	int testcase, pass, move, start; // pass : ����� ��ġ(P), move : �����ϼ� �ִ� �Ÿ�(K), start : ������ġ(S)
	vector< vector < bool > > vec;
	void Set();
	bool Sol(int pre, int ignore); // pre : ���° ���� Ȯ�� �� ���̳�, ignore : �����ؾ��� ��ġ
	void Print();
};
void CoinMove::Set() {
	vec.resize(start + 1);
	for (int i = 0; i < vec.size(); i++) vec[i].resize(move + 1);
}
bool CoinMove::Sol(int pre, int ignore) {
	if (pre < 0) return false; // 0�����δ� ������ ��
	else if (pre != 0 && pre % pass == 0) return false; // pass �ڸ��� ������� ��
	for (int i = 1; i <= move; i++)
		if (i != ignore && vec[pre][i]) return false; // �����ؾ��� �ڸ��� �����ϰ� true�� �ϳ��� �ִٸ� ��
	return true; // ���� ������ �ƴҰ�� �̱�
}
void CoinMove::Print() {
	for (int i = 1; i <= move; i++) {
		if (vec[start][i]) { // ���� ����� true�� ������� �¸�
			fcout << start - i << '\n';
			return;
		}
	}
	fcout << "-1\n"; // ���δ� �й��� ��� -1
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