#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

ifstream fcin("sjf.inp");
ofstream fcout("sjf.out");

typedef struct in {
	int process_num;
	int arrive_time;
	int cpu_burst;
}in;

vector <in> store; // �����ϱ� ���� ����ü ����
priority_queue <in> pq_cal; // ����ϱ� ���� �켱���� ť

int total_num; // ��ü ����Ǽ�
int result; // �����
int max_num; // �����ϴ� ���� ū ��
int store_index = 0; // ���庤���� �ε���

bool operator < (in a, in b) { 
	return a.cpu_burst > b.cpu_burst; 
}

bool compare(in a, in b) {
	if (a.arrive_time == b.arrive_time) return a.process_num < b.process_num;
	return a.arrive_time < b.arrive_time;
}

void input() { // �Է�
	for (int i = 0; i < total_num; i++)	fcin >> store[i].process_num >> store[i].arrive_time >> store[i].cpu_burst;
	sort(store.begin(), store.end(), compare); // ����
}

void sol() {
	pq_cal.push(store[store_index]); // ���� ó���� �켱����ť�� ����
	store_index++;
	in store_cal; // �켱����ť�� �ִ� ������ �����ϱ� ���� ����ü

	while(!pq_cal.size() == 0) { // �켱����ť�� �� �� ����
		store_cal = pq_cal.top(); // ���� ����ü�� ����
		pq_cal.pop(); // �� �켱����ť���� ����
		if (max_num >= store_cal.arrive_time) result += max_num - store_cal.arrive_time; // ū���� ���� �������� �ڿ� ������, >=�� max_num�� arrive_time�� ������츦 ���� =�� ���
		else max_num = store_cal.arrive_time; // ū���� �տ� �������
		max_num += store_cal.cpu_burst;

		while (store_index != total_num && max_num >= store[store_index].arrive_time) { // ���� ū ���� ������������ ū��� �켱���� ť�� ���� && ��ü ����� ����ŭ �ٵ��� �ʾ��� ���
			pq_cal.push(store[store_index]);
			store_index++;
		}

		if (pq_cal.size() == 0 && store_index != total_num) { // �켱����ť�� ����ִµ� ������ ���� ���� ��
			pq_cal.push(store[store_index]);
			store_index++;
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