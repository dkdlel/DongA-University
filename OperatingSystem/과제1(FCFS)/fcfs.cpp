#include <fstream>
#include <queue>
#include <algorithm>
using namespace std;

ifstream fcin("fcfs.inp");
ofstream fcout("fcfs.out");

typedef struct in {
	int process_num;
	int arrive_time;
	int cpu_burst;
}in;

priority_queue <in> cal; // ����ϱ� ���� ����ü ����
int total_num; // ��ü ����Ǽ�
int result; // �����
int max_num; // �����ϴ� ���� ū ��

bool operator < (in a, in b) { // �켱������ ���ϱ� ���� compare
	if (a.arrive_time == b.arrive_time) return a.process_num < b.process_num;
	return a.arrive_time < b.arrive_time;
}

int main() {

	fcin >> total_num;
	in tmp;
	for (int i = 0; i < total_num; i++) {
		fcin >> tmp.process_num >> tmp.arrive_time >> tmp.cpu_burst;
		cal.push(tmp);
	}
	tmp = cal.top();
	cal.pop();
	max_num = tmp.cpu_burst;

	while (!cal.empty()) {
		tmp = cal.top();
		cal.pop();
		if(max_num > tmp.arrive_time) result += max_num - tmp.cpu_burst;
	}

	fcout << result;
	return 0;
}


//#include <fstream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//ifstream fcin("fcfs.inp");
//ofstream fcout("fcfs.out");
//
//typedef struct in {
//	int process_num;
//	int arrive_time;
//	int cpu_burst;
//}in;
//
//vector <in> cal; // ����ϱ� ���� ����ü ����
//int total_num; // ��ü ����Ǽ�
//int result; // �����
//int max_num; // �����ϴ� ���� ū ��
//
//bool compare(in &a, in &b) { // �켱������ ���ϱ� ���� compare
//	if (a.arrive_time == b.arrive_time) return a.process_num < b.process_num;
//	return a.arrive_time < b.arrive_time;
//}
//
//void input() { // �Է�
//	for (int i = 0; i < total_num; i++)	fcin >> cal[i].process_num >> cal[i].arrive_time >> cal[i].cpu_burst;
//	sort(cal.begin(), cal.end(), compare); // ����
//}
//
//void sol() {
//	max_num += cal[0].cpu_burst;
//	for (int i = 1; i < cal.size(); i++) {
//		if (max_num > cal[i].arrive_time) result += max_num - cal[i].arrive_time; // ū���� ���� �������� �ڿ� ������
//		else max_num = cal[i].arrive_time; // ū���� �տ� �������
//		max_num += cal[i].cpu_burst;
//	}
//}
//
//int main() {
//
//	fcin >> total_num;
//	cal.resize(total_num);
//	input();
//	sol();
//	fcout << result;
//	return 0;
//}