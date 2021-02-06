#include<bits/stdc++.h>
using namespace std;

ifstream fcin("ladder.inp");
ofstream fcout("ladder.out");

struct Info {
	int num, dest_line, dest_num;
	// num : sort를 위한 숫자, dest_line : 도착 라인, dest_num : 도착지점의 수
};
bool compare(Info a, Info b) {
	return a.num > b.num;
}
class Ladder {
private:
	int next_vertical_num, next_idx, result_idx;
public:
	bool flag; // 처음 사용하는지 아닌지를 위한 판단
	int line_num;
	vector < vector < Info > > line;
	vector <int> result;
	void Sol(int vertical_num, int idx);
	void Find_Next(int next_vertical_num, int dest_num);
};
void Ladder::Sol(int vertical_num, int idx) {
	// vertical_num : 세로 선, idx : 다음 사용할 인덱스
	if (flag) { // 처음에 입력받은 세로선을 저장하기 위해
		result_idx = vertical_num;
		flag = false;
	}
	if (idx == line[vertical_num].size()) {
		result[vertical_num] = result_idx;
		return;
	}
	next_vertical_num = line[vertical_num][idx].dest_line;
	Find_Next(next_vertical_num, line[vertical_num][idx].dest_num);
	Sol(next_vertical_num, next_idx);
}
void Ladder::Find_Next(int next_vertical_num, int dest_num) {
	for (int i = 0; i < line[next_vertical_num].size(); i++) {
		if (line[next_vertical_num][i].num == dest_num) {
			next_idx = i + 1;
			break;
		}
	}
}
int main() {
	int x1, y1, x2, y2;
	Ladder ladder;
	fcin >> ladder.line_num;
	ladder.line.resize(ladder.line_num);
	ladder.result.resize(ladder.line_num);
	while(1) {
		fcin >> x1 >> y1 >> x2 >> y2;
		if (x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0) break;
		ladder.line[x1].push_back({ y1,x2,y2 });
		ladder.line[x2].push_back({ y2,x1,y1 });
	}
	for (int i = 0; i < ladder.line_num; i++) 
		sort(ladder.line[i].begin(), ladder.line[i].end(),compare);
	for (int i = 0; i < ladder.line_num; i++) {
		ladder.flag = true;
		ladder.Sol(i, 0);
	}
	for (int i = 0; i < ladder.line_num; i++)
		fcout << ladder.result[i] << ' ';
	return 0;
}