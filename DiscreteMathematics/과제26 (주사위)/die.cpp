#include <fstream>
using namespace std;

ifstream fcin("die.inp");
ofstream fcout("die.out");

enum { Top = 1, Front, Bottom, Right, Back, Left };

int total_num,x,y;
int dice[7];
int top, front, num;
char dir;

// 오른쪽으로 돌리기
void right_rotation() {
	int tmp;
	tmp = dice[Front];
	dice[Front] = dice[Left];
	dice[Left] = dice[Back];
	dice[Back] = dice[Right];
	dice[Right] = tmp;
}
// 위로 돌리기
void up_rotation() {
	int tmp;
	tmp = dice[Top];
	dice[Top] = dice[Front];
	dice[Front] = dice[Bottom];
	dice[Bottom] = dice[Back];
	dice[Back] = tmp;
}
// top 찾기 위해 돌림
void find_top() {
	int tmp;
	tmp = dice[Top];
	dice[Top] = dice[Right];
	dice[Right] = dice[Bottom];
	dice[Bottom] = dice[Left];
	dice[Left] = tmp;
}
// 주사위 만들기
void make_dice() {
	// 둘중 하나가 같은걸 찾자
	for (int i = 0; i < 4; i++) {
		if (dice[Front] == top || dice[Front] == front) break;
		else right_rotation();
	}
	// top에 해당하는 숫자가 front에 있을경우 위로 회전
	if (dice[Front] == top) {
		up_rotation();
		//front가 같을때 까지 회전
		for (int i = 0; i < 4; i++) {
			if (dice[Front] == front) break;
			else right_rotation();
		}
	}
	// front에 해당하는 숫자가 front에 있을 경우
	else {
		// top에 해당하는 숫자가 있을때 까지
		for (int i = 0; i < 4; i++) {
			if (dice[Top] == top) break;
			else find_top();
		}
	}
}
// 동쪽 이동
void East() {
	x++;
	int tmp;
	tmp = dice[Top];
	dice[Top] = dice[Left];
	dice[Left] = dice[Bottom];
	dice[Bottom] = dice[Right];
	dice[Right] = tmp;
}
// 서쪽 이동
void West() {
	x--;
	int tmp;
	tmp = dice[Top];
	dice[Top] = dice[Right];
	dice[Right] = dice[Bottom];
	dice[Bottom] = dice[Left];
	dice[Left] = tmp;
}
// 북쪽 이동
void North() {
	y++;
	int tmp;
	tmp = dice[Top];
	dice[Top] = dice[Front];
	dice[Front] = dice[Bottom];
	dice[Bottom] = dice[Back];
	dice[Back] = tmp;
}
// 남쪽 이동
void South() {
	y--;
	int tmp;
	tmp = dice[Top];
	dice[Top] = dice[Back];
	dice[Back] = dice[Bottom];
	dice[Bottom] = dice[Front];
	dice[Front] = tmp;
}

int main() {

	fcin >> total_num;

	while (total_num--) {
		x = 0; y = 0; // 좌표
		// 주사위 생성
		for (int i = 1; i <= 6; i++) {
			fcin >> num;
			dice[i] = num;
		}
		fcin >> top >> front;
		make_dice();

		fcin >> num;
		for (int i = 0; i < num; i++) {
			fcin >> dir;
			if (dir == 'E') East();
			else if (dir == 'W') West();
			else if (dir == 'S') South();
			else North();
		}
		fcout << x << ' ' << y  << ' ' << dice[Top] << ' ' << dice[Front] << endl;
	}

	fcin.close();
	fcout.close();
	return 0;
}