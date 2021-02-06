#include <stdio.h>

FILE *inp, *out;
int reverse[] = { 5,3,4,1,2,0 };
int dice[10000][6];
int total_num, num, sum = 0, up, down, max, total_sum; // t : �����
int a=0, start;

void input() {

	fscanf(inp, "%d\n", &total_num);

	for (int i = 0; i < total_num; i++) { // �Է�
		for (int j = 0; j < 6; j++) {
			fscanf(inp, "%d", &num);
			dice[i][j] = num;
		}
	}
}
void sol() {

	for (int t = 0; t < 6; t++) {
		down = dice[0][t];
		for (int i = 0; i < total_num; i++) { // ��ü ����Ǽ� ������

			for (int k = 0; k < 6; k++) { // ���� ��
				if (dice[i][k] == down) {
					up = dice[i][reverse[k]]; // ����
					break;
				}
			}

			for (int j = 0; j < 6; j++) { // �� �� ���		
				if (dice[i][j] == down || dice[i][j] == up) continue; // ����� �Ʒ����� ��
				else { // ����� �Ʒ����� �ٸ� ��
					if (max < dice[i][j]) max = dice[i][j]; // ���� ũ�� max�� ����
				}
			}
			sum += max; // sum�� ���� ū�� ���ϱ�
			max = 0;
			down = up; // ���� �Ʒ��� �ٲٱ�
		}
		if (total_sum < sum) { // ���� ���� ���� ������ Ŭ ��
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
