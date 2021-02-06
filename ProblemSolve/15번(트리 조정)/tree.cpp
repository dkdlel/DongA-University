#include<bits/stdc++.h>
#define MAX 100000
using namespace std;

ifstream fcin("tree.inp");
ofstream fcout("tree.out");

typedef struct Vertex_inf {
	int parent; // 부모의 정보
	int weight; // 부모와의 가중치
	int max_weight; // 자식들중 가장 큰 가중치
};

Vertex_inf vertex_inf[MAX] = { 0, };
vector < vector < int > > graph; //구조체 벡터로 그래프 선언

int total_num, vertex_cnt, parent_num, edge_weight; // 입력 받기 위한 변수
int sum_weight, max_sum_weight;
int tmp;

void dfs(int root) {
	for (int i = 0; i < graph[root].size(); i++) {
		// 0에서 해당 정점까지의 거리를 계산하기 위해서 더하기
		sum_weight += vertex_inf[graph[root][i]].weight;
		// 자식 재귀
		dfs(graph[root][i]);

		// 리프 노드이면 그 때 까지의 합을 max가중치에 저장
		if (graph[graph[root][i]].size() == 0) 
			vertex_inf[graph[root][i]].max_weight = sum_weight;
		// 자식의 max 가중치가 더 클 때
		if (vertex_inf[graph[root][i]].max_weight > vertex_inf[root].max_weight) 
			vertex_inf[root].max_weight = vertex_inf[graph[root][i]].max_weight;
		// 0에서 해당 정점까지의 거리를 계산하기 위해서 빼기
		sum_weight -= vertex_inf[graph[root][i]].weight;
	}
}

int main() {

	fcin >> total_num;

	for (int i = 0; i < total_num; i++) {

		int result = 0;

		fcin >> vertex_cnt;
		graph.resize(vertex_cnt);

		// 그래프 생성
		for (int i = 1; i < vertex_cnt; i++) {
			fcin >> parent_num >> edge_weight;
			vertex_inf[i].parent = parent_num;
			vertex_inf[i].weight = edge_weight;
			graph[parent_num].push_back(i);
		}
		// 0번부터 시작이니까
		sum_weight = 0; max_sum_weight = 0;
		dfs(0);

		// 결과값 계산
		for (int i = 1; i < vertex_cnt; i++)
			// 부모의 최대 가중치에서 자식의 최대 가중치의 차를 result에 저장
			result += vertex_inf[vertex_inf[i].parent].max_weight - vertex_inf[i].max_weight;

		fcout << result << "\n";

		memset(vertex_inf, 0, sizeof(vertex_inf));
		graph.clear();
	}

	fcin.close();
	fcout.close();
	return 0;
}