#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

ifstream inp("graph.inp"); // FILE *inp = fopen("graph.inp");
ofstream out("graph.out"); // FILE *out = fopen("graph.inp");


int total_num, vertex_num, edge_num; // n : vertex_num, m : edge_num
int u, v, w; // u,v : 두 정점 w : 가중치
int visited[10001];
int total_DFS, total_BFS;
int check_num, start_num;

typedef struct W {
	int to;
	int weight_num;
}W;

bool compare(W a, W b) {
	return a.to < b.to;
}


W weight;

vector< vector <W> > matrix;

void DFS(int start_num) {

	//방문한거는 방문하지 말자
	if (visited[start_num]) return;
	// 방문
	visited[start_num] = true;

	//시작부터 vector의 크기만큼 정렬
	sort(matrix[start_num].begin(), matrix[start_num].end(), compare);

	// 인접한 노드를 방문
	for (int i = 0; i < matrix[start_num].size(); i++) {
		int x = matrix[start_num][i].to;
		// 방문 안했으면
		if (!visited[x]) { 
			// 가중치 연산
			total_DFS += matrix[start_num][i].weight_num;
			DFS(x);
		}
	}
}

void BFS(int start_num) {

	queue<int> Queue;

	//방문한거는 방문하지 말자
	if (visited[start_num]) return;

	Queue.push(start_num);
	visited[start_num] = true;

	// 큐에 값이 있을경우 계속 반복 실행
	while (!Queue.empty()) {

		int x = Queue.front();
		//시작부터 vector의 크기만큼 정렬
		Queue.pop();
		for (int i = 0; i< matrix[x].size(); i++) {
			int y = matrix[x][i].to;
			if (!visited[y]) {// 방문하지 않았다면
				// 가중치 연산
				total_BFS += matrix[x][i].weight_num;
				Queue.push(y);
				visited[y] = true;
			}
		}
	}
}

int main() {

	inp >> total_num;

	for (int T = 0; T < total_num; T++) {

		inp >> vertex_num >> edge_num;

		matrix.resize(vertex_num);

		for (int i = 0; i < edge_num; i++) {

			inp >> u >> weight.to >> weight.weight_num; // u,v : 두 정점 w : 가중치
			// weight.to = v , weight.num = w

			//두 정점사이 연결
			matrix[u].push_back(weight);
			// 스왑
			int tmp = u; u = weight.to;	weight.to = tmp;
			matrix[u].push_back(weight);
		}

		inp >> check_num;
		for (int i = 0; i < check_num; i++) {

			inp >> start_num;

			//DFS 전 초기화
			total_DFS = 0;
			for (int j = 0; j < vertex_num; j++) visited[j] = false;

			//DFS 실행
			DFS(start_num);

			//BFS 전 초기화
			total_BFS = 0;
			for (int j = 0; j < vertex_num; j++) visited[j] = false;

			//BFS 실행
			BFS(start_num);

			out << "n=" << vertex_num << " m=" << edge_num << " start=" << start_num << " DFS:" << total_DFS << " BFS:" << total_BFS << endl;
		}

		matrix.clear();
	}

	inp.close();
	out.close();
	return 0;
}