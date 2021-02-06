#include <stdio.h>
#include <stdlib.h>

FILE *inp, *out;
int arr[1001][1001], total_num, n1, n1_1, n2, sum;

void input() {
	fscanf(inp, "%d", &n1);
	for (int i = 1; i <= n1; i++) { // 0부터하면 혹시 다른 주소값 참조 할까바
		for (int j = 1; j <= i; j++) {
			fscanf(inp, "%d", &n2);
			arr[i][j] = n2;
		}
	}
}

void sol() {
	for (int k = 0; k < n1; k++) { // 최악의 경우 전체경우의 수만큼 비교를 해야함
		for (int i = n1; i >= 1; i--) { // 가로 행렬, 맨 밑 맨 오른쪽에서 부터 시작
			for (int j = i; j > 1; j--) { // 세로 행렬

				if (arr[i][j] == -1) { // 처음이라 가정하고 맨 밑 맨 오른쪽으 -1이면
					if (arr[i][j - 1] == -1 || arr[i - 1][j - 1] == -1) continue; // 그 왼쪽과 그 위의 수가 -1이면 연산 불가
					else { // 아닐경우는 왼쪽 위의 수와 왼쪽 수가 존재하기 때문에
						sum = arr[i - 1][j - 1] - arr[i][j - 1]; // 위에수에서 밑에 수를 뺌
						if (sum < 0) sum += 100; // 합이 음수일 경우 100을 더해줌
						arr[i][j] = sum;
					}
				}

				else if (arr[i][j] != -1) { // -1이 아니고 숫자일 경우
					if (arr[i][j - 1] != -1 && arr[i - 1][j - 1] == -1) { // 왼쪽이 숫자이고 왼쪽위가 -1인 경우
						sum = arr[i][j] + arr[i][j - 1]; // 밑에 두수를 더함
						if (sum < 0) sum += 100;
						arr[i - 1][j - 1] = sum % 100; // 100이 넘을 경우 나머지를 사용
					}
					else if (arr[i][j - 1] == -1 && arr[i - 1][j - 1] != -1) { // 왼쪽이 -1이고 왼쪽위가 숫자인 경우
						sum = arr[i - 1][j - 1] - arr[i][j]; // 왼쪽 위에서 본인을 뺌
						if (sum < 0) sum += 100;
						arr[i][j - 1] = sum % 100;
					}
				}
			}
		}
	}
}


void output() {
	for (int i = 1; i <= n1; i++) {
		for (int j = 1; j <= i ; j++) {
			fprintf(out, "%d ", arr[i][j]);
		}
		fprintf(out, "\n");
	}
}
int main() {

	inp = fopen("block.inp", "rt");
	out = fopen("block.out", "wt");

	fscanf(inp, "%d\n", &total_num);

	for (int k = 0; k < total_num; k++) {
		input();
		sol();
		output();
	}


	fclose(inp);
	fclose(out);
	return 0;
}