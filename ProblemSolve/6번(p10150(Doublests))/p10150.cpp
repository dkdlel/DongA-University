#include<bits/stdc++.h>
using namespace std;
#define MAX 30000

ifstream fcin("p10150.inp");
ofstream fcout("p10150.out");

typedef struct info {
	string word;
	vector <int> doublet;
};

info dict[MAX]; // 입력 받아야할 배열들, dict : dictionary
bool isvisit[MAX];
vector < vector < int > > parent;
int len; // 입력의 총 크기
queue<int> Queue; // BFS 위한 큐
int start_idx, end_idx;

bool IsDoublet(string word1, string word2) {
	if (word1.size() != word2.size()) return false; // 길이가 다르면 더블릿 아님

	int cnt = 0;
	for (int i = 0; i < word1.size(); i++) // 1개만 다른 단어들 찾기
		if (word1[i] != word2[i]) cnt++;

	if (cnt == 1) return true; // 글자가 하나만 틀리니 더블릿

	return false; // 아니니깐 더블릿 아님
}
void MakeDoublet() { // 더블릿 만들기
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			if (IsDoublet(dict[i].word, dict[j].word)) {
				dict[i].doublet.push_back(j);
			}
		}
	}
}
bool BFS(string start, string end) {
	for (int i = 0; i < len; i++) { // 시작 idx
		if (start == dict[i].word) {
			start_idx = i;
		}
	}
	for (int i = 0; i < len; i++) { // 끝 idx
		if (end == dict[i].word) {
			end_idx = i;
		}
	}
	isvisit[start_idx] = true;
	parent[start_idx].push_back(start_idx);
	Queue.push(start_idx);
	while (!Queue.empty()) {
		int front = Queue.front(); Queue.pop();

		if (front == end_idx) return true; // 끝단어를 만나면 끝

		for (int i = 0; i < dict[front].doublet.size(); i++) {
			int idx = dict[front].doublet[i]; // 자식중 하나를 봄
			if (!isvisit[idx]) { // 방문하지 않았다면
				isvisit[idx] = true;
				parent[idx].push_back(idx); // 현재 위치를 저장하고
				for (int j = 0; j < parent[front].size(); j++) { // 부모들이 가지고 있는 위치들을 저장
					parent[idx].push_back(parent[front][j]);
				}
				Queue.push(idx);
			}
		}
	}

	return false;
}
int main() {

	for (len = 0; ; len++) { // 입력 받기
		string str;
		getline(fcin, str);
		if (str.size() == 0) break;
		if (str.back() != ' ') str.push_back(' ');
		dict[len].word = str;
	}

	MakeDoublet(); // 더블릿 가능한 것들을 저장

	string start, end;
	while (fcin >> start >> end) {
		start.push_back(' '); end.push_back(' ');
		parent.resize(MAX); // init
		for (int i = 0; i < MAX; i++) { isvisit[i] = false; } // init

		if (BFS(start, end)) {
			for (int i = parent[end_idx].size() - 1; i >= 0; i--) // 저장된 경로들을 역순으로 출력
				fcout << dict[parent[end_idx][i]].word << '\n';
		}
		else fcout << "No solution.\n";
		fcout << '\n';

		while (!Queue.empty()) Queue.pop();
		parent.clear();
	}
	return 0;
}
