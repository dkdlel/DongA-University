#include<bits/stdc++.h>
using namespace std;

ifstream fcin("pandora.inp");
ofstream fcout("pandora.out");
// 0 : 아래, 1 : 오른쪽, 2 : 위, 3 : 왼쪽
class Pandora {
public:
	int x_axis, y_axis, dir; // x축, y축, dir : 방향
	string str;
	void Sol();
};
//void Pandora::Sol() {
//	fcin >> str;
//	x_axis = y_axis = 1; dir = 0; // 초기화
//	// 출발이 R인 경우 연결 될 수 있기 때문에
//	str += str[0];
//	str += str[1];
//	for (int i = 0; i < str.size() - 1; i++) {
//		if (str[i] == 'R' && str[i + 1] == 'R') {
//			if (dir & 1) x_axis = 0; // 진행방향이 왼쪽 오른쪽이고, 각도가 270도인 경우 x 축으로 오목
//			else y_axis = 0; // 진행방향이 위쪽 아래쪽이고, 각도가 270도인 경우 y 축으로 오목
//		}
//		dir = str[i] == 'L' ? (dir + 3) % 4 : (dir + 1) % 4;
//		// +3을 하면 안쪽으로(90도) 회전, +1을 하면 바깥쪽으로(270도) 회전
//	}
//}
void Pandora::Sol() {
	fcin >> str;
	x_axis = y_axis = 1; dir = 0; // 초기화
	for (int i = 0; i < str.size(); i++) {
		int j = (i + 1) % str.size(); // 출발이 R인 경우 연결 될 수 있기 때문에
		if (str[i] == 'R' && str[j] == 'R') {
			if (dir & 1) x_axis = 0; // 진행방향이 왼쪽 오른쪽이고, 각도가 270도인 경우 x 축으로 오목
			else y_axis = 0; // 진행방향이 위쪽 아래쪽이고, 각도가 270도인 경우 y 축으로 오목
		}
		dir = str[i] == 'L' ? (dir + 3) % 4 : (dir + 1) % 4;
		// +3을 하면 안쪽으로(90도) 회전, +1을 하면 바깥쪽으로(270도) 회전
	}
}
int main() {

	Pandora pan;
	int testcase, j;
	fcin >> testcase;
	while (testcase--) {
		pan.Sol();
		fcout << pan.x_axis + pan.y_axis << '\n';
	}
	return 0;
}