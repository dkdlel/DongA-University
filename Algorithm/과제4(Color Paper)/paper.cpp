#include <bits/stdc++.h>
#define MAXI 4001
using namespace std;

ifstream fcin("paper.inp");
ofstream fcout("paper.out");

struct info {
	int sequence, x, y, dx, dy, area; // sequence : ��ȣ(1,2,3...), x : x ��ǥ, y : y ��ǥ, dx : x + w, dy : y + h, area : ĥ���� ������ ����
};
vector < info > input;
vector <int> x_location, y_location;
//vector < vector < int > > board(MAXI, vector<int>::vector(MAXI));
int board[MAXI][MAXI];
int all_hide = 0, part_hide = 0, all_see = 0;
void X_Mapping() {
	for (int i = 0; i < input.size(); i++) {
		for (int j = 0; j < x_location.size(); j++) {
			if (input[i].x == x_location[j]) input[i].x = j;
			if (input[i].dx == x_location[j]) input[i].dx = j;
		}
	}
}
void Y_Mapping() {
	for (int i = 0; i < input.size(); i++) {
		for (int j = 0; j < y_location.size(); j++) {
			if (input[i].y == y_location[j]) input[i].y = j;
			if (input[i].dy == y_location[j]) input[i].dy = j;
		}
	}
}
void Paint() {
	for (int i = 0; i < input.size(); i++) {
		for (int j = input[i].x; j < input[i].dx; j++) {
			for (int k = input[i].y; k < input[i].dy; k++) {
				board[j][k] = input[i].sequence;
				input[i].area++;
			}
		}
	}
}
void Check() {
	for (int i = 0; i < input.size(); i++) {
		int cnt = 0;
		for (int j = input[i].x; j < input[i].dx; j++) {
			for (int k = input[i].y; k < input[i].dy; k++) {
				if (board[j][k] == input[i].sequence) cnt++;
			}
		}
		if (cnt == input[i].area) all_see++;
		else if (cnt == 0) all_hide++;
		else part_hide++;
	}
}
int main() {
	int n;
	fcin >> n;
	// �Է�
	for (int i = 0; i < n; i++) {
		info temp;
		fcin >> temp.x >> temp.y >> temp.dx >> temp.dy;
		input.push_back({ i, temp.x, temp.y, temp.x + temp.dx, temp.y + temp.dy });
		x_location.push_back(temp.x);
		x_location.push_back(temp.x + temp.dx);
		y_location.push_back(temp.y);
		y_location.push_back(temp.y + temp.dy);
	}
	// ���� 
	sort(x_location.begin(), x_location.end());
	sort(y_location.begin(), y_location.end());
	// �ߺ� ���� ����
	x_location.erase(unique(x_location.begin(), x_location.end()), x_location.end());
	y_location.erase(unique(y_location.begin(), y_location.end()), y_location.end());
	// �ش� index ��ȣ�� mapping
	X_Mapping();
	Y_Mapping();
	// �׸���
	Paint();
	// paper Ȯ��
	Check();
	fcout << all_hide << ' ' << part_hide << ' ' << all_see << '\n';
	return 0;
}