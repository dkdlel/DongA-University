#include <stdio.h>

FILE *inp, *out;
int num,total_num, a, b, c, d, e, f, g, h;
char n1[7],n2;

char A[7] = { '0','0','0','0','0','0' }; // �� ���ĺ��ٴ� ��ӵ� �迭�� �ʱ�ȭ
char B[7] = { '0','0','1','1','1','1' };
char C[7] = { '0','1','0','0','1','1' };
char D[7] = { '0','1','1','1','0','0' };
char E[7] = { '1','0','0','1','1','0' };
char F[7] = { '1','0','1','0','0','1' };
char G[7] = { '1','1','0','1','0','1' };
char H[7] = { '1','1','1','0','1','0' };

void check()
{
	a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0;
	for (int i = 0; i < 6; i++) { // ���� �Ѱ� ���̰� ���� ����� ���ĺ����� ����� �Ѵ� �Ͽ��� ������ �� �ڸ����� �ش�ɶ����� 1�� ������
		if (A[i] == n1[i]) a++;
		if (B[i] == n1[i]) b++;
		if (C[i] == n1[i]) c++;
		if (D[i] == n1[i]) d++;
		if (E[i] == n1[i]) e++;
		if (F[i] == n1[i]) f++;
		if (G[i] == n1[i]) g++;
		if (H[i] == n1[i]) h++;
	}
	if (a >= 5) fprintf(out, "%c", 'A'); // 6���� 5�� �̻��� ��ġ�ϸ� ���
	else if (b >= 5) fprintf(out, "%c", 'B');
	else if (c >= 5) fprintf(out, "%c", 'C');
	else if (d >= 5) fprintf(out, "%c", 'D');
	else if (e >= 5) fprintf(out, "%c", 'E');
	else if (f >= 5) fprintf(out, "%c", 'F');
	else if (g >= 5) fprintf(out, "%c", 'G');
	else if (h >= 5) fprintf(out, "%c", 'H');
	else fprintf(out, "%c", 'X'); // �׿� X ���
}

int main()
{
	inp = fopen("mail.inp", "rt");
	out = fopen("mail.out", "wt");
	
	fscanf(inp, "%d\n", &total_num);

	for (int k = 0; k < total_num; k++)
	{
		fscanf(inp, "%d\n", &num);
		for (int i = 0; i < num; i++)
		{
			for (int j = 0; j < 6; j++) {
				fscanf(inp, "%c", &n2);
				n1[j] = n2;
			}
			check();
		}
		fprintf(out, "\n");
	}

	fclose(inp);
	fclose(out);
	return 0;
}