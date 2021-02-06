#include <fstream>
using namespace std;

ifstream fcin("die.inp");
ofstream fcout("die.out");

enum { Top = 1, Front, Bottom, Right, Back, Left };

int total_num,x,y;
int dice[7];
int top, front, num;
char dir;

// ���������� ������
void right_rotation() {
	int tmp;
	tmp = dice[Front];
	dice[Front] = dice[Left];
	dice[Left] = dice[Back];
	dice[Back] = dice[Right];
	dice[Right] = tmp;
}
// ���� ������
void up_rotation() {
	int tmp;
	tmp = dice[Top];
	dice[Top] = dice[Front];
	dice[Front] = dice[Bottom];
	dice[Bottom] = dice[Back];
	dice[Back] = tmp;
}
// top ã�� ���� ����
void find_top() {
	int tmp;
	tmp = dice[Top];
	dice[Top] = dice[Right];
	dice[Right] = dice[Bottom];
	dice[Bottom] = dice[Left];
	dice[Left] = tmp;
}
// �ֻ��� �����
void make_dice() {
	// ���� �ϳ��� ������ ã��
	for (int i = 0; i < 4; i++) {
		if (dice[Front] == top || dice[Front] == front) break;
		else right_rotation();
	}
	// top�� �ش��ϴ� ���ڰ� front�� ������� ���� ȸ��
	if (dice[Front] == top) {
		up_rotation();
		//front�� ������ ���� ȸ��
		for (int i = 0; i < 4; i++) {
			if (dice[Front] == front) break;
			else right_rotation();
		}
	}
	// front�� �ش��ϴ� ���ڰ� front�� ���� ���
	else {
		// top�� �ش��ϴ� ���ڰ� ������ ����
		for (int i = 0; i < 4; i++) {
			if (dice[Top] == top) break;
			else find_top();
		}
	}
}
// ���� �̵�
void East() {
	x++;
	int tmp;
	tmp = dice[Top];
	dice[Top] = dice[Left];
	dice[Left] = dice[Bottom];
	dice[Bottom] = dice[Right];
	dice[Right] = tmp;
}
// ���� �̵�
void West() {
	x--;
	int tmp;
	tmp = dice[Top];
	dice[Top] = dice[Right];
	dice[Right] = dice[Bottom];
	dice[Bottom] = dice[Left];
	dice[Left] = tmp;
}
// ���� �̵�
void North() {
	y++;
	int tmp;
	tmp = dice[Top];
	dice[Top] = dice[Front];
	dice[Front] = dice[Bottom];
	dice[Bottom] = dice[Back];
	dice[Back] = tmp;
}
// ���� �̵�
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
		x = 0; y = 0; // ��ǥ
		// �ֻ��� ����
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