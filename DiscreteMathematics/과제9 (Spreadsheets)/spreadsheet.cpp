#include <stdio.h>
#include <string.h>;
FILE *inp, *out;

int total_num, n1=1, num, cnt=0, num_1=0,temp,total;
int n2, n3; // n2 : ��, n3 : ������
int N2[20]; // ������ ����
char test;
char in[100], output[100];

typedef enum alp{Z=0,A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y}ALP;

void TEMP(int a) { // �� switch ������
	switch (a)
	{
	case 1:
		fprintf(out, "%c",'A');
		break;
	case 2:
		fprintf(out, "%c", 'B');
		break;
	case 3:
		fprintf(out, "%c", 'C');
		break;
	case 4:
		fprintf(out, "%c", 'D');
		break;
	case 5:
		fprintf(out, "%c", 'E');
		break;
	case 6:
		fprintf(out, "%c", 'F');
		break;
	case 7:
		fprintf(out, "%c", 'G');
		break;
	case 8:
		fprintf(out, "%c", 'H');
		break;
	case 9:
		fprintf(out, "%c", 'I');
		break;
	case 10:
		fprintf(out, "%c", 'J');
		break;
	case 11:
		fprintf(out, "%c", 'K');
		break;
	case 12:
		fprintf(out, "%c", 'L');
		break;
	case 13:
		fprintf(out, "%c", 'M');
		break;
	case 14:
		fprintf(out, "%c", 'N');
		break;
	case 15:
		fprintf(out, "%c", 'O');
		break;
	case 16:
		fprintf(out, "%c", 'P');
		break;
	case 17:
		fprintf(out, "%c", 'Q');
		break;
	case 18:
		fprintf(out, "%c", 'R');
		break;
	case 19:
		fprintf(out, "%c", 'S');
		break;
	case 20:
		fprintf(out, "%c", 'T');
		break;
	case 21:
		fprintf(out, "%c", 'U');
		break;
	case 22:
		fprintf(out, "%c", 'V');
		break;
	case 23:
		fprintf(out, "%c", 'W');
		break;
	case 24:
		fprintf(out, "%c", 'X');
		break;
	case 25:
		fprintf(out, "%c", 'Y');
		break;
	case 26:
		fprintf(out, "%c", 'Z');
		break;
	}
}
void sol_num_to_char() {
	n2 = num;
	num_1 = 0;
	cnt = 0;
	while (1) {
		n3 = (n2-1) % 26 +1; // ������
		n2 = n2 / 26; // ��
		if (n3 == 26) n2--; // �������� 26�� ��쿡 1��(�������� �𸣰��� �Ѥ�;;)
		if (n2 == 0) { // ���� 0�̸� �׶��� �������� ������ ����
			n2 = n3;
			break;
		}
		N2[num_1] = n3; // �������� �迭�� ����(�������� ����ؾ���)
		num_1++; // N2�迭 ����ĭ���� �ѱ��
		cnt++; // ���ĺ��� ����� �Ǻ��ϱ� ���ؼ�
	}

	TEMP(n2); // enum�� ���� ���� TEMP�Լ�
	for (int i = cnt-1; i >= 0; i--) {
		TEMP(N2[i]);
	} // ���ĺ����� �����ؼ� ��¿Ϸ�

	for (int i = 1; --n1; i++) {
		fprintf(out, "%c", in[i]);
	}
	fprintf(out, "\n");
}
void sol_char_to_num() {
	total = 0;
	fprintf(out, "R"); // ���� ó�� ����� ������ R�̴ϱ�
	for (int i = n1 - 1; in[i] != NULL; i++) { // �Է¹��� ���� �״�� ���
		fprintf(out, "%c", in[i]);
	}
	if (in[0] >= 'A' && in[0] <= 'Z' && in[1] >= 'A' && in[1] <= 'Z') { // ���ڰ� �������� ���
		total = 26 * (in[0] - 64) + (in[1] - 64); // �����ε� ��� �������� Ȱ���ؼ� �� (���� ��ȯ�Ҷ� ó�� ������ �ϴٺ��� �̰� ���� �˲��� ������)
		for (int i = 2; i < n1 - 1; i++) {
			total = total * 26 + (in[i] - 64);
		}
		fprintf(out, "C%d", total);
	}
	else // ���ڰ� �Ѱ��� ���
		fprintf(out, "C%d", in[0] - 64);

	
	fprintf(out, "\n");
}
void num_to_char() { // R23C55
	num = 0;
	n1 = 0;
	while (in[n1] != 'C') n1++; // C�� ã���� ������

	for (int i = n1 + 1; in[i] != NULL; i++) { // n1+1�� n1�� C�� �ش��ϴ� ���̱� ������, ���� ��ȯ �۾�
		num *= 10; // �ƽ�Ű�ڵ� ���� �ƶ��Ƽ��� �ٲٱ�
		num += in[i] - '0';
	}

	sol_num_to_char();
}

void char_to_num() { // BC23
	n1 = 1;
	for (;;) {
		if (in[n1-1] >= '0' && in[n1-1] <= '9') break; // ���ڸ� Ż��
		else n1++; // ���ڴ��� ������ ���� �ľ��ϱ� ���ؼ�
	}

	for (int i = n1-1 ; in[i] != NULL; i++) { // n1-1�� �ѹ� �����ұ� ������, �ű⼭ ���� ����������
		num *= 10; 
		num += in[i] - '0';
	}

	sol_char_to_num();
}

void input() { // ����Ǽ� 2�� ������������
	if (in[0] == 'R' && in[1] >= '0' && in[1] <= '9') {
		num_to_char(); // R23C55
	}
	else {
		char_to_num(); // BC23
	}
}

int main() {

	inp = fopen("spreadsheet.inp", "rt");
	out = fopen("spreadsheet.out", "wt");

	fscanf(inp, "%d\n", &total_num);

	for (int i = 0; i < total_num; i++) {
		fscanf(inp, "%s", &in);
		input();
	}

	fclose(inp);
	fclose(out);
	return 0;
}