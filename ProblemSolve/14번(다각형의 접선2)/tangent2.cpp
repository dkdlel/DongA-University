#include <bits/stdc++.h>
using namespace std;

ifstream fcin("tangent2.inp");
FILE* fcout = fopen("tangent2.out", "wt");
typedef struct Point {
	long long int x, y, dx, dy, n; // dx, dy : 시작점과의 거리, n : 순서
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
long long int getDirection(Point a, Point b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

vector<Point> pPoint, qPoint, hullPoint, pHull, qHull, Hull, innerpolygon;
int p_size, q_size;
int ptop, pbottom, qtop, qbottom;
bool pflag, qflag;

vector<Point> ConvexHull(vector<Point> point) {

	sort(point.begin(), point.end());
	for (int i = 1; i < point.size(); i++) {
		point[i].dx = point[i].x - point[0].x;
		point[i].dy = point[i].y - point[0].y;
	}
	sort(point.begin() + 1, point.end());

	stack<int> s;
	// 스택에 시작 2개 먼저 삽입
	s.push(0); s.push(1);
	int next = 2;
	// 외접을 찾기 위함
	while (next < point.size()) {
		while (s.size() >= 2) {
			int second = s.top(); s.pop();
			int first = s.top();
			if (ccw(point[first], point[second], point[next]) > 0) { // ccw가 양수면 좌회전
				s.push(second);
				break;
			}
		}
		s.push(next++);
	}
	vector<Point> point_result;
	point_result.resize(s.size());
	for (int i = point_result.size() - 1; i >= 0; i--) {
		point_result[i] = point[s.top()];
		s.pop();
	}

	return point_result;
}
void Init() {
	pPoint.clear(); qPoint.clear(); hullPoint.clear(); pHull.clear(); qHull.clear(); Hull.clear(); innerpolygon.clear();
	fcin >> p_size;
	pPoint.resize(p_size);
	for (int i = 0; i < p_size; i++) {
		int n1, n2;
		fcin >> n1 >> n2;
		pPoint[i] = { n1,n2,0,1,i,'P' };
		hullPoint.push_back(pPoint[i]);
	}

	fcin >> q_size;
	qPoint.resize(q_size);
	for (int i = 0; i < q_size; i++) {
		int n1, n2;
		fcin >> n1 >> n2;
		qPoint[i] = { n1,n2,0,1,i,'Q' };
		hullPoint.push_back(qPoint[i]);
	}

	pHull = ConvexHull(pPoint);
	qHull = ConvexHull(qPoint);
	Hull = ConvexHull(hullPoint);
}
void FindPoint() {
	// 전체 hull 중에서 p와 q 경계 찾기
	for (int i = 0; i < Hull.size(); i++) {
		Point cur, next;
		cur = Hull[i]; next = Hull[(i + 1) % Hull.size()];
		if (cur.ch == 'P' && next.ch == 'Q') { // bottom
			pbottom = cur.n; qbottom = next.n;
		}
		else if (cur.ch == 'Q' && next.ch == 'P') { // top
			ptop = next.n; qtop = cur.n;
		}
	}
	// 좌표의 순서 찾기
	for (int i = 0; i < pHull.size(); i++) {
		if (pHull[i].n == ptop) ptop = i;
		if (pHull[i].n == pbottom) pbottom = i;
	}
	for (int i = 0; i < qHull.size(); i++) {
		if (qHull[i].n == qtop) qtop = i;
		if (qHull[i].n == qbottom) qbottom = i;
	}

	// p와q 사이의 접선 찾기
	while (1) {
		pflag = qflag = false;
		for (int i = 0; i < qHull.size(); i++) { // qbottom 고정
			if (ccw(pHull[ptop], qHull[i], qHull[qbottom]) > 0) { // ptop을 기준으로 좌회전
				qflag = true;
				qbottom = (qbottom + qHull.size() - 1) % qHull.size();
				break;
			}
		}
		for (int i = 0; i < pHull.size(); i++) { // ptop 고정
			if (ccw(qHull[qbottom], pHull[i], pHull[ptop]) > 0) { // qbottom을 기준으로 좌회전
				pflag = true;
				ptop = (ptop + pHull.size() - 1) % pHull.size();
				break;
			}
		}
		if (!pflag && !qflag) break;
	}
	// 예외
	for (int i = 0; i < pHull.size(); i++) {
		if (ccw(pHull[ptop], pHull[i], qHull[qbottom]) == 0 && (getDirection(pHull[i], qHull[qbottom]) < getDirection(pHull[ptop], qHull[qbottom])))
			ptop = i;
	}
	for (int i = 0; i < qHull.size(); i++) {
		if (ccw(qHull[qbottom], qHull[i], pHull[ptop]) == 0 && (getDirection(qHull[i], pHull[ptop]) < getDirection(qHull[qbottom], pHull[ptop])))
			qbottom = i;
	}
	ptop = pHull[ptop].n; qbottom = qHull[qbottom].n;

	//q와p 사이의 접선 찾기
	while (1) {
		pflag = qflag = false;
		for (int i = 0; i < pHull.size(); i++) { // pbottom 고정
			if (ccw(qHull[qtop], pHull[i], pHull[pbottom]) < 0) { // qtop을 기준으로 우회전
				pflag = true;
				pbottom = (pbottom + 1) % pHull.size();
				break;
			}
		}
		for (int i = 0; i < qHull.size(); i++) { // qtop 고정
			if (ccw(pHull[pbottom], qHull[i], qHull[qtop]) < 0) { // pbottom을 기준으로 우회전
				qflag = true;
				qtop = (qtop + 1) % qHull.size();
				break;
			}
		}
		if (!pflag && !qflag) break;
	}
	// 예외
	for (int i = 0; i < pHull.size(); i++) {
		if (ccw(pHull[pbottom], pHull[i], qHull[qtop]) == 0 && (getDirection(pHull[i], qHull[qtop]) < getDirection(pHull[pbottom], qHull[qtop])))
			pbottom = i;
	}
	for (int i = 0; i < qHull.size(); i++) {
		if (ccw(qHull[qtop], qHull[i], pHull[pbottom]) == 0 && (getDirection(qHull[i], pHull[pbottom]) < getDirection(qHull[qtop], pHull[pbottom])))
			qtop = i;
	}
	pbottom = pHull[pbottom].n; qtop = qHull[qtop].n;
}
void Cal() {
	// point들에 대해서 innerpolygon 찾기
	for (int i = pbottom;; ) {
		innerpolygon.push_back(pPoint[i]);
		if (i == ptop) break;
		i = (i + 1) % p_size;
	}
	for (int i = qtop;; ) {
		innerpolygon.push_back(qPoint[i]);
		if (i == qbottom) break;
		i = (i + 1) % q_size;
	}
	innerpolygon.push_back(innerpolygon[0]);

	double area = 0;
	for (int i = 0; i < innerpolygon.size() - 1; i++) {
		area += (innerpolygon[i].x * innerpolygon[i + 1].y) - (innerpolygon[i + 1].x * innerpolygon[i].y);
	}
	fprintf(fcout, "%0.1f\n", 0.5 * fabs(area));
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