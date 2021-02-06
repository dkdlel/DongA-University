#include<bits/stdc++.h>
using namespace std;

ifstream fcin("p384.inp");
ofstream fcout("p384.out");

string word;

bool isSlump(int start, int end) {
	if ((word[start] != 'D' && word[start] != 'E') || word[start + 1] != 'F') return false; // ������ D,E�� �ƴϰ�, �״��� ���ڰ� F�� �ƴҶ�
	int idx = start + 2; // DF or EF����
	for (int i = idx;; i++) { // �ϳ� �̻��� F �Ÿ���
		if (word[i] != 'F') {
			idx = i;
			break;
		}
	} 

	if (word[idx] == 'G' && idx == end) return true; // slump ����
	else return isSlump(idx, end);

}
bool isSlimp(int start, int end) {
	if (end-start == 1 && word[start + 1] == 'H') return true; // AH �� slimp ����
	else if (word[end] != 'C') return false; // AH�� �ƴҰ�� ���ڸ��� �׻� C ������
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
		if (word[0] != 'A') { fcout << "NO\n"; continue; } // ù�ܾ A�� �ƴϸ� slimp�� �ƴϱ� ������

		for (int i = word.size() - 1; i >= 0; i--) { // slimp, slump ��� ã��
			if (word[i] == 'H' || word[i] == 'C') { // slimp�� ������ ����
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