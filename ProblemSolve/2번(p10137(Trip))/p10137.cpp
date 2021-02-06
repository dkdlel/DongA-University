#include<bits/stdc++.h>
using namespace std;

ifstream fcin("p10137.inp");
ofstream fcout("p10137.out");

int money[1001], num, sum, dollar, cent;
int avg, ceilavg, lesssum, moresum, totalsum;

int main() {

	while (1) {
		sum = 0;
		fcin >> num;
		if (num == 0) break;
		for (int i = 0; i < num; i++) {
			char tmp;
			fcin >> dollar >> tmp >> cent;
			money[i] = dollar * 100 + cent;
			sum += money[i];
		}
		avg = sum / num;
		ceilavg = ceil((double)sum / num);

		lesssum = 0, moresum = 0; // lesssum = 평균보다 작은값들의 합, moresum = 평균보다 큰값들의 합
		for (int i = 0; i < num; i++) {
			if (money[i] <= avg) lesssum += avg - money[i];
			else if (money[i] >= ceilavg) moresum += money[i] - ceilavg;
		}

		totalsum = max(lesssum, moresum);
		fcout << '$' << totalsum / 100 << '.' << setw(2) << setfill('0') << totalsum % 100 << '\n';
	}
	return 0;
}