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

priority_queue <in> cal; // 계산하기 위한 구조체 벡터
int total_num; // 전체 경우의수
int result; // 결과값
int max_num; // 빼야하는 수중 큰 수

bool operator < (in a, in b) { // 우선순위를 정하기 위한 compare
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
//vector <in> cal; // 계산하기 위한 구조체 벡터
//int total_num; // 전체 경우의수
//int result; // 결과값
//int max_num; // 빼야하는 수중 큰 수
//
//bool compare(in &a, in &b) { // 우선순위를 정하기 위한 compare
//	if (a.arrive_time == b.arrive_time) return a.process_num < b.process_num;
//	return a.arrive_time < b.arrive_time;
//}
//
//void input() { // 입력
//	for (int i = 0; i < total_num; i++)	fcin >> cal[i].process_num >> cal[i].arrive_time >> cal[i].cpu_burst;
//	sort(cal.begin(), cal.end(), compare); // 정렬
//}
//
//void sol() {
//	max_num += cal[0].cpu_burst;
//	for (int i = 1; i < cal.size(); i++) {
//		if (max_num > cal[i].arrive_time) result += max_num - cal[i].arrive_time; // 큰수가 도착 지점보다 뒤에 있으면
//		else max_num = cal[i].arrive_time; // 큰수가 앞에 있을경우
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