#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#define INF 0x7FFFFFFF // INF 표시할수있는 최대값
using namespace std;

ifstream fcin("dijkstra.inp");
ofstream fcout("dijkstra.out");

struct V_inf {
	int pre, v, w, n; // pre : 이전, v : 현재, w : 가중치, n : 간선의 순서
};

bool operator<(V_inf A, V_inf B) { return (A.w == B.w ? A.n < B.n : A.w > B.w); }

vector< vector < V_inf > > Vertex_inf; // 정점들의 정보 저장
vector< vector < int > > result;
int pre_vertex, vertex, weight;
int vertex_num, edge_num; // 정점수랑 간선수
int Dist[2][1000000]; // 이전 정점, 최단거리 저저장 배열

void go_back(int p, int n) {

	if (Dist[0][p] == -1) { // 0에서 출발이면
		return;
	}
	if (Dist[0][p] == -INF) { // 무한대이면
		result[n].push_back(0);
		return;
	}
	if (result[Dist[0][p]].size() > 0) { // 0과 연결된 정점이 아닐 때
		for (int i = 0; i < result[Dist[0][p]].size(); i++) {
			result[n].push_back(result[Dist[0][p]][i]);
		}
		return;
	}
	// 0과 연결된 정점이면
	result[n].push_back(Dist[0][p]);
	return go_back(Dist[0][p], n);
}

void dijkstra() {

	bool Visited[10000] = { false, };
	priority_queue < V_inf > pq;
	vector <int> Input_Num(vertex_num, -INF);

	Dist[1][0] = { 0 };
	pq.push({ -1,0,0,-1 }); // 이전 정점, 현재 정점 , 가중치 , 입력된 간선의 순서

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

		for (int i = 0; i < Vertex_inf[cur].size(); i++) { // 거리 배열에 최신화
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

	fcin >> vertex_num >> edge_num; // fscanf 정점수와 간선의 갯수
	
	Vertex_inf.resize(vertex_num); // 공간 할당 받기
	result.resize(vertex_num); // 결과 벡터 공간 할당
	for (int i = 0; i < edge_num; i++) {

		fcin >> pre_vertex >> vertex >> weight; // fscanf 두개의 정점과 가중치

		Vertex_inf[pre_vertex].push_back({ pre_vertex, vertex, weight, i }); // Vertex_inf라는 이차원 구조체 배열에 삽입, i : 간선의 입력 순서
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