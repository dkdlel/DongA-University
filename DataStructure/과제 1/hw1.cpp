#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int N(int num) // N�Լ�
{
	return num; // �Է¹��� num ��ȯ
}

int Log(int num) // log2 �Լ�
{
	return (int)(log(num) / log(2)); // log num ��ȯ
}

int Logn(int num) // nlog2n �Լ�
{
	return (int)(num*Log(num)); // numlog2num ��ȯ
}
int Mul(int num) // 2��n�� �Լ�
{
	int result=1; // �����(0���� 1�̴ϱ� 1�� �ʱ�ȭ)

			for (int j = 0; j < num; j++) // n�� ���ϱ�
				result = 2 * result;

	return result; // ���� ��� ��ȯ
}
int Fac(int num) // ���丮�� �Լ�
{
	if (num <= 1) // 1���� ������
		return 1;
	else
		return num * Fac(num - 1); // ���丮�� ��ȯ
}
int main(void)
{
	FILE *input_fp = fopen("hw1.inp", "rt"); //hw1 open
	FILE *output_fp = fopen("hw1.out", "wt"); //hw2 open

	int num = 0; // ������ ���� ����
	char star; // �� ��������
	float *big_o = NULL;

	if ((input_fp = fopen("hw1.inp", "rt")) == NULL)
	{
		fprintf(stderr, "can't open %s\n", "hw1.inp");
	}

	if ((output_fp = fopen("hw1.out", "wt")) == NULL)
	{
		fprintf(stderr, "can't open %s\n", "hw1.out");
	}
	// calloc(num, sizeof(float))
	if ((big_o = (float*)malloc(sizeof(float)*5)) == NULL)
	{
		fprintf(stderr, "memory allocation error\n");
	}

	for(;;) // �Է°� ����� �ѹ����ϱ����� �ݺ���
	{
		fscanf(input_fp, "%d", &num); // ���ڹ���
		fscanf(input_fp, "%c", &star); // \n�̶� *��������
		if (star == '*') // *������ Ż��
			break;
		big_o[0] = N(num); //big_o�� ����
		big_o[1] = Log(num);
		big_o[2] = Logn(num);
		big_o[3] = Mul(num);
		big_o[4] = Fac(num);
		fprintf(output_fp, "1)%d 2)%d 3)%d 4)%d 5)%d\n", (int)big_o[0], (int)big_o[1], (int)big_o[2], (int)big_o[3], (int)big_o[4]); //���
	}
	fprintf(output_fp, "*"); // ������ ��

	fclose(input_fp); // hw1 close
	fclose(output_fp); // hw2 close
	free(big_o);

	return 0;
}