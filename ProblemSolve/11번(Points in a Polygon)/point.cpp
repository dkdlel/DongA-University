#include<bits/stdc++.h>
using namespace std;

ifstream fcin("point.inp");
ofstream fcout("point.out");

typedef struct Point {
	int x, y;
};

long long int ccw(const Point& A, const Point& B, const Point& C) {
	return A.x * B.y + B.x * C.y + C.x * A.y - B.x * A.y - C.x * B.y - A.x * C.y;
}

vector<Point> point;
Point origin;
int num, testcase, cross_cnt;

bool Between(Point a, Point b, Point c) {
	if (ccw(a, b, c) != 0) return false;
	if (a.x != b.x) return a.x <= c.x && c.x <= b.x || b.x <= c.x && c.x <= a.x;
	else return a.y <= c.y && c.y <= b.y || b.y <= c.y && c.y <= a.y;
}

bool Sol() {

	cross_cnt = 0;

	for (int i = 0; i < num; i++) {
		int next = (i + 1) % num;
		if (Between(point[i], point[next], origin)) return true;
		if (point[i].y < origin.y && point[next].y >= origin.y && ccw(point[i], point[next], origin) > 0
			|| point[next].y < origin.y && point[i].y >= origin.y && ccw(point[next], point[i], origin) > 0)
			cross_cnt++;
	}

	return cross_cnt % 2;
}
int main() {

	fcin >> num;
	point.resize(num);
	for (int i = 0; i < num; i++) fcin >> point[i].x >> point[i].y;
	
	fcin >> testcase;
	for (int i = 0; i < testcase; i++) {
		fcin >> origin.x >> origin.y;
		fcout << Sol() << '\n';
	}


	return 0;
}

