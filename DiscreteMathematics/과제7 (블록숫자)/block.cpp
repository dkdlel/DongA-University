#include <stdio.h>
#include <stdlib.h>

FILE *inp, *out;
int arr[1001][1001], total_num, n1, n1_1, n2, sum;

void input() {
	fscanf(inp, "%d", &n1);
	for (int i = 1; i <= n1; i++) { // 0�����ϸ� Ȥ�� �ٸ� �ּҰ� ���� �ұ��
		for (int j = 1; j <= i; j++) {
			fscanf(inp, "%d", &n2);
			arr[i][j] = n2;
		}
	}
}

void sol() {
	for (int k = 0; k < n1; k++) { // �־��� ��� ��ü����� ����ŭ �񱳸� �ؾ���
		for (int i = n1; i >= 1; i--) { // ���� ���, �� �� �� �����ʿ��� ���� ����
			for (int j = i; j > 1; j--) { // ���� ���

				if (arr[i][j] == -1) { // ó���̶� �����ϰ� �� �� �� �������� -1�̸�
					if (arr[i][j - 1] == -1 || arr[i - 1][j - 1] == -1) continue; // �� ���ʰ� �� ���� ���� -1�̸� ���� �Ұ�
					else { // �ƴҰ��� ���� ���� ���� ���� ���� �����ϱ� ������
						sum = arr[i - 1][j - 1] - arr[i][j - 1]; // ���������� �ؿ� ���� ��
						if (sum < 0) sum += 100; // ���� ������ ��� 100�� ������
						arr[i][j] = sum;
					}
				}

				else if (arr[i][j] != -1) { // -1�� �ƴϰ� ������ ���
					if (arr[i][j - 1] != -1 && arr[i - 1][j - 1] == -1) { // ������ �����̰� �������� -1�� ���
						sum = arr[i][j] + arr[i][j - 1]; // �ؿ� �μ��� ����
						if (sum < 0) sum += 100;
						arr[i - 1][j - 1] = sum % 100; // 100�� ���� ��� �������� ���
					}
					else if (arr[i][j - 1] == -1 && arr[i - 1][j - 1] != -1) { // ������ -1�̰� �������� ������ ���
						sum = arr[i - 1][j - 1] - arr[i][j]; // ���� ������ ������ ��
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