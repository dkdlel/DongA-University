#include<bits/stdc++.h>
using namespace std;

ifstream fcin("p11994.inp");
ofstream fcout("p11994.out");

typedef struct infp {
	int parent, color;
}info;

vector<info> graph;
vector<bool> isvisit;
int n, m;
int type, x, y, c; // c : color
int sameancestor;
set <int> color_cnt;
int edge_cnt;

void Find_X_Ancestor(int x){
	isvisit[x] = true;
	if (!graph[x].parent) return;
	Find_X_Ancestor(graph[x].parent);
}
void Find_Y_Ancestor(int y){
	if (isvisit[y]) { // 같은 조상이 있음
		sameancestor = y;
		return;
	}
	if (!graph[y].parent) return;
	Find_Y_Ancestor(graph[y].parent);
}
bool CheckAncestor(int y) {
	if (y == 0) return true; // 겹치는거 없음
	if (x == graph[y].parent) return false; // 겹치는거 있음
	return CheckAncestor(graph[y].parent);
}
void PaintColor(int n) {
	if (n == sameancestor) return;
	graph[n].color = c;
	PaintColor(graph[n].parent);
}
void Count() {
	if (!sameancestor) { // 같은 조상이 없음
		fcout << "0 0\n";
		return;
	}
	int node = x;
	while (true) { // 같은 조상 만날때 까지
		if (x == sameancestor) break;
		color_cnt.insert(graph[x].color);
		edge_cnt++; x = graph[x].parent;
	}
	node = y;
	while (true) {
		if (y == sameancestor) break;
		color_cnt.insert(graph[y].color);
		edge_cnt++; y = graph[y].parent;
	}
	fcout << edge_cnt << ' ' << color_cnt.size() << '\n';
}
void Sol() {

	for (int t = 0; t < m; t++) {
		sameancestor = 0;
		isvisit.assign(m + 1, false);
		fcin >> type >> x >> y;
		Find_X_Ancestor(x); Find_Y_Ancestor(y);
		if (type == 1) {
			fcin >> c;
			if (x != y && CheckAncestor(y)) { // x랑 y랑 같지 않고 x가 y의 조상이 아님
				graph[x].parent = y;
				graph[x].color = c;
			}
		}
		else if (type == 2) {
			fcin >> c;
			// x와 y사이에 경로가 있을때
			if (sameancestor) {
				PaintColor(x);
				PaintColor(y);
			}
		}
		else {
			color_cnt.clear(); edge_cnt = 0;
			Count();
		}
	}
}
int main() {


	fcin >> n >> m;
	graph.resize(n + 1);
	for (int i = 1; i <= n; i++) fcin >> graph[i].parent;
	for (int i = 1; i <= n; i++) fcin >> graph[i].color;

	Sol();

	return 0;
}