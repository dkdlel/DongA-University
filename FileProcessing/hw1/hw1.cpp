#include <stdio.h>
#include <string.h>

FILE *inp = fopen("hw1.inp", "rt");
FILE *out = fopen("hw1.out", "wt");

int num_arr1[100000], num_arr2[100000],total_arr[100000];
int num, arr_size[2], cnt1, cnt2, distance;
char enter;

void insert1() { // �Է�

	cnt1 = 0;
	for (int i = 0; i < 100000; i++) {
		if (enter == '*') break;
		fscanf(inp, "%d", &num);
		enter = fgetc(inp);

		if (enter == '\n') {
			num_arr1[i] = num;
			cnt1++;
			break;
		}
		else {
			num_arr1[i] = num;
			cnt1++;
		}
	}
	arr_size[0] = cnt1;
}

void insert2() { // �Է�

	cnt2 = 0;
	for (int i = 0; i < 100000; i++) {
		fscanf(inp, "%d%c", &num, &enter);
		if (enter == '\n') {
			num_arr2[i] = num;
			cnt2++;
			break;
		}
		else {
			num_arr2[i] = num;
			cnt2++;
		}
	}
	arr_size[1] = cnt2;
}

void check1() { // �߰� ����
		distance = arr_size[0] / 2; // �迭 ũ�� �� �ɰ��� ���ؼ�
		while (distance >= 1) { // ���̰� 1�̸� �׳� �����̴ϱ�
			for (int k = 0; k < distance; k++) { // ó������ ������ �ɰ��� ����
				int i, j, temp;
				for (i = k + distance; i <= arr_size[0] - 1; i = i + distance) { // ù��°�� distance�Ÿ���ŭ ����� �� ��
					temp = num_arr1[i]; // ó���� �ӽ� ����
					for (j = i - distance; j >= k && temp < num_arr1[j]; j = j - distance) 
						num_arr1[j + distance] = num_arr1[j];
					num_arr1[j + distance] = temp;
				}
			}
			for (int i = 0; i < arr_size[0]; i++) 
				fprintf(out, "%d ", num_arr1[i]); // �������� ���
			fprintf(out, "\n");
			distance = distance / 2;
		}
}

void check2() { // �߰� ����
	distance = arr_size[1] / 2; // �迭 ũ�� �� �ɰ��� ���ؼ�
	while (distance >= 1) { // ���̰� 1�̸� �׳� �����̴ϱ�
		for (int k = 0; k < distance; k++) { // ó������ ������ �ɰ��� ����
			int i, j, temp;
			for (i = k + distance; i <= arr_size[1] - 1; i = i + distance) { // ù��°�� distance�Ÿ���ŭ ����� �� ��
				temp = num_arr2[i]; // ó���� �ӽ� ����
				for (j = i - distance; j >= k && temp < num_arr2[j]; j = j - distance)
					num_arr2[j + distance] = num_arr2[j];
				num_arr2[j + distance] = temp;
			}
		}
		for (int i = 0; i < arr_size[1]; i++)
			fprintf(out, "%d ", num_arr2[i]); // �������� ���
		fprintf(out, "\n");
		distance = distance / 2;
	}
}

void output() { // ���� ���� �� ���
	
	int c1 = 0, c2 = 0, total_cnt=0;
	int i = 0, j = 0, t = 0;
	while (1) {
		if (num_arr1[i] < num_arr2[j]) { // �ι�° �迭�� Ŭ ��
			total_arr[t] = num_arr1[i];
			i++; t++; c1++; total_cnt++;
			if (c1 == arr_size[0]) { // ���� �迭�� ��������
				while (num_arr2[j] != 0) {
					total_arr[t] = num_arr2[j];
					j++; t++; total_cnt++;
				}
				break;
			}
		}
		else if (num_arr1[i] > num_arr2[j]) { // ù��° �迭�� Ŭ �� 
			total_arr[t] = num_arr2[j];
			j++; t++; c2++; total_cnt++;
			if (c2 == arr_size[1]) { // �ؿ� �迭�� ��������
				while (num_arr1[i] != 0) {
					total_arr[t] = num_arr1[i];
					i++; t++; total_cnt++;
				}
				break;
			}
		}
		else if (num_arr1[i] == num_arr2[j]) { // �� ���� ���� ��
			total_arr[t] = num_arr1[i];
			t++;
			total_arr[t] = num_arr2[j];
			i++; j++; t++; c1++; c2++; total_cnt += 2;
			if (c1 == arr_size[0]) { // ���� �迭�� ��������
				while (num_arr2[j] != 0) {
					total_arr[t] = num_arr2[j];
					j++; t++; total_cnt++;
				}
				break;
			}
			if (c2 == arr_size[1]) { // �ؿ� �迭�� ��������
				while (num_arr1[i] != 0) {
					total_arr[t] = num_arr1[i];
					i++; t++; total_cnt++;
				}
				break;
			}
		}
	}

	for (int t = 0; t < total_cnt; t++) fprintf(out, "%d ", total_arr[t]);
	fprintf(out, "\n");
}

int main() {

	if ((inp = fopen("hw1.inp", "rt")) == NULL)
		fprintf(stderr, "cant't open %s\n", "hw1.inp");

	if ((out = fopen("hw1.out", "wt")) == NULL)
		fprintf(stderr, "cant't open %s\n", "hw1.out");

	while (1) {
		insert1(); // ù��° �迭 �Է�
		if (enter == '*') { // * ������
			fprintf(out, "*");
			break;
		}
		insert2(); // �ι�° �迭 �Է�
		check1(); // ù��° �迭 �� ����
		check2(); // �ι�° �迭 �� ����
		output(); // ���ĵ� �� ������ �պ� ����

	}
	
	fclose(inp);
	fclose(out);
	return 0;
}