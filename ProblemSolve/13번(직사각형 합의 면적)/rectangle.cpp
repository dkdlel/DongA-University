#include<bits/stdc++.h>
#define MAX 20001
#define move 10000
using namespace std;

ifstream fcin("rectangles.inp");
ofstream fcout("rectangles.out");

typedef struct Point {
	char dir;
	int x, y1, y2;
};
bool operator<(Point a, Point b) {
	return a.x < b.x;
}
vector<Point> rec;
int minX, maxX, minY, maxY;

void Find(int x1, int y1, int x2, int y2) {
	if (minX > x1) minX = x1;
	if (minY > y1) minY = y1;
	if (maxX < x2) maxX = x2;
	if (maxY < y2) maxY = y2;
}
void Init() {
	minX = minY = MAX; maxX = maxY = -1;
	int num;
	fcin >> num;
	while (num--) {
		int x1, x2, y1, y2;
		fcin >> x1 >> y1 >> x2 >> y2;
		x1 += move; x2 += move; y1 += move; y2 += move;

		rec.push_back({ 'L',x1,y1,y2 });
		rec.push_back({ 'R',x2,y1,y2 });
		Find(x1, y1, x2, y2); 
	}
	sort(rec.begin(), rec.end());
}
void Sol() {
	vector<int> yPoint; yPoint.assign(maxY, 0);
	vector<Point> range;
	int size = rec.size(), area = 0;
	for (int i = 0; i < size -1;) {
		int cutlength = 0;
		while(rec[i].x == rec[i+1].x) // x좌표가 같은게 여러개일 경우
			range.push_back(rec[i++]);
		range.push_back(rec[i]);
		
		for (int j = 0; j < range.size(); j++) {
			if (range[j].dir == 'L') { // 왼쪽접선
				for (int k = range[j].y1; k < range[j].y2; k++) yPoint[k]++;
			}
			else { // 오른쪽 접선
				for (int k = range[j].y1; k < range[j].y2; k++) yPoint[k]--;
			}
		}
		
		// y좌표 범위 계산
		for (int j = 0; j < yPoint.size(); j++) {
			if (yPoint[j] > 0) cutlength++;
		}
		area += cutlength * (rec[i + 1].x - rec[i].x);
		i++; range.clear();
	}
	fcout << area << '\n';
}
int main() {
	
	Init();
	Sol();
	return 0;
}