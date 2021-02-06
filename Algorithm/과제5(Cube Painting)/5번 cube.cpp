#include<bits/stdc++.h>
using namespace std;

ifstream fcin("cube.inp");
ofstream fcout("cube.out");

enum { TOP, FRONT, LEFT, RIGHT, BACK, BOTTOM };
class Cube {
public:
	string dice1, dice2, cubes, rotate_dice, roll_dice, tmp_dice;
	// dice1 : 기본, dice2 : 찾아야할 주사위, cubes : 전체입력, rotate : 왼쪽회전
	// roll : 뒤->앞 방향으로 회전, tmp : 왼쪽이 위가 되는 주사위
	string blue = "bbbbbbbbbbbb";
	string red = "rrrrrrrrrrrr";
	string green = "gggggggggggg";
	void rotate(string& dice);
	void roll(string& dice);
	bool check(string dice);
};
void Cube::rotate(string& dice) {
	char tmp = dice[FRONT];
	dice[FRONT] = dice[RIGHT];
	dice[RIGHT] = dice[BACK];
	dice[BACK] = dice[LEFT];
	dice[LEFT] = tmp;
}
void Cube::roll(string& dice) {
	char tmp = dice[TOP];
	dice[TOP] = dice[BACK];
	dice[BACK] = dice[BOTTOM];
	dice[BOTTOM] = dice[FRONT];
	dice[FRONT] = tmp;
}
bool Cube::check(string dice) {
	for (int i = 0; i < 4; i++) {
		rotate(dice);
		if (dice == dice2) {
			fcout << "TRUE\n";
			return true;
		}
	}
	return false;
}
int main() {

	Cube cube;
	while (1) {
		getline(fcin, cube.cubes);
		if (cube.cubes == cube.blue || cube.cubes == cube.red || cube.cubes == cube.green) {
			fcout << "TRUE\n";
			break;
		}
		cube.dice1 = cube.cubes.substr(0, 6);
		cube.dice2 = cube.cubes.substr(6);
		// 왼쪽을 위로 만드는 작업
		cube.tmp_dice = cube.dice1;
		cube.rotate(cube.tmp_dice);
		cube.roll(cube.tmp_dice);
		// 왼쪽위 주사위 먼저 확인
		if (cube.check(cube.tmp_dice)) continue;
		cube.roll(cube.tmp_dice);
		cube.roll(cube.tmp_dice);
		if (cube.check(cube.tmp_dice)) continue;
		// 기본 주사위 확인
		bool flag = false;
		for (int i = 0; i < 4; i++) {
			if (cube.check(cube.dice1)) {
				flag = true;
				break;
			}
			cube.roll(cube.dice1);
		}
		if (flag) continue;
		fcout << "FALSE\n";
	}

	return 0;
}