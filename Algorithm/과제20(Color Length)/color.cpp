#include <bits/stdc++.h>
#define MAX 5002
#define INF 999999999
using namespace std;

ifstream fcin("color.inp");
ofstream fcout("color.out");

int testcase;
string s1, s2; // 합쳐야 할 string
int left1[26], left2[26], right1[26], right2[26]; // 왼쪽에서 읽은거 2개, 오른쪽에서 읽은거 2개
int cache[MAX][MAX];
void Init();
void Sol();

void Init() {
	s1 = s2 = '0';
	string str;
	fcin >> str; s1 += str;
	fcin >> str; s2 += str;

	for (int i = 0; i < 26; i++)
		left1[i] = left2[i] = INF, right1[i] = right2[i] = -1;
	for (int i = s1.size() - 1; i >= 1; i--)
		left1[s1[i] - 'A'] = i;
	for (int i = 1; i <= s1.size() - 1; i++)
		right1[s1[i] - 'A'] = i;
	for (int i = s2.size() - 1; i >= 1; i--)
		left2[s2[i] - 'A'] = i;
	for (int i = 1; i <= s2.size() - 1; i++)
		right2[s2[i] - 'A'] = i;

	for (int i = 0; i <= s1.size() - 1; i++)
		for (int j = 0; j <= s2.size() - 1; j++)
			cache[i][j] = INF;
	cache[0][0] = 0;
}
void Sol() {
	for (int i = 0; i <= s1.size() - 1; i++) {
		for (int j = 0; j <= s2.size() - 1; j++) {
			if (i != 0) {
				int cur = s1[i] - 'A';
				int val = 0;
				if (left1[cur] == i && left2[cur] > j) val += -i - j;
				if (right1[cur] == i && right2[cur] <= j) val += i + j;
				cache[i][j] = min(cache[i][j], cache[i - 1][j] + val);
			}
			if (j != 0) {
				int cur = s2[j] - 'A';
				int val = 0;
				if (left1[cur] > i && left2[cur] == j) val += -i - j;
				if (right1[cur] <= i && right2[cur] == j) val += i + j;
				cache[i][j] = min(cache[i][j], cache[i][j - 1] + val);
			}
		}
	}
	fcout << cache[s1.size() - 1][s2.size() - 1] << '\n';
}
int main() {

	fcin >> testcase;
	while (testcase--) {
		Init();
		Sol();
	}

	return 0;
}