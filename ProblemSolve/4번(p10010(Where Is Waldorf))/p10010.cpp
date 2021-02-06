#include<bits/stdc++.h>
using namespace std;

ifstream fcin("p10010.inp");
ofstream fcout("p10010.out");

char board[51][51] = { '0', }; // 전체 문자의 판
string find_text; // 찾아야할 문자
int idx, tmp_idx; // 찾아야할 문자의 인덱스
int n, m; // 입력받은 판
int dx[8] = { -1,-1,-1,0,1,1, 1, 0 }; // 왼쪽위, 위, 오른쪽위, 오른쪽, 오른쪽 아래, 아래, 왼쪽아래, 왼쪽
int dy[8] = { -1, 0, 1,1,1,0,-1,-1 };

bool Check(int i, int j, int k) {// k : 방향
	for (int l = 2; l < find_text.size(); l++) {
		if (board[i][j] == '0') return false; // 테두리
		if (find_text[l] != board[i + dx[k]][j + dy[k]]) return false; // 글자 안맞음
		i += dx[k]; j += dy[k];
	}
	return true;
}
void Find() {
	for (int i = 1; i <= n; i++) {
		bool flag = false;
		for (int j = 1; j <= m; j++) {
			if (find_text[0] == board[i][j]) {
				for (int k = 0; k < 8; k++) {
					if (find_text[1] == board[i + dx[k]][j + dy[k]]) { // 8개 방향으로 같은게 있으면
						if (Check(i + dx[k], j + dy[k], k)) { // 문자가 있으면
							fcout << i << ' ' << j << '\n';
							flag = true;
							break;
						}
					}
				}
			}
			if (flag) break;
		}
		if (flag) break;
	}
}
int main() {

	int testcase;
	fcin >> testcase;
	while (testcase--) {
		fcin >> n >> m;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				char ch; // 입력받을 문자
				fcin >> ch;
				if (ch <= 'Z') ch += 32;
				board[i][j] = ch;
			}
		}
		int find_num; // 찾아야할 문자들의 수
		fcin >> find_num;
		for (int i = 0; i < find_num; i++) {
			idx = 0;
			fcin >> find_text;
			for (int j = 0; j < find_text.size(); j++) {
				if (find_text[j] <= 'Z') find_text[j] += 32;
			}
			Find();
		}
		fcout << '\n';
	}
	return 0;
}