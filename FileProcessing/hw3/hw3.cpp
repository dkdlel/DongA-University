#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *inp = fopen("hw4.inp", "rt");
FILE *out = fopen("hw4.out", "wt");

char new_track[5], new_key[5], check_key[5];
int length, total_node = 1, idx;
int true_false;

// 레코드 선언
typedef struct Record {
	struct Record* child[10];
	int check;
	char track[5], key[5];
}Record;

Record* Create_Node() { // 노드 만들기
	Record* new_Node = (Record *)malloc(sizeof(Record));
	// 사실 필요없엉
	new_Node->check = 0;
	// 초기화
	for (int i = 0; i < 10; i++) new_Node->child[i] = 0;
	return new_Node;
}

void Insert_Node(Record* root) {

	Record* now = root;
	// 노드 생성
	for (int i = 1; i <= 4; i++) {
		if (!now->child[new_track[i] - '0']) {
			total_node++;
			now->child[new_track[i] - '0'] = Create_Node();
		}
		now = now->child[new_track[i] - '0'];
		// 이건 사실 필요 없어
		now->check = 1;
		// 리프노드를 입력하려면 구조체에 그 값들 대입
		if (i == 4) {
			total_node--;
			for (int j = 1; j <= 4; j++) {
				now->track[j] = new_track[j];
				now->key[j] = new_key[j];
			}
		}
	}
}
// 입력
void input() {

	char comma, num;
	// 따라가는 경로
	for (int i = 1; i <= 4; i++) {
		fscanf(inp, "%c", &num);
		new_track[i] = num;
	}
	// ,
	fscanf(inp, "%c", &comma);
	// 그때의 key 값
	for (int i = 1; i <= 4; i++) {
		fscanf(inp, "%c", &num);
		new_key[i] = num;
	}
}

void output(Record* root) {

	Record* now = root;
	// 리프노드에 도착 했을 때
	if (length == 4) {
		// 와일드카드를 받고 리프노드에 도착 했을때 idx++
		if (true_false == 0) idx++;
		for (int i = 1; i <= 4; i++) fprintf(out, "%c", now->track[i]);
		fprintf(out, " %d ", idx);
		for (int i = 1; i <= 4; i++) fprintf(out, "%c", now->key[i]);
		fprintf(out, " ");
		length--;
		return;
	}
	// 밑에 자식이 있으면 재귀
	for (int i = 0; i < 10; i++) {
		if (now->child[i] != NULL) {
			// 깊이를 찾아 가기 위한 length
			length++;
			// 재귀
			output(now->child[i]);
		}
	}
	length--; idx = 0;
}
// 출력 전 리프노드 찾아가기
void check(Record* root) {

	Record* now = root; int tmp = 0;
	// * 전까지 내려가기
	for (int i = 1; i <= length; i++) {
		if (now->child[check_key[i] - '0'] == NULL) {
			// 찾는게 없으면 tmp = 1
			tmp = 1;
			fprintf(out, "no\n");
			return;
		}
		now = now->child[check_key[i] - '0'];
		// 4개 다 받았을 때
		if (true_false == 1 && i == 3) {
			for (int j = 0; j < 10; j++) {
				// idx : 유효 레코드 숫자
				if (now->child[j] != NULL) idx++;
				// 리프노드의 수랑 같으면
				if (j == (check_key[4] - '0')) break;
			}
		}
	}

	// 찾는게 있으면 그때 해당하는 값들을 출력
	if (tmp != 1) {
		output(now);
		fprintf(out, "\n");
	}
}

int main() {

	if ((inp = fopen("hw4.inp", "rt")) == NULL) fprintf(stderr, "cant't open %s\n", "hw4.inp");
	if ((out = fopen("hw4.out", "wt")) == NULL) fprintf(stderr, "cant't open %s\n", "hw4.out");

	Record* root = Create_Node();

	// 입력
	while (1) {
		char check_char;

		fscanf(inp, "%c", &check_char);
		// \n받으면 입력 끝
		if (check_char == '\n') break;

		else if (check_char == '(') {
			input();
			Insert_Node(root);
		}
	}

	fprintf(out, "%d\n", total_node);
	// 계산
	for (int i = 1; ; i++) {

		char check_char;

		fscanf(inp, "%c", &check_char);

		// 4개 다받았을 때
		if (i == 5) {
			length = i - 1;
			// 숫자 4개 받은거 표현하기 위해서 true_false
			true_false = 1;
			check(root);
			i = 1; idx = 0; true_false = 0; length = 0;
		}
		// \n받으면 입력 끝
		if (check_char == '\n') {
			fprintf(out, "*");
			break;
		}
		// wildcard 계산
		else if (check_char == '*') {
			length = i - 1;
			check(root); idx = 0; length = 0; i = 1;
		}

		// 위 사항들 아닐경우 배열에 넣기
		check_key[i] = check_char;

		// 다음 수가 있을수도 있으니 초기화
		if (check_char == ' ') {
			for (int i = 0; i <= 4; i++) check_key[i] = 0;
			i = 0;
		}
		
	}

	fclose(inp);
	fclose(out);
	return 0;
}