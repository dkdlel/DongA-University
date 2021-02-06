#include <stdio.h>

FILE *inp, *out;
int row, col, num, sum;
int A[50][50], B[50][50];

void input() { // �Է¹ޱ�

	fscanf(inp, "%d %d", &row, &col);

	for (int i = 0; i < row; i++) { // ����
		for (int j = 0; j < col - 1; j++) {
			fscanf(inp, "%d", &num);
			A[i][j] = num;
		}
	}

	for (int i = 0; i < row - 1; i++) { // ����
		for (int j = 0; j < col; j++) {
			fscanf(inp, "%d", &num);
			B[i][j] = num;
		}
	}
}

void sol() { // ����Ǯ��
	for (int i = 0; i < row - 1; i++) {
		for (int j = 0; j < col - 1; j++) {
			sum = 0;
			sum = A[i][j] + B[i][j] + B[i][j + 1] + A[i + 1][j]; // �� ������� ��
			if (sum % 2 == 0) {
				fprintf(out,"%d ", 0);
				break;
			}
		}
		if (sum % 2 == 0)
			break;
	}
	if(sum %2 ==1) fprintf(out, "%d ", 1);
}

int main() {

	inp = fopen("paper.inp", "rt");
	out = fopen("paper.out", "wt");
	
	int total_num;

	fscanf(inp, "%d\n", &total_num);

	for (int t = 0; t < total_num; t++) {
		input(); // �Է�
		sol(); // ����Ǯ��
	}

	fclose(inp);
	fclose(out);
	return 0;
}