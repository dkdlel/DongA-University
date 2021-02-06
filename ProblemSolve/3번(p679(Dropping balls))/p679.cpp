#include<bits/stdc++.h>
using namespace std;
#define MAX 1048577

ifstream fcin("p679.inp");
ofstream fcout("p679.out");
bool tree[MAX];

int Sol(int depth, int ball) {
	int result;
	for (int i = 0; i < ball; i++) {
	result = 1;
		for (int j = 1; j < depth; j++) {
			if (tree[result]) { // ture일때는 왼쪽으로(2n)
				tree[result] = false;
				result = result * 2 + 1;
			}
			else { // false일때는 오른쪽으로(2n+1)
				tree[result] = true;
				result *= 2;
			}
		}
	}
	return result;
}

int main() {

	while (1) {
		int num;
		fcin >> num;
		if (num == -1) break;
		else {
			for (int i = 0; i < num; i++) {
				for (int i = 0; i < MAX; i++) tree[i] = false;
				int depth, ball; // depth : 깊이, ball : 공의 갯수
				fcin >> depth >> ball;
				fcout << Sol(depth, ball) << '\n';
			}
		}
	}
	return 0;
}