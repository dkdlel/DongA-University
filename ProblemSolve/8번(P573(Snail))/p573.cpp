#include <bits/stdc++.h>
using namespace std;

ifstream fcin("p573.inp");
ofstream fcout("p573.out");

int H, U, D, F; // H : �칰�� ����, U : �������ִ� �Ÿ�, D : �������� �Ÿ�, F: �Ƿε�
int day;

bool Sol() {
	H *= 100; U *= 100; D *= 100;
	int height = 0;
	int fatigue = U * 0.01 * F; // �Ƿε�

	for (day = 1; ; day++) {
		height += U;
		if (height > H) return true;

		height -= D;
		if (height <= 0) return false;

		U -= fatigue;
		if (U < 0) U = 0;
	}
}
int main() {

	while (true) {
		fcin >> H >> U >> D >> F;
		if (!H && !U && !D && !F) break;
		if (Sol())
			fcout << "success on day " << day << '\n';
		else
			fcout << "failure on day " << day << '\n';
	}
	return 0;
}