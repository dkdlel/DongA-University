#include<bits/stdc++.h>
#define MAX 104
using namespace std;

ifstream fcin("coin.inp");
ofstream fcout("coin.out");

int DP[MAX][MAX][MAX];

class Coin {
public:
	void Sol(int n1, int n2, int n3);
};
void Coin::Sol(int n1, int n2, int n3) {
	for (int i = 3; i <= n1; i++) {
		for (int j = 3; j <= n2; j++) {
			for (int k = 3; k <= n3; k++) {
				if (i == 3 && j == 3 && k == 3)continue;
				if (DP[i - 1][j][k] == -1 || DP[i][j - 1][k] == -1 || DP[i][j][k - 1] == -1) 
					DP[i][j][k] = 1;
				else if (DP[i - 2][j][k] == -1 || DP[i][j - 2][k] == -1 || DP[i][j][k - 2] == -1) 
					DP[i][j][k] = 1;
				else if (DP[i - 3][j][k] == -1 || DP[i][j - 3][k] == -1 || DP[i][j][k - 3] == -1) 
					DP[i][j][k] = 1;
				else DP[i][j][k] = -1;
			}
		}
	}
}
int main() {

	Coin coin;
	int testcase;
	fcin >> testcase;
	while (testcase--) {
		int n1, n2, n3;
		fcin >> n1 >> n2 >> n3;
		coin.Sol(n1 + 3, n2 + 3, n3 + 3);
		fcout << '(' << n1 << ' ' << n2 << ' ' << n3 << ')' << " : " << DP[n1 + 3][n2 + 3][n3 + 3] << '\n';
	}

	return 0;
}