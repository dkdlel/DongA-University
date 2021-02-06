#include <stdio.h>
#include <string.h>;
FILE *inp, *out;

int total_num, n1=1, num, cnt=0, num_1=0,temp,total;
int n2, n3; // n2 : 몫, n3 : 나머지
int N2[20]; // 나머지 저장
char test;
char in[100], output[100];

typedef enum alp{Z=0,A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y}ALP;

void TEMP(int a) { // 몫 switch 쓸래요
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
		n3 = (n2-1) % 26 +1; // 나머지
		n2 = n2 / 26; // 몫
		if (n3 == 26) n2--; // 나머지가 26일 경우에 1뺌(왜인지는 모르겠음 ㅡㅡ;;)
		if (n2 == 0) { // 몫이 0이면 그때의 나머지를 몫으로 저장
			n2 = n3;
			break;
		}
		N2[num_1] = n3; // 나머지를 배열에 저장(역순으로 출력해야함)
		num_1++; // N2배열 다음칸으로 넘기기
		cnt++; // 알파벳이 몇개인지 판별하기 위해서
	}

	TEMP(n2); // enum을 위해 사용된 TEMP함수
	for (int i = cnt-1; i >= 0; i--) {
		TEMP(N2[i]);
	} // 알파벳으로 변형해서 출력완료

	for (int i = 1; --n1; i++) {
		fprintf(out, "%c", in[i]);
	}
	fprintf(out, "\n");
}
void sol_char_to_num() {
	total = 0;
	fprintf(out, "R"); // 제일 처음 출력은 무조건 R이니까
	for (int i = n1 - 1; in[i] != NULL; i++) { // 입력받은 숫자 그대로 출력
		fprintf(out, "%c", in[i]);
	}
	if (in[0] >= 'A' && in[0] <= 'Z' && in[1] >= 'A' && in[1] <= 'Z') { // 문자가 여러개인 경우
		total = 26 * (in[0] - 64) + (in[1] - 64); // 연산인데 몫과 나머지를 활용해서 함 (진법 변환할때 처럼 나누고 하다보면 이게 뭔지 알꺼임 ㅋㅅㅋ)
		for (int i = 2; i < n1 - 1; i++) {
			total = total * 26 + (in[i] - 64);
		}
		fprintf(out, "C%d", total);
	}
	else // 문자가 한개인 경우
		fprintf(out, "C%d", in[0] - 64);

	
	fprintf(out, "\n");
}
void num_to_char() { // R23C55
	num = 0;
	n1 = 0;
	while (in[n1] != 'C') n1++; // C를 찾으로 가는중

	for (int i = n1 + 1; in[i] != NULL; i++) { // n1+1은 n1은 C에 해당하는 수이기 때문에, 숫자 변환 작업
		num *= 10; // 아스키코드 수를 아라비아수로 바꾸기
		num += in[i] - '0';
	}

	sol_num_to_char();
}

void char_to_num() { // BC23
	n1 = 1;
	for (;;) {
		if (in[n1-1] >= '0' && in[n1-1] <= '9') break; // 숫자면 탈출
		else n1++; // 문자다음 숫자의 수를 파악하기 위해서
	}

	for (int i = n1-1 ; in[i] != NULL; i++) { // n1-1은 한번 더돌았기 때문에, 거기서 부터 마지막까지
		num *= 10; 
		num += in[i] - '0';
	}

	sol_char_to_num();
}

void input() { // 경우의수 2개 따져보기위함
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