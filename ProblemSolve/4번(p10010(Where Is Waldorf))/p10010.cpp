#include<bits/stdc++.h>
using namespace std;

ifstream fcin("p10010.inp");
ofstream fcout("p10010.out");

char board[51][51] = { '0', }; // ��ü ������ ��
string find_text; // ã�ƾ��� ����
int idx, tmp_idx; // ã�ƾ��� ������ �ε���
int n, m; // �Է¹��� ��
int dx[8] = { -1,-1,-1,0,1,1, 1, 0 }; // ������, ��, ��������, ������, ������ �Ʒ�, �Ʒ�, ���ʾƷ�, ����
int dy[8] = { -1, 0, 1,1,1,0,-1,-1 };

bool Check(int i, int j, int k) {// k : ����
	for (int l = 2; l < find_text.size(); l++) {
		if (board[i][j] == '0') return false; // �׵θ�
		if (find_text[l] != board[i + dx[k]][j + dy[k]]) return false; // ���� �ȸ���
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
					if (find_text[1] == board[i + dx[k]][j + dy[k]]) { // 8�� �������� ������ ������
						if (Check(i + dx[k], j + dy[k], k)) { // ���ڰ� ������
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
				char ch; // �Է¹��� ����
				fcin >> ch;
				if (ch <= 'Z') ch += 32;
				board[i][j] = ch;
			}
		}
		int find_num; // ã�ƾ��� ���ڵ��� ��
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