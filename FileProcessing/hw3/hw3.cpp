#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *inp = fopen("hw4.inp", "rt");
FILE *out = fopen("hw4.out", "wt");

char new_track[5], new_key[5], check_key[5];
int length, total_node = 1, idx;
int true_false;

// ���ڵ� ����
typedef struct Record {
	struct Record* child[10];
	int check;
	char track[5], key[5];
}Record;

Record* Create_Node() { // ��� �����
	Record* new_Node = (Record *)malloc(sizeof(Record));
	// ��� �ʿ����
	new_Node->check = 0;
	// �ʱ�ȭ
	for (int i = 0; i < 10; i++) new_Node->child[i] = 0;
	return new_Node;
}

void Insert_Node(Record* root) {

	Record* now = root;
	// ��� ����
	for (int i = 1; i <= 4; i++) {
		if (!now->child[new_track[i] - '0']) {
			total_node++;
			now->child[new_track[i] - '0'] = Create_Node();
		}
		now = now->child[new_track[i] - '0'];
		// �̰� ��� �ʿ� ����
		now->check = 1;
		// ������带 �Է��Ϸ��� ����ü�� �� ���� ����
		if (i == 4) {
			total_node--;
			for (int j = 1; j <= 4; j++) {
				now->track[j] = new_track[j];
				now->key[j] = new_key[j];
			}
		}
	}
}
// �Է�
void input() {

	char comma, num;
	// ���󰡴� ���
	for (int i = 1; i <= 4; i++) {
		fscanf(inp, "%c", &num);
		new_track[i] = num;
	}
	// ,
	fscanf(inp, "%c", &comma);
	// �׶��� key ��
	for (int i = 1; i <= 4; i++) {
		fscanf(inp, "%c", &num);
		new_key[i] = num;
	}
}

void output(Record* root) {

	Record* now = root;
	// ������忡 ���� ���� ��
	if (length == 4) {
		// ���ϵ�ī�带 �ް� ������忡 ���� ������ idx++
		if (true_false == 0) idx++;
		for (int i = 1; i <= 4; i++) fprintf(out, "%c", now->track[i]);
		fprintf(out, " %d ", idx);
		for (int i = 1; i <= 4; i++) fprintf(out, "%c", now->key[i]);
		fprintf(out, " ");
		length--;
		return;
	}
	// �ؿ� �ڽ��� ������ ���
	for (int i = 0; i < 10; i++) {
		if (now->child[i] != NULL) {
			// ���̸� ã�� ���� ���� length
			length++;
			// ���
			output(now->child[i]);
		}
	}
	length--; idx = 0;
}
// ��� �� ������� ã�ư���
void check(Record* root) {

	Record* now = root; int tmp = 0;
	// * ������ ��������
	for (int i = 1; i <= length; i++) {
		if (now->child[check_key[i] - '0'] == NULL) {
			// ã�°� ������ tmp = 1
			tmp = 1;
			fprintf(out, "no\n");
			return;
		}
		now = now->child[check_key[i] - '0'];
		// 4�� �� �޾��� ��
		if (true_false == 1 && i == 3) {
			for (int j = 0; j < 10; j++) {
				// idx : ��ȿ ���ڵ� ����
				if (now->child[j] != NULL) idx++;
				// ��������� ���� ������
				if (j == (check_key[4] - '0')) break;
			}
		}
	}

	// ã�°� ������ �׶� �ش��ϴ� ������ ���
	if (tmp != 1) {
		output(now);
		fprintf(out, "\n");
	}
}

int main() {

	if ((inp = fopen("hw4.inp", "rt")) == NULL) fprintf(stderr, "cant't open %s\n", "hw4.inp");
	if ((out = fopen("hw4.out", "wt")) == NULL) fprintf(stderr, "cant't open %s\n", "hw4.out");

	Record* root = Create_Node();

	// �Է�
	while (1) {
		char check_char;

		fscanf(inp, "%c", &check_char);
		// \n������ �Է� ��
		if (check_char == '\n') break;

		else if (check_char == '(') {
			input();
			Insert_Node(root);
		}
	}

	fprintf(out, "%d\n", total_node);
	// ���
	for (int i = 1; ; i++) {

		char check_char;

		fscanf(inp, "%c", &check_char);

		// 4�� �ٹ޾��� ��
		if (i == 5) {
			length = i - 1;
			// ���� 4�� ������ ǥ���ϱ� ���ؼ� true_false
			true_false = 1;
			check(root);
			i = 1; idx = 0; true_false = 0; length = 0;
		}
		// \n������ �Է� ��
		if (check_char == '\n') {
			fprintf(out, "*");
			break;
		}
		// wildcard ���
		else if (check_char == '*') {
			length = i - 1;
			check(root); idx = 0; length = 0; i = 1;
		}

		// �� ���׵� �ƴҰ�� �迭�� �ֱ�
		check_key[i] = check_char;

		// ���� ���� �������� ������ �ʱ�ȭ
		if (check_char == ' ') {
			for (int i = 0; i <= 4; i++) check_key[i] = 0;
			i = 0;
		}
		
	}

	fclose(inp);
	fclose(out);
	return 0;
}