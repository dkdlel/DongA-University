#include <bits/stdc++.h>
using namespace std;

ifstream fcin("p100.inp");
ofstream fcout("p100.out");

void Swap(int &start, int &end) {
		int tmp;
		tmp = start;
		start = end;
		end = tmp;
}
long long Cal(int i, int cnt) {
	cnt++;
	if (i == 1) return cnt;
	else if (i % 2 == 0) return Cal(i / 2, cnt);
	else Cal(3 * i + 1, cnt);
}
long long Sol(int start, int end) {
	long long result = 0;
	for (int i = start; i <= end; i++) {
		int cnt = 0;
		result = max(result,Cal(i, cnt));
	}
	return result;
}

int main() {

	int start, end;
	while (fcin >> start >> end) {
		fcout << start << ' ' << end << ' ';
		if(start > end) Swap(start,end);
		fcout << Sol(start, end) << '\n';
	}
	return 0;
}