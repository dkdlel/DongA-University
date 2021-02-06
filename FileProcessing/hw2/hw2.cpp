#include <stdio.h>
#include <math.h>

FILE *inp = fopen("hw2.inp", "rt");
FILE *out = fopen("hw2.out", "wt");

int size, hash, Hashing_Table[100];
double Real_num;
char star;

int Hash_Cal() {
	double tmp;
	// �ؽ��� * �Ǽ� ��
	tmp = (Real_num * hash) - floor(Real_num * hash);
	// ��°�ڸ� ���� ���
	tmp *= 100;

	// ������ ���� �ݿø�
	tmp += 0.5;
	tmp = floor(tmp);

	// �Ҽ� * ũ��
	tmp = tmp * size;

	tmp /= 100;

	return tmp;
}
int main() {

	if ((inp = fopen("hw2.inp", "rt")) == NULL) fprintf(stderr, "cant't open %s\n", "hw2.inp");
	if ((out = fopen("hw2.out", "wt")) == NULL) fprintf(stderr, "cant't open %s\n", "hw2.out");

	fscanf(inp, "%d %lf", &size, &Real_num);

	// �Է�
	while(fscanf(inp, "%d", &hash)) {
		int h = Hash_Cal();
		while (Hashing_Table[h] != 0) h++;
		// �Է� ũ�� ���� Ŭ ���
		if (h >= size) h -= size;
		Hashing_Table[h] = hash;
	}

	// ���
	for (int i = 0; i < size ; i++) {
		if (Hashing_Table[i] == 0) continue;
		fprintf(out, "[%d,%d]\n", i, Hashing_Table[i]);
	}
	fprintf(out, "*");

	fclose(inp);
	fclose(out);
	return 0;
}