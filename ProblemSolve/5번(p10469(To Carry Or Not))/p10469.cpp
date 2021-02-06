#include<bits/stdc++.h>
using namespace std;

ifstream fcin("p10469.inp");
ofstream fcout("p10469.out");

int binary_num1[32];
int binary_num2[32];
int binary_result[32];
long long int num1, num2, result;

void Init() {
	for (int i = 0; i < 32; i++) binary_num1[i] = binary_num2[i] = binary_result[i] = 0;
}
void To_Binary(long long int num1,long long int num2) {
	int idx = 0;
	while (1) {
		binary_num1[idx] = num1 % 2;
		num1 /= 2;
		idx++;
		if (num1 == 0) break;
	}
	idx = 0;
	while (1) {
		binary_num2[idx] = num2 % 2;
		num2 /= 2;
		idx++;
		if (num2 == 0) break;
	}
}
void Sol() {
	int num;
	for (int i = 0; i < 32; i++) {
		if (binary_num1[i] + binary_num2[i] >= 2) num = 0;
		else num = binary_num1[i] + binary_num2[i];

		binary_result[i] = num;
	}
}
void To_Digit() {
	long long int num = 1; result = 0;
	for (int i = 0; i < 32; i++) {
		result += binary_result[i] * num;
		num *= 2;
	}
	fcout << result << '\n';
}
int main() {

	while (fcin >> num1 >> num2) {
		Init();
		To_Binary(num1, num2);
		Sol();
		To_Digit();
	}
	return 0;
}