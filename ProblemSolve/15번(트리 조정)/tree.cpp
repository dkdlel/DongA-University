#include<bits/stdc++.h>
#define MAX 100000
using namespace std;

ifstream fcin("tree.inp");
ofstream fcout("tree.out");

typedef struct Vertex_inf {
	int parent; // �θ��� ����
	int weight; // �θ���� ����ġ
	int max_weight; // �ڽĵ��� ���� ū ����ġ
};

Vertex_inf vertex_inf[MAX] = { 0, };
vector < vector < int > > graph; //����ü ���ͷ� �׷��� ����

int total_num, vertex_cnt, parent_num, edge_weight; // �Է� �ޱ� ���� ����
int sum_weight, max_sum_weight;
int tmp;

void dfs(int root) {
	for (int i = 0; i < graph[root].size(); i++) {
		// 0���� �ش� ���������� �Ÿ��� ����ϱ� ���ؼ� ���ϱ�
		sum_weight += vertex_inf[graph[root][i]].weight;
		// �ڽ� ���
		dfs(graph[root][i]);

		// ���� ����̸� �� �� ������ ���� max����ġ�� ����
		if (graph[graph[root][i]].size() == 0) 
			vertex_inf[graph[root][i]].max_weight = sum_weight;
		// �ڽ��� max ����ġ�� �� Ŭ ��
		if (vertex_inf[graph[root][i]].max_weight > vertex_inf[root].max_weight) 
			vertex_inf[root].max_weight = vertex_inf[graph[root][i]].max_weight;
		// 0���� �ش� ���������� �Ÿ��� ����ϱ� ���ؼ� ����
		sum_weight -= vertex_inf[graph[root][i]].weight;
	}
}

int main() {

	fcin >> total_num;

	for (int i = 0; i < total_num; i++) {

		int result = 0;

		fcin >> vertex_cnt;
		graph.resize(vertex_cnt);

		// �׷��� ����
		for (int i = 1; i < vertex_cnt; i++) {
			fcin >> parent_num >> edge_weight;
			vertex_inf[i].parent = parent_num;
			vertex_inf[i].weight = edge_weight;
			graph[parent_num].push_back(i);
		}
		// 0������ �����̴ϱ�
		sum_weight = 0; max_sum_weight = 0;
		dfs(0);

		// ����� ���
		for (int i = 1; i < vertex_cnt; i++)
			// �θ��� �ִ� ����ġ���� �ڽ��� �ִ� ����ġ�� ���� result�� ����
			result += vertex_inf[vertex_inf[i].parent].max_weight - vertex_inf[i].max_weight;

		fcout << result << "\n";

		memset(vertex_inf, 0, sizeof(vertex_inf));
		graph.clear();
	}

	fcin.close();
	fcout.close();
	return 0;
}