#include <stdio.h>

FILE *inp, *out;
int total_num, ori[1001], result[1001], TEMP[1001], num, n1, cnt, answer,temp;

void input()
{
	fscanf(inp, "%d\n", &num);
	for (int j = 1; j <= num; j++) // ���� �迭 �ޱ�
	{
		fscanf(inp, "%d", &n1);
		ori[j] = n1;
	}
	for (int j = 1; j <= num; j++) // ��� �迭 �ޱ�
	{
		fscanf(inp, "%d", &n1);
		result[j] = n1;
	}
}

void sol()
{
	for (int i = num; i >= 1; i--) // ���� �迭�� ����������
	{
		for (int j = 1; j <= num; j++) // ��� �迭�� ó������
		{
			if (ori[i] == result[j]) // ���� ���
			{
				answer = i - j; // �ε����� �� ����
				if (answer < 0) answer *= -1; // ������ ����� �ٲٱ�
				TEMP[ori[i]] = answer; // ��� �迭�� �ֱ�
				for (int k = j; k < num; k++)
				{
					temp = result[k];
					result[k] = result[k + 1];
					result[k + 1] = temp;
				}
				break;
			}
		}
	}

	for (int j = 1; j <= num; j++)
	{
		fprintf(out, "%d ", TEMP[j]);
	}
	fprintf(out, "\n");
	
}

int main() {

	inp = fopen("line2.inp", "rt");
	out = fopen("line2.out", "wt");

	fscanf(inp, "%d\n", &total_num);
	for (int i = 0; i < total_num; i++) // ��ü ����
	{
		input();
		sol();
	}

	fclose(inp);
	fclose(out);
	return 0;
}