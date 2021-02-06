#include <stdio.h>
#include <stdlib.h>

FILE *inp, *out;
int row; // 행(가로박스)
int col; // 열(세로박스)
int total_num, type, start, distance, result;
int n1, n2; // 몫, 나머지

int type1_1() { // 좌상 , 시작점 1.1

	n1 = (distance-1) / col; // 그냥 나누기를 하면 col/col하면 1이되기때문에 다음줄로 넘어감, ex) 4/4 = 1 이나오면 다음줄로 넘어감
	n2 = (distance-1) % col +1; // 위와 동일하지만 1을 더하는 이유는 나머지를 1부터 시작하기 위해서, ex) 0 1 2 3 -> 1 2 3 4 

	if (n1 % 2 == 0){
		result = col * n1 + n2;
	}
	else {
		result = n1 * col + (col-n2) +1;
	}
	return result;
}
int type1_2() { // 우상, 시작점 몫 * col

	n1 = (distance - 1) / col;
	n2 = (distance - 1) % col + 1;

	if (n1 % 2 == 0) {
		result = n1 * col + (col - n2) + 1;
	}
	else {
		result = col * n1 + n2;
	}
	return result;
}
int type1_3() { // 우하, 시작점 row * col

	n1 = (distance - 1) / col;
	n2 = (distance - 1) % col + 1;
	int x = row, y = col;

	if (n1 % 2 == 0) {
		result = (x*y) - (n1 * col) - n2 +1;	
	}
	else {
		result = (x*y) - ((n1+1)*col)+ n2;
	}
	return result;
}
int type1_4() { // 좌하, 시작점 row*col - (col-1)

	n1 = (distance - 1) / col;
	n2 = (distance - 1) % col + 1;
	int x = row, y = 1;

	if (n1 % 2 == 0) {
		result = row * col - (col - 1) - (n1*col) + n2 - 1;
	}
	else {
		result = row * col - (col - 1) - ((n1-1)*col) - n2;
	}
	return result;
}
int type2_1() { // 좌상, 시작점 1.1
	
	int x = 1, y = 1;
	n1 = (distance - 1) / row;
	n2 = (distance - 1) % row + 1;

	if (n1 % 2 == 0) {
		result = x*y + n1 + ((n2 - 1) *col);
	}
	else {
		result = x*y + n1 + (row-n2) *col;
	}
	return result;
}
int type2_2() { // 우상, 시작점 1,col

	int x = 1, y = col;
	n1 = (distance - 1) / row;
	n2 = (distance - 1) % row + 1;

	if (n1 % 2 == 0) {
		result = x * y - n1 + ((n2 - 1) *col);
	}
	else {
		result = x * y - n1 + (row - n2) *col;
	}
	return result;
}
int type2_3() { //우하, 시작점 row*col

	int x = row, y = col;
	n1 = (distance - 1) / row;
	n2 = (distance - 1) % row + 1;

	if (n1 % 2 == 0) {
		result = x * y - n1 - ((n2 - 1) *col);
	}
	else {
		result = x * y - n1 - (row - n2) *col;
	}
	return result;
}
int type2_4() { //좌하, 시작점 row.1

	int x = row, y = 1;
	n1 = (distance - 1) / row;
	n2 = (distance - 1) % row + 1;

	if (n1 % 2 == 0) {
		result = x * col - (col-1) + n1 - ((n2 - 1) *col);
	}
	else {
		result = x * col - (col - 1) + n1 - (row - n2) *col;
	}
	return result;
}

int main() {
	
	inp = fopen("grid1.inp", "rt");
	out = fopen("grid1.out", "wt");

	fscanf(inp, "%d\n", &total_num);
	for (int i = 0; i < total_num; i++) {

		fscanf(inp, "%d %d %d %d %d", &row, &col, &type, &start, &distance);

		if (type == 1 && start == 1) {
			type1_1();
			fprintf(out, "%d\n", result);
		}
		else if (type == 1 && start == 2) {
			type1_2();
			fprintf(out, "%d\n", result);
		}
		else if (type == 1 && start == 3) {
			type1_3();
			fprintf(out, "%d\n", result);
		}
		else if (type == 1 && start == 4) {
			type1_4();
			fprintf(out, "%d\n", result);
		}
		else if (type == 2 && start == 1) {
			type2_1();
			fprintf(out, "%d\n", result);
		}
		else if (type == 2 && start == 2) {
			type2_2();
			fprintf(out, "%d\n", result);
		}
		else if (type == 2 && start == 3) {
			type2_3();
			fprintf(out, "%d\n", result);
		}
		else if (type == 2 && start == 4) {
			type2_4();
			fprintf(out, "%d\n", result);
		}

	}
	

	fclose(inp);
	fclose(out);
	return 0;
}