#include <bits/stdc++.h>
using namespace std;

ifstream fcin("tangent.inp");
FILE* fcout = fopen("tangent.out", "wt");
typedef struct Point {
	long long int x, y, dx, dy; // dx, dy : 시작점과의 거리
	char ch; // 도형

	bool operator<(const Point& P) {
		if (dy * P.dx != dx * P.dy) return dy * P.dx < dx* P.dy;
		if (x != P.x) return x < P.x;
		return y < P.y;
	}
};
long long int ccw(const Point& A, const Point& B, const Point& C) {
	return A.x * B.y + B.x * C.y + C.x * A.y - B.x * A.y - C.x * B.y - A.x * C.y;
}

vector<Point> P, Q, polygon, hullpoint, innerpolygon;
int p_size, q_size, p_idx, q_idx; // idx : 시작하는 위치의 번호를 알기 위해서
Point ptop, pbottom, qtop, qbottom;

void ConvexHull() {
	stack<int> s;
	// 스택에 시작 2개 먼저 삽입
	s.push(0); s.push(1);
	int next = 2;
	// 외접을 찾기 위함
	while (next < p_size + q_size) {
		while (s.size() >= 2) {
			int second = s.top(); s.pop();
			int first = s.top();
			if (ccw(polygon[first], polygon[second], polygon[next]) > 0) { // ccw가 양수면 좌회전
				s.push(second);
				break;
			}
		}
		s.push(next++);
	}
	hullpoint.resize(s.size());
	for (int i = hullpoint.size() - 1; i >= 0; i--) {
		hullpoint[i] = polygon[s.top()];
		s.pop();
	}
}
void Init() {
	P.clear(); Q.clear(); polygon.clear(); hullpoint.clear(); innerpolygon.clear();
	fcin >> p_size;
	P.resize(p_size);
	for (int i = 0; i < p_size; i++) {
		int n1, n2;
		fcin >> n1 >> n2;
		P[i] = { n1,n2,0,1,'P' };
		polygon.push_back(P[i]);
	}

	fcin >> q_size;
	Q.resize(q_size);
	for (int i = 0; i < q_size; i++) {
		int n1, n2;
		fcin >> n1 >> n2;
		Q[i] = { n1,n2,0,1,'Q' };
		polygon.push_back(Q[i]);
	}

	sort(polygon.begin(), polygon.end());
	for (int i = 1; i < p_size + q_size; i++) {
		polygon[i].dx = polygon[i].x - polygon[0].x;
		polygon[i].dy = polygon[i].y - polygon[0].y;
	}
	sort(polygon.begin() + 1, polygon.end());

	ConvexHull();
}
long long int getDirection(Point a, Point b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
void FindPoint() {
	for (int i = 0; i < hullpoint.size(); i++) {
		Point cur, next;
		cur = hullpoint[i]; next = hullpoint[(i + 1) % hullpoint.size()];
		if (cur.ch == 'P' && next.ch == 'Q') { // 아래 접선
			pbottom = cur; qbottom = next;
			// 예외 1
			for (int j = 0; j < p_size; j++) {
				if (ccw(cur, P[j], next) == 0 && (getDirection(P[j], next) < getDirection(cur, next) ) ) {
					cur = P[j], pbottom = P[j];
				}
			}
			for (int j = 0; j < q_size; j++) {
				if (ccw(cur, Q[j], next) == 0 && (getDirection(cur, Q[j]) < getDirection(cur, next))) {
						next = Q[j], qbottom = Q[j];
				}
			}
		}
		else if (cur.ch == 'Q' && next.ch == 'P') { // 위 접선
			ptop = next; qtop = cur;
			// 예외 1
			for (int j = 0; j < p_size; j++) {
				if (ccw(cur, P[j], next) == 0 && (getDirection(P[j], cur) < getDirection(next, cur))) {
						next = P[j], ptop = P[j];
					}
			}
			for (int j = 0; j < q_size; j++) {
				if (ccw(cur, Q[j], next) == 0 && (getDirection(next, Q[j]) < getDirection(next, cur))) {
						cur = Q[j], qtop = Q[j];
				}
			}
		}

	}

	// 좌표의 순서 찾기
	for (int i = 0; i < P.size(); i++) {
		if (P[i].x == pbottom.x && P[i].y == pbottom.y) {
			p_idx = i; break;
		}
	}
	for (int i = 0; i < Q.size(); i++) {
		if (Q[i].x == qtop.x && Q[i].y == qtop.y) {
			q_idx = i; break;
		}
	}
}
void Cal() {
	for (int i = p_idx;; ) {
		innerpolygon.push_back(P[i]);
		if (P[i].x == ptop.x && P[i].y == ptop.y) break;
		i = (i + 1) % p_size;
	}
	for (int i = q_idx;; ) {
		innerpolygon.push_back(Q[i]);
		if (Q[i].x == qbottom.x && Q[i].y == qbottom.y) break;
		i = (i + 1) % q_size;
	}
	innerpolygon.push_back(innerpolygon[0]);

	double area = 0;
	for (int i = 0; i < innerpolygon.size() - 1; i++) {
		area += (innerpolygon[i].x * innerpolygon[i + 1].y) - (innerpolygon[i + 1].x * innerpolygon[i].y);
	}
	// 예외 2
	if ((ptop.x == pbottom.x) && (ptop.y == pbottom.y)) {
		for (int i = 0; i < p_size; i++) {
			int j = (i + 1) % p_size;
			area += (P[i].x * P[j].y) - (P[i].y * P[j].x);
		}
	}
	else if ((qtop.x == qbottom.x) && (qtop.y == qbottom.y)) {
		for (int i = 0; i < q_size; i++) {
			int j = (i + 1) % q_size;
			area += (Q[i].x * Q[j].y) - (Q[i].y * Q[j].x);
		}
	}
	fprintf(fcout,"%0.1f\n",0.5 * fabs(area));
}
int main() {

	int testcase;
	fcin >> testcase;

	while (testcase--) {
		Init();
		FindPoint();
		Cal();
	}
	return 0;
}