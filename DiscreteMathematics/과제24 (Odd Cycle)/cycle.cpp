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

// DFS �����
void cycle(int root, int color_num) {

	//������ �ش��ϴ� ���� ����
	Vertex_Color[root] = color_num;

	// ������ ��带 �湮
	for (int i = 0; i < graph[root].size(); i++) {

		int x = graph[root][i];
		// �湮 �� �ѰŸ�
		if (Vertex_Color[x] == -1)
			cycle(x, (color_num + 1) % 2);
		// ������ ������ Ȧ�� ����Ŭ
		if (Vertex_Color[x] == color_num) {
			result = 1;
			return;
		}
		// �ϳ��� Ȧ�� ����Ŭ�̸� Ȧ�� ����Ŭ�̴ϱ�
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

		// �Է� �� �׷��� ����
		for (int i = 0; i < edge_num; i++) {
			fcin >> vertex >> edge;
			graph[vertex].push_back(edge);
			graph[edge].push_back(vertex);
		}

		// �������
		cycle(0, 0);

		// Ȧ�� ����Ŭ�̸�
		if (result == 1) 
			fcout << "O" << endl;
		// Ȧ�� ����Ŭ�� �ƴϸ�
		else 
			fcout << "X" << endl;
		graph.clear();
	}

	fcin.close();
	fcout.close();
	return 0;
}