#include<bits/stdc++.h>
using namespace std;

ifstream fcin("cube.inp");
ofstream fcout("cube.out");

enum { TOP, FRONT, LEFT, RIGHT, BACK, BOTTOM };
class Cube {
public:
	string dice1, dice2, cubes, rotate_dice, roll_dice, tmp_dice;
	// dice1 : �⺻, dice2 : ã�ƾ��� �ֻ���, cubes : ��ü�Է�, rotate : ����ȸ��
	// roll : ��->�� �������� ȸ��, tmp : ������ ���� �Ǵ� �ֻ���
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
		// ������ ���� ����� �۾�
		cube.tmp_dice = cube.dice1;
		cube.rotate(cube.tmp_dice);
		cube.roll(cube.tmp_dice);
		// ������ �ֻ��� ���� Ȯ��
		if (cube.check(cube.tmp_dice)) continue;
		cube.roll(cube.tmp_dice);
		cube.roll(cube.tmp_dice);
		if (cube.check(cube.tmp_dice)) continue;
		// �⺻ �ֻ��� Ȯ��
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