#include<bits/stdc++.h>
using namespace std;

ifstream fcin("p384.inp");
ofstream fcout("p384.out");

string word;

bool isSlump(int start, int end) {
	if ((word[start] != 'D' && word[start] != 'E') || word[start + 1] != 'F') return false; // 시작이 D,E가 아니고, 그다음 문자가 F가 아닐때
	int idx = start + 2; // DF or EF이후
	for (int i = idx;; i++) { // 하나 이상의 F 거르기
		if (word[i] != 'F') {
			idx = i;
			break;
		}
	} 

	if (word[idx] == 'G' && idx == end) return true; // slump 성립
	else return isSlump(idx, end);

}
bool isSlimp(int start, int end) {
	if (end-start == 1 && word[start + 1] == 'H') return true; // AH 로 slimp 성립
	else if (word[end] != 'C') return false; // AH가 아닐경우 끝자리는 항상 C 여야함
	else if (word[start + 1] == 'B') return isSlimp(start + 2, end-1); // A -> B -> slimp -> C
	else return isSlump(start + 1, end-1); // A -> Slump -> C
}
int main() {
	fcout << "SLURPYS OUTPUT\n";
	int testcase;
	fcin >> testcase;

	for (int t = 0; t < testcase; t++) {
		bool ans = false;
		fcin >> word;
		if (word[0] != 'A') { fcout << "NO\n"; continue; } // 첫단어가 A가 아니면 slimp가 아니기 때문에

		for (int i = word.size() - 1; i >= 0; i--) { // slimp, slump 경계 찾기
			if (word[i] == 'H' || word[i] == 'C') { // slimp가 끝나는 지점
				if (isSlimp(0, i) && isSlump(i+1, word.size() - 1)) 
					ans = true;
				break;
			}
		}
		fcout << (ans ? "YES\n" : "NO\n");
	}
	fcout << "END OF OUTPUT";
	return 0;
}