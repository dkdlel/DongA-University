#include <stdio.h>

FILE *inp, *out;
int reverse[] = { 5,3,4,1,2,0 };
int dice[10000][6];
int total_num, num, sum = 0, up, down, max, total_sum; // t : 저장용
int a=0, start;

void input() {

	fscanf(inp, "%d\n", &total_num);

	for (int i = 0; i < total_num; i++) { // 입력
		for (int j = 0; j < 6; j++) {
			fscanf(inp, "%d", &num);
			dice[i][j] = num;
		}
	}
}
void sol() {

	for (int t = 0; t < 6; t++) {
		down = dice[0][t];
		for (int i = 0; i < total_num; i++) { // 전체 경우의수 돌리기

			for (int k = 0; k < 6; k++) { // 윗면 용
				if (dice[i][k] == down) {
					up = dice[i][reverse[k]]; // 윗면
					break;
				}
			}

			for (int j = 0; j < 6; j++) { // 각 행 계산		
				if (dice[i][j] == down || dice[i][j] == up) continue; // 윗면과 아랫면일 때
				else { // 윗면과 아랫면이 다를 때
					if (max < dice[i][j]) max = dice[i][j]; // 값이 크면 max에 저장
				}
			}
			sum += max; // sum에 가장 큰값 더하기
			max = 0;
			down = up; // 윗면 아랫면 바꾸기
		}
		if (total_sum < sum) { // 계산된 값이 기존 값보다 클 때
			total_sum = sum;
		}
		sum = 0;
	}

	fprintf(out, "%d", total_sum);
}

int main() {

	inp = fopen("dice.inp", "rt");
	out = fopen("dice.out", "wt");

	input();
	sol();

	fclose(inp);
	fclose(out);
	return 0;
}
