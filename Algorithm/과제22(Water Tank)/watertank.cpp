#include<bits/stdc++.h>
using namespace std;

ifstream fcin("watertank.inp");
ofstream fcout("watertank.out");

typedef struct inf {
	int x, y, h; // x, y : 좌표, h : 그때의 높이
};
bool operator <(inf A, inf B) {
	return A.h > B.h;
};
class WaterTank {
public:
	int T, N, M, H; // T : testcase, N : 세로, M : 가로, H : 높이
	int result; // 결과
	vector< vector < int > > watertank; // 결과
	vector< vector < bool > > visited; // 방문 여부
	vector< vector < int > > row; // 가로 입력
	vector< vector < int > > col; // 세로 입력
	priority_queue<inf> pq; // 블럭에서 구멍이 뚫려있는거
	void Init(); // 초기화
	void Sol();
};
void WaterTank::Init() {
	result = 0;
	fcin >> N >> M >> H;
	watertank.clear();  watertank.resize(N + 2, vector<int>(M + 2, 0));
	visited.clear();  visited.resize(N + 2, vector<bool>(M + 2, false));
	row.clear(); row.resize(N + 3, vector<int>(M + 2, -1));
	col.clear(); col.resize(N + 2, vector<int>(M + 3, -1));

	// 물탱크 초기화
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			watertank[i][j] = H;
	// row 입력
	for (int i = 1; i <= N + 1; i++) {
		for (int j = 1; j <= M; j++) {
			fcin >> row[i][j];
			if (i == 1 && row[i][j] != -1)
				pq.push({ i - 1, j, -1 });
			else if (i == N + 1 && row[i][j] != -1)
				pq.push({ i, j, -1 });
		}
	}
	// col 입력
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M + 1; j++) {
			fcin >> col[i][j];
			if (j == 1 && col[i][j] != -1)
				pq.push({ i, j - 1, -1 });
			if (j == M + 1 && col[i][j] != -1)
				pq.push({ i, j, -1 });
		}
	}
}
void WaterTank::Sol() {
	while (!pq.empty())
	{
		int x = pq.top().x;
		int y = pq.top().y;
		pq.pop();

		if (!visited[x][y]) {
			visited[x][y] = true;

			if (y + 1 <= M && col[x][y + 1] != -1){ // 오른쪽
				if (watertank[x][y] <= col[x][y + 1])
					watertank[x][y + 1] = min(watertank[x][y + 1], col[x][y + 1]);
				else{
					if (watertank[x][y + 1] >= col[x][y + 1])
						watertank[x][y + 1] = min(watertank[x][y + 1], watertank[x][y]);
					else
						watertank[x][y + 1] = max(watertank[x][y + 1], watertank[x][y]);
				}
				if (!visited[x][y + 1])
					pq.push({ x,y + 1,col[x][y + 1] });
			}
			if (y - 1 >= 1 && col[x][y] != -1){ // 왼쪽
				if (watertank[x][y] <= col[x][y])
					watertank[x][y - 1] = min(watertank[x][y - 1], col[x][y]);
				else{
					if (watertank[x][y - 1] >= col[x][y])
						watertank[x][y - 1] = min(watertank[x][y - 1], watertank[x][y]);
					else
						watertank[x][y - 1] = max(watertank[x][y - 1], watertank[x][y]);
				}
				if (!visited[x][y - 1])
					pq.push({ x,y - 1, col[x][y] });
			}
			if (x + 1 <= N && row[x + 1][y] != -1){ // 아래
				if (watertank[x][y] <= row[x + 1][y])
					watertank[x + 1][y] = min(watertank[x + 1][y], row[x + 1][y]);
				else{
					if (watertank[x + 1][y] >= row[x + 1][y])
						watertank[x + 1][y] = min(watertank[x + 1][y], watertank[x][y]);
					else
						watertank[x + 1][y] = max(watertank[x + 1][y], watertank[x][y]);
				}
				if (!visited[x + 1][y])
					pq.push({ x + 1,y, row[x + 1][y] });
			}
			if (x - 1 >= 1 && row[x][y] != -1){ // 위
				if (watertank[x][y] <= row[x][y])
					watertank[x - 1][y] = min(watertank[x - 1][y], row[x][y]);
				else{
					if (watertank[x - 1][y] >= row[x][y])
						watertank[x - 1][y] = min(watertank[x - 1][y], watertank[x][y]);
					else
						watertank[x - 1][y] = max(watertank[x - 1][y], watertank[x][y]);
				}
				if (!visited[x - 1][y])
					pq.push({ x - 1,y, row[x][y] });
			}
		}
	}
}
int main() {

	WaterTank wt;
	fcin >> wt.T;
	while (wt.T--) {
		wt.Init();
		wt.Sol();
		for (int i = 1; i <= wt.N; i++)
			for (int j = 1; j <= wt.M; j++)
				wt.result += wt.watertank[i][j];
		fcout << wt.result << '\n';
	}
	return 0;
}