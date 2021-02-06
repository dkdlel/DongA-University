#include<bits/stdc++.h>
using namespace std;
#define MAX 30000

ifstream fcin("p10150.inp");
ofstream fcout("p10150.out");

typedef struct info {
	string word;
	vector <int> doublet;
};

info dict[MAX]; // �Է� �޾ƾ��� �迭��, dict : dictionary
bool isvisit[MAX];
vector < vector < int > > parent;
int len; // �Է��� �� ũ��
queue<int> Queue; // BFS ���� ť
int start_idx, end_idx;

bool IsDoublet(string word1, string word2) {
	if (word1.size() != word2.size()) return false; // ���̰� �ٸ��� ���� �ƴ�

	int cnt = 0;
	for (int i = 0; i < word1.size(); i++) // 1���� �ٸ� �ܾ�� ã��
		if (word1[i] != word2[i]) cnt++;

	if (cnt == 1) return true; // ���ڰ� �ϳ��� Ʋ���� ����

	return false; // �ƴϴϱ� ���� �ƴ�
}
void MakeDoublet() { // ���� �����
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			if (IsDoublet(dict[i].word, dict[j].word)) {
				dict[i].doublet.push_back(j);
			}
		}
	}
}
bool BFS(string start, string end) {
	for (int i = 0; i < len; i++) { // ���� idx
		if (start == dict[i].word) {
			start_idx = i;
		}
	}
	for (int i = 0; i < len; i++) { // �� idx
		if (end == dict[i].word) {
			end_idx = i;
		}
	}
	isvisit[start_idx] = true;
	parent[start_idx].push_back(start_idx);
	Queue.push(start_idx);
	while (!Queue.empty()) {
		int front = Queue.front(); Queue.pop();

		if (front == end_idx) return true; // ���ܾ ������ ��

		for (int i = 0; i < dict[front].doublet.size(); i++) {
			int idx = dict[front].doublet[i]; // �ڽ��� �ϳ��� ��
			if (!isvisit[idx]) { // �湮���� �ʾҴٸ�
				isvisit[idx] = true;
				parent[idx].push_back(idx); // ���� ��ġ�� �����ϰ�
				for (int j = 0; j < parent[front].size(); j++) { // �θ���� ������ �ִ� ��ġ���� ����
					parent[idx].push_back(parent[front][j]);
				}
				Queue.push(idx);
			}
		}
	}

	return false;
}
int main() {

	for (len = 0; ; len++) { // �Է� �ޱ�
		string str;
		getline(fcin, str);
		if (str.size() == 0) break;
		if (str.back() != ' ') str.push_back(' ');
		dict[len].word = str;
	}

	MakeDoublet(); // ���� ������ �͵��� ����

	string start, end;
	while (fcin >> start >> end) {
		start.push_back(' '); end.push_back(' ');
		parent.resize(MAX); // init
		for (int i = 0; i < MAX; i++) { isvisit[i] = false; } // init

		if (BFS(start, end)) {
			for (int i = parent[end_idx].size() - 1; i >= 0; i--) // ����� ��ε��� �������� ���
				fcout << dict[parent[end_idx][i]].word << '\n';
		}
		else fcout << "No solution.\n";
		fcout << '\n';

		while (!Queue.empty()) Queue.pop();
		parent.clear();
	}
	return 0;
}
