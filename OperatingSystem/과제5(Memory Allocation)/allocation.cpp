#include <bits/stdc++.h>
using namespace std;
ifstream fcin("allocation.inp");
ofstream fcout("allocation.out");

typedef struct Fit {
	int pid, end;
}Fit;
bool operator < (Fit A, Fit B) {
	return A.end > B.end;
}
typedef struct Best {
	int index, size;
}Best;
struct Compare_Best {
	bool operator() (Best A, Best B) {
		if (A.size == B.size) return A.index > B.index;
		else return A.size > B.size;
	}
};

typedef struct Worst {
	int index, size;
}Worst;
struct Compare_Worst {
	bool operator() (Worst A, Worst B) {
		if (A.size == B.size) return A.index > B.index;
		else return A.size < B.size;
	}
};

class Allocation {
public:
	int num;
	typedef struct Info {
		int start, burst, pid, memory_size;
	}Info;
	typedef struct Memory {
		int start, pid, memory_size, end;
	}Memory;
	vector<Info> first_fit; // 기본 input
	vector<Info> best_fit;
	vector<Info> worst_fit;
	vector<Memory> memory;
	vector<Info> ready_queue;
	priority_queue<Fit> First_Start_End;
	priority_queue<Fit> Best_Start_End;
	priority_queue<Fit> Worst_Start_End;
	int idx; // fit에 해당하는 index
	int time; // 시간 확인
	void Input();
	void First_Fit();
	bool Flag_Check(priority_queue<Fit> &Start_End);
	void IsRelease(priority_queue<Fit> &Start_End, int index);
	bool First_Release();
	bool IsAllocate(Info &fit, priority_queue<Fit> &Start_End, int index);
	void Best_Fit();
	bool Best_Release();
	void Best_push(priority_queue<Best, vector<Best>, Compare_Best> &best_pq);
	void Worst_Fit();
	bool Worst_Release();
	void Worst_push(priority_queue<Worst, vector<Worst>, Compare_Worst> &worst_pq);
};
void Allocation::Input() {

	fcin >> num; // 들어오는 전체 프로세스 수
	first_fit.resize(num);
	best_fit.resize(num);
	worst_fit.resize(num);
	for (int i = 0; i < num; i++) { // 시작, 종료, 메모리 크기 입력
		fcin >> first_fit[i].start >> first_fit[i].burst >> first_fit[i].memory_size;
		first_fit[i].pid = i;
	}
	best_fit = first_fit;
	worst_fit = first_fit;
}
void Allocation::First_Fit() {
	// 초기화
	idx = 0;
	memory.clear();
	memory.push_back({ 0, -1, 1000 , 99999 });
	ready_queue.clear();

	for (time = 0; ; time++) {
		bool flag = false;
		// 끝났을때
		while (!First_Start_End.empty() && First_Start_End.top().end == time)
			flag = Flag_Check(First_Start_End) ? true : false;
		// 레디큐 반환여부 확인
		if (flag)
			if (First_Release()) return;
		// 도착했을때
		while (idx < num && time == first_fit[idx].start) {
			bool check = true;
			for (int i = 0; i < memory.size(); i++) {
				if (memory[i].pid == -1 && first_fit[idx].memory_size <= memory[i].memory_size) {
					check = IsAllocate(first_fit[idx], First_Start_End, i) ? true : false;
					if (check) return; // 마지막인지 아닌지
					break;
				}
			}
			if (check) ready_queue.push_back(first_fit[idx]); // 처음 입력일 때
			idx++; // 다음 first_fit을 받기 위해서
		}
	}
}
// 프로세스 번호가 같을 경우 & 레디큐 확인
bool Allocation::Flag_Check(priority_queue<Fit> &Start_End) {
	int a = memory.size();
	for (int i = 0; i < a; i++) {
		if (memory[i].pid == Start_End.top().pid) {
			IsRelease(Start_End, i);
			return true;
		}
	}
}
// 반환할수 있는지 없는지
void Allocation::IsRelease(priority_queue<Fit> &Start_End, int index) {
	// 반환했다고 표시
	for (int i = 0; i < memory.size(); i++) {
		if (time == memory[i].end) {
			memory[i].pid = -1;
			memory[i].end = 99999;
			Start_End.pop();
		}
	}
	// -1이 연속이면 빈공간을 합치기 위해서
	for (int i = 0; i < memory.size() - 1; i++) {
		if (memory[i].pid == memory[i + 1].pid) {
			memory[i].memory_size += memory[i + 1].memory_size;
			memory.erase(memory.begin() + i + 1);
			i--;
		}
	}
}
//할당할수 있는지 없는지
bool Allocation::IsAllocate(Info &fit, priority_queue<Fit> &Start_End, int index) {
	// 마지막 프로세스면 시작주소 출력
	if (fit.pid == num - 1) {
		fcout << memory[index].start << '\n';
		return true;
	}
	// 메모리 할당 해주기
	memory[index].pid = fit.pid; // -1을 해당 프로세스 번호로
	memory[index].end = time + fit.burst; // 끝나는 시간
	if (memory[index].memory_size > fit.memory_size) {
		Memory temp = { memory[index].start + fit.memory_size, -1, memory[index].memory_size - fit.memory_size, 99999 };
		memory[index].memory_size = fit.memory_size;
		memory.insert(memory.begin() + index + 1, temp);
	}
	Start_End.push({ fit.pid, time + fit.burst });
	return false;
}
// 레디큐에 있는걸 반환활수 있는지 없는지
bool Allocation::First_Release() {
	
	for (int i = 0; i < ready_queue.size(); i++) {
		for (int j = 0; j < memory.size(); j++) {
			if (memory[j].pid == -1 && ready_queue[i].memory_size <= memory[j].memory_size) {
				bool check = IsAllocate(ready_queue[i], First_Start_End, j) ? true : false;
				if (check) return true;
				ready_queue.erase(ready_queue.begin() + i);
				i--;
				break;
			}
		}
	}
	return false;
}
void Allocation::Best_Fit() {
	// 초기화
	idx = 0;
	memory.clear();
	memory.push_back({ 0, -1, 1000 , 99999 });
	ready_queue.clear();

	for (time = 0; ; time++) {
		bool flag = false;
		while (!Best_Start_End.empty() && Best_Start_End.top().end == time)
			flag = Flag_Check(Best_Start_End) ? true : false;

		if (flag)
			if (Best_Release()) return;

		while (idx < num && time == best_fit[idx].start) {
			priority_queue<Best, vector<Best>, Compare_Best> best_pq;
			bool check = true;
			// 우선순위에 먼저 넣고
			Best_push(best_pq);
			// 그 우선순위 큐들이 할당이 가능한지 아닌지 확인
			while (!best_pq.empty()) {
				if (best_fit[idx].memory_size <= best_pq.top().size) {
					check = IsAllocate(best_fit[idx], Best_Start_End, best_pq.top().index) ? true : false;
					if (check) return;
					break;
				}
				best_pq.pop();
			}
			if (check) ready_queue.push_back(best_fit[idx]);
			idx++;
		}
	}
}
bool Allocation::Best_Release() {
	priority_queue<Best, vector<Best>, Compare_Best> best_pq;
	// 우선순위큐에 먼저 넣고
	Best_push(best_pq);

	for (int i = 0; i < ready_queue.size(); i++) {
		priority_queue<Best, vector<Best>, Compare_Best> temp = best_pq;
		// 똑같이 하나 복사해서
		while (!temp.empty()) {
			// 복사한 만큼 도는데
			if (ready_queue[i].memory_size <= temp.top().size) {
				// 할당 가능한지 아닌지를 확인
				bool check = IsAllocate(ready_queue[i], Best_Start_End, temp.top().index) ? true : false;
				if (check) return true; // 마지막인지 아닌지
				ready_queue.erase(ready_queue.begin() + i);
				i--;

				while (!best_pq.empty()) best_pq.pop();
				// 레디큐에 있는걸 확인하면 빈공간이 새로 생기기 때문에 다시 확인후 insert
				Best_push(best_pq);
				break;
			}
			temp.pop();
		}
	}
	return false;
}
// 빈공간인 부분들 우선순위큐에
void Allocation::Best_push(priority_queue<Best, vector<Best>, Compare_Best> &best_pq) {
	for (int i = 0; i < memory.size(); i++) {
		if (memory[i].pid == -1)
			best_pq.push(Best{ i,memory[i].memory_size });
	}
}
void Allocation::Worst_Fit() {
	// 초기화
	idx = 0;
	memory.clear();
	memory.push_back({ 0, -1, 1000 , 99999 });
	ready_queue.clear();
	// Best랑 유사(우선순위의 기준이 다름)
	for (time = 0; ; time++) {
		bool flag = false;
		while (!Worst_Start_End.empty() && Worst_Start_End.top().end == time)
			flag = Flag_Check(Worst_Start_End) ? true : false;

		if (flag)
			if (Worst_Release()) return;

		while (idx < num && time == best_fit[idx].start) {
			priority_queue<Worst, vector<Worst>, Compare_Worst> worst_pq;
			bool check = true;

			Worst_push(worst_pq);

			while (!worst_pq.empty()) {
				if (worst_fit[idx].memory_size <= worst_pq.top().size) {
					check = IsAllocate(worst_fit[idx], Worst_Start_End, worst_pq.top().index) ? true : false;
					if (check) return;
					break;
				}
				worst_pq.pop();
			}
			if (check) ready_queue.push_back(worst_fit[idx]);
			idx++;
		}
	}
}
bool Allocation::Worst_Release() {
	priority_queue<Worst, vector<Worst>, Compare_Worst> worst_pq;

	Worst_push(worst_pq);

	for (int i = 0; i < ready_queue.size(); i++) {
		priority_queue<Worst, vector<Worst>, Compare_Worst> temp = worst_pq;
		while (!temp.empty()) {
			if (ready_queue[i].memory_size <= temp.top().size) {
				bool check = IsAllocate(ready_queue[i], Worst_Start_End, temp.top().index) ? true : false;
				if (check) return true;
				ready_queue.erase(ready_queue.begin() + i);
				i--;

				while (!worst_pq.empty()) worst_pq.pop();

				Worst_push(worst_pq);
				break;
			}
			temp.pop();
		}
	}
	return false;
}
void Allocation::Worst_push(priority_queue<Worst, vector<Worst>, Compare_Worst> &worst_pq) {
	for (int i = 0; i < memory.size(); i++) {
		if (memory[i].pid == -1)
			worst_pq.push(Worst{ i,memory[i].memory_size });
	}
}
int main() {

	Allocation Alloc;
	Alloc.Input();
	Alloc.First_Fit();
	Alloc.Best_Fit();
	Alloc.Worst_Fit();
	return 0;
}