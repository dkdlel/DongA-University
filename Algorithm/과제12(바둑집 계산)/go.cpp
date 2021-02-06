#include <bits/stdc++.h>
using namespace std;

ifstream fcin("go.inp");
ofstream fcout("go.out");
enum { UP, DOWN, LEFT, RIGHT };
class Go {
public:
	int n1 = 0, cnt = 0, nextx = 0, nexty = 0, black_cnt = 0, white_cnt = 0, black_room = 0, white_room = 0; // n1 : n x n, cnt : 집의 갯수
	vector < vector < char > > board; // 바둑판
	vector < vector < bool > > visited; // 방문 했는지 안했는지
	void Input();
	void Sol(int x, int y);
	void FindNext(int x, int y, int n);
};
void Go::Input() {
	fcin >> n1;
	for (int i = 0; i < n1; i++) {
		board.resize(n1);
		visited.resize(n1);
		for (int j = 0; j < n1; j++) {
			board[i].resize(n1);
			visited[i].resize(n1);
			fcin >> board[i][j];
		}
	}
}
void Go::FindNext(int x , int y, int n) {
	if (n == UP) { // 위
		nextx = x - 1; nexty = y;
	}
	else if (n == DOWN) { // 아래
		nextx = x + 1; nexty = y;
	}
	else if (n == LEFT) { // 왼쪽
		nextx = x; nexty = y - 1;
	}
	else { // 오른쪽
		nextx = x; nexty = y + 1;
	}
}
void Go::Sol(int x, int y) {
	visited[x][y] = true; cnt++;
	for (int i = 0; i < 4; i++) { // 위, 아래, 왼쪽, 오른쪽
		FindNext(x, y, i); // 다음 좌표를 찾기 위해
		if (nextx >= 0 && nexty >= 0 && nextx < n1 && nexty < n1 && !visited[nextx][nexty]) {
			// 왼쪽 && 위 && 아래 && 오른쪽
			if (board[nextx][nexty] == 'B') black_cnt++;
			else if (board[nextx][nexty] == 'W') white_cnt++;
			else Sol(nextx, nexty);
		}
	}
}
int main() {
	
	Go go;
	go.Input();
	for (int i = 0; i < go.n1; i++) {
		for (int j = 0; j < go.n1; j++) {
			if (go.board[i][j] == '.' && !go.visited[i][j]) {
				go.Sol(i, j);
				if (go.black_cnt == 0) go.white_room += go.cnt; // 흰색으로 가득 차 있으면
				else if (go.white_cnt == 0) go.black_room += go.cnt; // 검은색으로 가득 차 있으면
				go.cnt = 0; go.black_cnt = 0; go.white_cnt = 0;
			}
		}
	}
	fcout << go.black_room << ' ' << go.white_room << '\n';
	return 0;
}