#include<bits/stdc++.h>
using namespace std;

ifstream fcin("mst.inp");
ofstream fcout("mst.out");

typedef struct info {
	int u, v, weight, idx; // idx : 순서
};
bool operator< (info A, info B) {
	if (A.weight == B.weight) return A.idx > B.idx;
	return A.weight > B.weight;
}
int vertex_num, edge_num; // total_intput
int u, v, w; // u, v : vertex , w : weight

vector< vector < info > > vec; // original graph

priority_queue<info> kruskal_pq;
vector<int> parent; // storage parents vertex

int Find_Kruskal(int n) {
	if (n == parent[n]) return n;
	else return parent[n] = Find_Kruskal(parent[n]);
}
void Kruskal() {
	int result = 0;
	vector<int>edge_order; // 출력할 edge의 순서를 저장
	for (int i = 0; i < vertex_num; i++) parent.push_back(i); // 부모저장 배열 초기화

	while (!kruskal_pq.empty()) {
		int u = kruskal_pq.top().u;
		int v = kruskal_pq.top().v;
		int w = kruskal_pq.top().weight;
		int idx = kruskal_pq.top().idx;
		kruskal_pq.pop();
		
		int x = Find_Kruskal(u); // 부모 찾기
		int y = Find_Kruskal(v); // 부모 찾기

		if (x != y) {
			parent[x] = y;
			edge_order.push_back(idx);
			result += w; // 가중치 합 구하기

			if (edge_order.size() == vertex_num - 1) { // 끝나는 조건
				fcout << "Tree edges by Kruskal algorithm: " << result << "\n";
				for (int i = 0; i < edge_order.size(); i++)
					fcout << edge_order[i] << "\n";
				break; // while 탈출 break;
			}
		}
	}
}
void Prim(int start) {

	int result = 0;
	priority_queue<info> prim_pq;
	vector<int> edge_order;
	vector<bool> visited(vertex_num);
	prim_pq.push({ 0,start,0,0 });

	while (!prim_pq.empty()) {
		int u = prim_pq.top().u;
		int v = prim_pq.top().v;
		int w = prim_pq.top().weight;
		int idx = prim_pq.top().idx;
		prim_pq.pop();

		if (!visited[v]) { // 방문하지 않았다면
			result += w;
			edge_order.push_back(idx);
			visited[v] = true;

			if (edge_order.size() == vertex_num)
			{
				fcout << "Tree edges by Prim algorithm with starting vertex " << start << ": " << result << "\n";
				for (int i = 1; i < edge_order.size(); i++) // 시작정점이 들어가기 때문에 0부터 시작
					fcout << edge_order[i] << "\n";
				return;
			}
		}

		for (int i = 0; i < vec[v].size(); i++) { // 연결되어있는 모든 정점에 대해
			if (!visited[vec[v][i].v]) { // 방문하지 않았던 정점들만
				prim_pq.push(vec[v][i]);
			}
		}
	}
}
int main() {

	fcin >> vertex_num >> edge_num;
	vec.resize(vertex_num);
	for (int i = 0; i < edge_num; i++) {
		fcin >> u >> v >> w;
		vec[v].push_back({ v,u,w,i });
		vec[u].push_back({ u,v,w,i });
		kruskal_pq.push({ v,u,w,i });
	}
	Kruskal();
	Prim(0);
	Prim(vertex_num / 2);
	Prim(vertex_num - 1);
	return 0;
}