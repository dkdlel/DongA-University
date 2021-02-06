#include <bits/stdc++.h>
using namespace std;

ifstream fcin("srtf.inp");
ofstream fcout("srtf.out");

typedef struct in {
	int process_num;
	int arrive_time;
	int cpu_burst;
}in;

vector <in> store; // ����ϱ� ���� ����ü ����
priority_queue <in> pq; // ����ϱ� ���� �켱���� ť

int total_num; // ��ü ����Ǽ�
int result; // �����
int max_num; // �����ϴ� ���� ū ��
int store_index = 0; // ���庤���� �ε���

bool operator < (in a, in b) {
	return a.cpu_burst > b.cpu_burst;
}

bool compare(in a, in b) { // �켱������ ���ϱ� ���� compare
	if (a.arrive_time == b.arrive_time) return a.process_num < b.process_num;
	return a.arrive_time < b.arrive_time;
}

void input() { // �Է�
	for (int i = 0; i < total_num; i++)	fcin >> store[i].process_num >> store[i].arrive_time >> store[i].cpu_burst;
	sort(store.begin(), store.end(), compare); // ����
}

void sol() { // ���ڸ� 1�� ���ҽ�Ű�鼭 cpu_burst������ �켱����ť�� ���

	pq.push(store[store_index++]);
	in store_cal;
	store_cal = pq.top(); // ó�� ���� ������ �������ֱ� ���ؼ�

	for (int i = store_cal.arrive_time; store_index != total_num || !pq.empty()  ; i++) { // �켱����ť�� ��� �ְų� ����Ǽ����� �� ������ �ʾ����� ����

		if (store_index != total_num && i == store[store_index].arrive_time) { // arrive_time�� ������
			pq.push(store[store_index++]);
			i--; // �������� ���� ������������ �ִ��� ������ Ȯ���ϱ� ���ؼ�
		}
	
		else if(!pq.empty()){ // arrive_time�� �ٸ���
			store_cal = pq.top();
			pq.pop();
			store_cal.cpu_burst--; // ����ĭ���� �̵�(1�� �̵�)

			if (store_cal.cpu_burst != 0) { // ���� �̵��� �� ������
				pq.push(store_cal);
				result += pq.size() - 1;
			}
			else result += pq.size(); // �̵� ���ϸ�, �̵����ϴ� process�� pq�� ���� �ʱ� ������ -1�� ���� ����
		}
	}
}

int main() {

	fcin >> total_num;
	store.resize(total_num);
	input();
	sol();
	fcout << result;
	return 0;
}