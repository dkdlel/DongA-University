#include <stdio.h>
#include <math.h>

FILE *inp, *out;
int check, cnt,final_max,final_min;
double max, min, n1, n2; // n1 : Q, n2 : A
bool isEnd; // ������ Ȯ��

void sol() {
	cnt = 0, final_max = 1'000'000'000, final_min = 0; // �ʱ�ȭ
	isEnd = true;

	fscanf(inp, "%d\n", &check);
	for (int j = 0; j < check; j++) {
		fscanf(inp, "%lf %lf", &n1, &n2);
		if (isEnd == true) { // ��곡���� ������ ���� ���� �ޱ� ���ؼ�
			cnt++;
			max = floor((n1 - 1 - ((n2 - 1)*(n2 - 2) / 2)) / (n2 - 1)); // ����, �׸��� ����
			min = ceil((n1 - (n2*(n2 - 1)) / 2) / n2); // �ø�
			if (final_min < min) { // ���� min���� ���� min������ Ŭ ��
				final_min = min;
			}
			if (max < final_max) { // ���� max���� ���� max������ ���� ��
				final_max = max;
			}

			if (final_max == final_min) { // ���� ���� ��
				fprintf(out, "%d %d\n", cnt, final_max);
				isEnd = false; // ��������� ����̿���
			}
		}
	}
	if (isEnd == true)
		fprintf(out, "%d\n", -1);
}
int main()
{
	inp = fopen("line.inp", "rt");
	out = fopen("line.out", "wt");

	int total_num;

	fscanf(inp, "%d\n", &total_num);
	for (int i = 0; i < total_num; i++) {
		sol();
	}
		

	fclose(inp);
	fclose(out);
	return 0;
}