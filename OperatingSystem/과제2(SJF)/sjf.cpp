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

vector <in> store; // 저장하기 위한 구조체 벡터
priority_queue <in> pq_cal; // 계산하기 위한 우선순위 큐

int total_num; // 전체 경우의수
int result; // 결과값
int max_num; // 빼야하는 수중 큰 수
int store_index = 0; // 저장벡터의 인덱스

bool operator < (in a, in b) { 
	return a.cpu_burst > b.cpu_burst; 
}

bool compare(in a, in b) {
	if (a.arrive_time == b.arrive_time) return a.process_num < b.process_num;
	return a.arrive_time < b.arrive_time;
}

void input() { // 입력
	for (int i = 0; i < total_num; i++)	fcin >> store[i].process_num >> store[i].arrive_time >> store[i].cpu_burst;
	sort(store.begin(), store.end(), compare); // 정렬
}

void sol() {
	pq_cal.push(store[store_index]); // 제일 처음값 우선순위큐에 저장
	store_index++;
	in store_cal; // 우선수위큐에 있는 값들을 저장하기 위한 구조체

	while(!pq_cal.size() == 0) { // 우선순위큐가 빌 때 까지
		store_cal = pq_cal.top(); // 계산용 구조체에 대입
		pq_cal.pop(); // 후 우선순위큐에서 제거
		if (max_num >= store_cal.arrive_time) result += max_num - store_cal.arrive_time; // 큰수가 도착 지점보다 뒤에 있으면, >=는 max_num과 arrive_time이 같은경우를 위해 =를 사용
		else max_num = store_cal.arrive_time; // 큰수가 앞에 있을경우
		max_num += store_cal.cpu_burst;

		while (store_index != total_num && max_num >= store[store_index].arrive_time) { // 가장 큰 수가 도착지점보다 큰경우 우선수위 큐에 대입 && 전체 경우의 수만큼 다들어가지 않았을 경우
			pq_cal.push(store[store_index]);
			store_index++;
		}

		if (pq_cal.size() == 0 && store_index != total_num) { // 우선순위큐는 비어있는데 연산이 남아 있을 때
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