#include <bits/stdc++.h>
using namespace std;

ifstream fcin("srtf.inp");
ofstream fcout("srtf.out");

typedef struct in {
	int process_num;
	int arrive_time;
	int cpu_burst;
}in;

vector <in> store; // 계산하기 위한 구조체 벡터
priority_queue <in> pq; // 계산하기 위한 우선순위 큐

int total_num; // 전체 경우의수
int result; // 결과값
int max_num; // 빼야하는 수중 큰 수
int store_index = 0; // 저장벡터의 인덱스

bool operator < (in a, in b) {
	return a.cpu_burst > b.cpu_burst;
}

bool compare(in a, in b) { // 우선순위를 정하기 위한 compare
	if (a.arrive_time == b.arrive_time) return a.process_num < b.process_num;
	return a.arrive_time < b.arrive_time;
}

void input() { // 입력
	for (int i = 0; i < total_num; i++)	fcin >> store[i].process_num >> store[i].arrive_time >> store[i].cpu_burst;
	sort(store.begin(), store.end(), compare); // 정렬
}

void sol() { // 숫자를 1씩 감소시키면서 cpu_burst순으로 우선순위큐를 사용

	pq.push(store[store_index++]);
	in store_cal;
	store_cal = pq.top(); // 처음 시작 지점을 지정해주기 위해서

	for (int i = store_cal.arrive_time; store_index != total_num || !pq.empty()  ; i++) { // 우선순위큐가 비어 있거나 경우의수들이 다 들어오지 않았을때 실행

		if (store_index != total_num && i == store[store_index].arrive_time) { // arrive_time과 같을때
			pq.push(store[store_index++]);
			i--; // 다음수에 같은 도착지점들이 있는지 없는지 확인하기 위해서
		}
	
		else if(!pq.empty()){ // arrive_time과 다를때
			store_cal = pq.top();
			pq.pop();
			store_cal.cpu_burst--; // 다음칸으로 이동(1씩 이동)

			if (store_cal.cpu_burst != 0) { // 다음 이동할 수 있으면
				pq.push(store_cal);
				result += pq.size() - 1;
			}
			else result += pq.size(); // 이동 못하면, 이동못하는 process는 pq에 들어가지 않기 때문에 -1을 하지 않음
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