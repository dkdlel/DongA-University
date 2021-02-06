#include <bits/stdc++.h>
using namespace std;

ifstream fcin("banker.inp");
ofstream fcout("banker.out");

class Banker {
public:
	int p_num, r_num; // ���μ�����ȣ(n), �ڿ��� ��ȣ(m)
	vector<int> p_avail; // Available
	vector<int> q_num; // requset, release�ڿ� ���� ��
	vector<vector<int> > p_max; // MAX
	vector<vector<int> > p_alloc; // Allocation
	queue <pair<int, vector<int> > > ready_queue;
	int num;
	void Input();
	void Query();
	void Request();
	void Release();
	bool IsSafe();
	bool Minus();
	bool Exceed();
};

void Banker::Input() {
	fcin >> p_num >> r_num; // n,m �Է�
	p_avail.resize(r_num);
	q_num.resize(r_num);
	p_max.resize(p_num);
	p_alloc.resize(p_num);

	for (int i = 0; i < r_num; i++) fcin >> p_avail[i]; // avail�� �Ѱ��� �־ alloction ������ ���� ����

	for (int i = 0; i < p_num; i++) { // MAX�� ����
		p_max[i].resize(r_num);
		for (int j = 0; j < r_num; j++) {
			fcin >> p_max[i][j];
		}
	}

	for (int i = 0; i < p_num; i++) { // allocation�� ����
		p_alloc[i].resize(r_num);
		for (int j = 0; j < r_num; j++) {
			fcin >> p_alloc[i][j];
		}
	}

	for (int i = 0; i < r_num; i++) for (int j = 0; j < p_num; j++) p_avail[i] -= p_alloc[j][i]; // avail���� ���ϱ�
	Query();
}

void Banker::Query() {

	string str;

	while (1) {
		fcin >> str;
		if (str == "quit") break;

		fcin >> num; // ���μ��� ��ȣ
		for (int i = 0; i < r_num; i++) fcin >> q_num[i]; // ���ڵ� �ޱ�

		if (str == "request") Request();
		else if (str == "release") Release();

		// ���
		for (int i = 0; i < r_num; i++) fcout << p_avail[i] << ' ';
		fcout << "\n";
	}
}

void Banker::Request() {
	for (int i = 0; i < r_num; i++) {
		p_avail[i] -= q_num[i]; // avil - request_num
		p_alloc[num][i] += q_num[i]; // alloc + request_num
	}
	for (int i = 0; i < r_num; i++) {
		if (Exceed() || IsSafe() || Minus()) { // ����
			for (int j = 0; j < r_num; j++) {
				p_avail[j] += q_num[j]; // ���������� ����
				p_alloc[num][j] -= q_num[j];
			}
			ready_queue.push(pair<int, vector<int> >{num, q_num});
			break;
		}
	}
}

void Banker::Release() {
	for (int i = 0; i < r_num; i++) {
		p_avail[i] += q_num[i]; // avil + request_num
		p_alloc[num][i] -= q_num[i]; // alloc - request_num
	}
	int a = ready_queue.size();
	for (int i = 0; i < a; i++) {
		num = ready_queue.front().first;
		q_num = ready_queue.front().second;
		ready_queue.pop();
		Request();
	}
}

bool Banker::IsSafe() {
	for (int i = 0; i < p_num; i++) {
		int cnt = 0;
		for (int j = 0; j < r_num; j++) if (p_avail[j] + p_alloc[i][j] >= p_max[i][j]) cnt++;
		if (cnt == r_num) return false;
	}
	return true;
}

bool Banker::Minus() {
	for (int i = 0; i < r_num; i++) if (p_avail[i] < 0) return true;
	return false;
}

bool Banker::Exceed() {
	for (int i = 0; i < r_num; i++) if (p_alloc[num][i] > p_max[num][i]) return true;
	return false;
}
int main() {

	Banker banker;
	banker.Input();

	return 0;
}