#include <stdio.h>

FILE *inp, *out;
int row, col, num, sum;
int A[50][50], B[50][50];

void input() { // 입력받기

	fscanf(inp, "%d %d", &row, &col);

	for (int i = 0; i < row; i++) { // 세로
		for (int j = 0; j < col - 1; j++) {
			fscanf(inp, "%d", &num);
			A[i][j] = num;
		}
	}

	for (int i = 0; i < row - 1; i++) { // 가로
		for (int j = 0; j < col; j++) {
			fscanf(inp, "%d", &num);
			B[i][j] = num;
		}
	}
}

void sol() { // 문제풀기
	for (int i = 0; i < row - 1; i++) {
		for (int j = 0; j < col - 1; j++) {
			sum = 0;
			sum = A[i][j] + B[i][j] + B[i][j + 1] + A[i + 1][j]; // ㅏ 모양으로 비교
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
		input(); // 입력
		sol(); // 문제풀기
	}

	fclose(inp);
	fclose(out);
	return 0;
}