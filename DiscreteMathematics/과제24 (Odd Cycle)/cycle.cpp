#include <fstream>
#include <vector>
#include <queue>
#include <string.h>
#define MAX 1000000
using namespace std;

ifstream fcin("cycle.inp");
ofstream fcout("cycle.out");


int total_num, vertex_num, edge_num, vertex, edge;
vector < vector < int > > graph;
int Vertex_Color[MAX];
int color_num, result;

// DFS 방식임
void cycle(int root, int color_num) {

	//정점에 해당하는 색갈 대입
	Vertex_Color[root] = color_num;

	// 인접한 노드를 방문
	for (int i = 0; i < graph[root].size(); i++) {

		int x = graph[root][i];
		// 방문 안 한거면
		if (Vertex_Color[x] == -1)
			cycle(x, (color_num + 1) % 2);
		// 색깔이 같으면 홀수 사이클
		if (Vertex_Color[x] == color_num) {
			result = 1;
			return;
		}
		// 하나라도 홀수 사이클이면 홀수 사이클이니까
		if (result == 1) return;
	}
}
int main() {

	fcin >> total_num;

	for (int T = 0; T < total_num; T++) {

		fcin >> vertex_num >> edge_num;

		result = 0;
		memset(Vertex_Color, -1, sizeof(Vertex_Color));
		graph.resize(vertex_num);

		// 입력 및 그래프 생성
		for (int i = 0; i < edge_num; i++) {
			fcin >> vertex >> edge;
			graph[vertex].push_back(edge);
			graph[edge].push_back(vertex);
		}

		// 계산하자
		cycle(0, 0);

		// 홀수 사이클이면
		if (result == 1) 
			fcout << "O" << endl;
		// 홀수 사이클이 아니면
		else 
			fcout << "X" << endl;
		graph.clear();
	}

	fcin.close();
	fcout.close();
	return 0;
}