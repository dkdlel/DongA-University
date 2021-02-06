// 백준 10090
#include <bits/stdc++.h>
using namespace std;

ifstream fcin("inv.inp");
ofstream fcout("inv.out");

class Inv {
public:
	int n1;
	long long inv_num; // inv_num : 도치수
	vector<int> S;
	void Input();
	void Partition(int low, int high);
	void Merge(int low, int mid, int high);
};
void Inv::Input() {
	S.clear();
	fcin >> n1;
	for (int i = 0; i < n1; i++) {
		int n2;
		fcin >> n2;
		S.push_back(n2);
	}
}
void Inv::Partition(int low, int high) {
	int mid = (low + high) / 2;
	if (low < mid) {
		Partition(low, mid);
		Partition(mid, high);
		Merge(low, mid, high);
	}
}
void Inv::Merge(int low, int mid, int high) {
	int start = low;
	int center = mid;
	vector<int> U;
	while (start < mid && center < high) {
		if (S[start] < S[center]) U.push_back(S[start++]); 
		else if (S[start] > S[center]) {
			inv_num += mid - start;
			U.push_back(S[center++]);
		}
	}
	while (start < mid) U.push_back(S[start++]);
	while (center < high) U.push_back(S[center++]);
	for (int i = 0; i < high - low; ++i) S[low + i] = U[i];
	U.clear();
}
int main() {

	Inv inv;
	int test_case;
	fcin >> test_case;
	while (test_case--) {
		inv.inv_num = 0;
		inv.Input();
		inv.Partition(0,inv.n1);
		fcout << inv.inv_num << '\n';
	}
	return 0;
}