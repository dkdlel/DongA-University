#include <stdio.h>
#include <math.h>

FILE *inp = fopen("hw2.inp", "rt");
FILE *out = fopen("hw2.out", "wt");

int size, hash, Hashing_Table[100];
double Real_num;
char star;

int Hash_Cal() {
	double tmp;
	// 해쉬수 * 실수 값
	tmp = (Real_num * hash) - floor(Real_num * hash);
	// 둘째자리 버림 계산
	tmp *= 100;

	// 연산을 위한 반올림
	tmp += 0.5;
	tmp = floor(tmp);

	// 소수 * 크기
	tmp = tmp * size;

	tmp /= 100;

	return tmp;
}
int main() {

	if ((inp = fopen("hw2.inp", "rt")) == NULL) fprintf(stderr, "cant't open %s\n", "hw2.inp");
	if ((out = fopen("hw2.out", "wt")) == NULL) fprintf(stderr, "cant't open %s\n", "hw2.out");

	fscanf(inp, "%d %lf", &size, &Real_num);

	// 입력
	while(fscanf(inp, "%d", &hash)) {
		int h = Hash_Cal();
		while (Hashing_Table[h] != 0) h++;
		// 입력 크기 보다 클 경우
		if (h >= size) h -= size;
		Hashing_Table[h] = hash;
	}

	// 출력
	for (int i = 0; i < size ; i++) {
		if (Hashing_Table[i] == 0) continue;
		fprintf(out, "[%d,%d]\n", i, Hashing_Table[i]);
	}
	fprintf(out, "*");

	fclose(inp);
	fclose(out);
	return 0;
}