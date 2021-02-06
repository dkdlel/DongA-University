#include <stdio.h>

FILE *inp, *out;

enum {UP = 0,DOWN,RIGHT,LEFT};
int typedirection[2][4][4] = {  // 모든 경우의 수들
	{
		{RIGHT,DOWN,LEFT,UP },{ DOWN,LEFT,UP,RIGHT },{ LEFT,UP,RIGHT,DOWN },{ UP,RIGHT,DOWN,LEFT } 
	},
	{
		{DOWN,RIGHT,UP,LEFT},{LEFT,DOWN,RIGHT,UP},{UP,LEFT,DOWN,RIGHT},{RIGHT,UP,LEFT,DOWN}
	}
};
int dir;

int total_num, row, col, type, start, distance, result;
int cur=0,r1,c1;
bool isEnd = true;

void up() {
	if (distance < r1) { // 그라인에서 출력
		result = cur - col * distance;
		fprintf(out, "%d\n", result);
		isEnd = false;
	}
	else {
		dir = (dir + 1) % 4;
		cur = cur - col * r1; // 다음 출발점 설정
		c1--; // 행 or 열 하나 제거
		distance -= r1; // 이동거리만큼 빼주기
	}
}

void down() {
	if (distance < r1) { // 그 라인에서 출력
		result = cur + col * distance;
		fprintf(out, "%d\n", result);
		isEnd = false;
	}
	else {
		dir = (dir + 1) % 4;
		cur = cur + col * r1;
		c1--;
		distance -= r1;
	}
}

void right() {
	if (distance < c1) {
		result = cur + distance;
		fprintf(out, "%d\n", result);
		isEnd = false;
	}
	else {
		dir = (dir + 1) % 4;
		cur = cur + c1;
		r1--;
		distance -= c1;
	}
}

void left() {
	if (distance < c1) {
		result = cur - distance;
		fprintf(out, "%d\n", result);
		isEnd = false;
	}
	else {
		dir = (dir + 1) % 4;
		cur = cur - c1;
		r1--;
		distance -= c1;
	}
}
void solve()
{
	isEnd = true;
	r1 = row; c1 = col;
	dir = 0;
	if (start == 1) {
		cur = (type == 3 ? 0 : 1-col);
	}
	else if (start == 2) {
		cur = (type == 3 ? 0 : col+1);
	}
	else if (start == 3) {
		cur = (type == 3 ? row * col + 1 : row * col + col);
	}
	else if (start == 4) {
		cur = (type == 3 ? row*col+1 : (row-1)*col);
	}

	while (isEnd)
	{
		int cur_1 = typedirection[type-3][start-1][dir];
		if (cur_1 == UP)
			up();
		else if (cur_1 == DOWN)
			down();
		else if (cur_1 == RIGHT)
			right();
		else if (cur_1 == LEFT)
			left();

		cur_1 = (cur_1 + 1) % 4;
	}
}
int main() {

	inp = fopen("grid2.inp", "rt");
	out = fopen("grid2.out", "wt");

	fscanf(inp, "%d\n", &total_num);

	for (int i = 0; i < total_num; i++) {
		fscanf(inp, "%d %d %d %d %d", &row, &col, &type, &start, &distance);
		solve();
	}

	fclose(inp);
	fclose(out);
	return 0;
}