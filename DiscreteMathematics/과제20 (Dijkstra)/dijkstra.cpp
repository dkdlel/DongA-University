#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#define INF 0x7FFFFFFF // INF ǥ���Ҽ��ִ� �ִ밪
using namespace std;

ifstream fcin("dijkstra.inp");
ofstream fcout("dijkstra.out");

struct V_inf {
	int pre, v, w, n; // pre : ����, v : ����, w : ����ġ, n : ������ ����
};

bool operator<(V_inf A, V_inf B) { return (A.w == B.w ? A.n < B.n : A.w > B.w); }

vector< vector < V_inf > > Vertex_inf; // �������� ���� ����
vector< vector < int > > result;
int pre_vertex, vertex, weight;
int vertex_num, edge_num; // �������� ������
int Dist[2][1000000]; // ���� ����, �ִܰŸ� ������ �迭

void go_back(int p, int n) {

	if (Dist[0][p] == -1) { // 0���� ����̸�
		return;
	}
	if (Dist[0][p] == -INF) { // ���Ѵ��̸�
		result[n].push_back(0);
		return;
	}
	if (result[Dist[0][p]].size() > 0) { // 0�� ����� ������ �ƴ� ��
		for (int i = 0; i < result[Dist[0][p]].size(); i++) {
			result[n].push_back(result[Dist[0][p]][i]);
		}
		return;
	}
	// 0�� ����� �����̸�
	result[n].push_back(Dist[0][p]);
	return go_back(Dist[0][p], n);
}

void dijkstra() {

	bool Visited[10000] = { false, };
	priority_queue < V_inf > pq;
	vector <int> Input_Num(vertex_num, -INF);

	Dist[1][0] = { 0 };
	pq.push({ -1,0,0,-1 }); // ���� ����, ���� ���� , ����ġ , �Էµ� ������ ����

	while (!pq.empty()) {

		int pre = pq.top().pre;
		int cur = pq.top().v;
		int w = pq.top().w;
		int n = pq.top().n;
		pq.pop();

		if (Dist[1][cur] == w) {
			if (Input_Num[cur] < n) {
				Input_Num[cur] = n;
				Dist[0][cur] = pre;
			}
		}
		if (Visited[cur]) continue;
		Visited[cur] = true;

		for (int i = 0; i < Vertex_inf[cur].size(); i++) { // �Ÿ� �迭�� �ֽ�ȭ
			int alt = Dist[1][cur] + Vertex_inf[cur][i].w;
			if (Dist[1][Vertex_inf[cur][i].v] >= alt) {
				Dist[1][Vertex_inf[cur][i].v] = alt;
				pq.push({ Vertex_inf[cur][i].pre, Vertex_inf[cur][i].v, Dist[1][Vertex_inf[cur][i].v], Vertex_inf[cur][i].n });
			}
		}
	}

	for (int i = 1; i < vertex_num ; i++) {
		result[i].push_back(i);
		go_back(i,i);
		if (Dist[1][i] == INF || Dist[1][i] == 0) Dist[1][i] = -1;
		for (int j = result[i].size() - 1; j >= 0; j--) {
			fcout << "V" << result[i][j] << " ";
		}
		fcout << "(" << Dist[1][i] << ")\n";
	}
}

int main() {

	fcin >> vertex_num >> edge_num; // fscanf �������� ������ ����
	
	Vertex_inf.resize(vertex_num); // ���� �Ҵ� �ޱ�
	result.resize(vertex_num); // ��� ���� ���� �Ҵ�
	for (int i = 0; i < edge_num; i++) {

		fcin >> pre_vertex >> vertex >> weight; // fscanf �ΰ��� ������ ����ġ

		Vertex_inf[pre_vertex].push_back({ pre_vertex, vertex, weight, i }); // Vertex_inf��� ������ ����ü �迭�� ����, i : ������ �Է� ����
		Dist[0][i] = { -INF };
		Dist[1][i] = { INF };
	}
	dijkstra();

	Vertex_inf.clear();
	result.clear();

	fcin.close();
	fcout.close();
	return 0;
}