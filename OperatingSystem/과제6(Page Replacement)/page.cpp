#include<bits/stdc++.h>
using namespace std;

ifstream fcin("page.inp");
ofstream fcout("page.out");

typedef struct Info {
	int pid, page_num, arrive;
}Info;
bool operator < (Info A, Info B) {
	return A.arrive > B.arrive;
}

class Page {
public:
	int frame_num, result; // result : page_fault_num
	int pid_cnt;
	vector<Info> page;
	vector<Info> FIFO_page;
	vector<Info> LRU_page;
	vector<Info> OPT_page;
	bool Check_page(vector<Info> page, int pid, int page_num);
	void Check_pid(vector<Info> page, int pid);
	void Input();
	void FIFO();
	void LRU();
	void OPT();
};
void Page::Input() { // input
	int n1, n2;
	fcin >> frame_num;
	for (int i = 0; ; i++) {
		fcin >> n1 >> n2;

		if (n1 == -1 && n2 == -1) break;
		page.push_back({ n1,n2,i });
	}
}
bool Page::Check_page(vector<Info> page, int pid, int page_num) { // 같은 프로세스 번호와 페이지번호를 가지는것이 있는지 없는지 확인
	for (int i = 0; i < page.size(); i++) {
		if (page[i].pid == pid && page[i].page_num == page_num) return true;
	}
	return false;
}
void Page::Check_pid(vector<Info> page, int pid) { // 출력 vector에 해당 프로세스 번호가 몇개 있는지
	pid_cnt = 0;
	for (int i = 0; i < page.size(); i++) {
		if (page[i].pid == pid) pid_cnt++;
	}
}
void Page::FIFO() {
	result = 0;
	for (int i = 0; i < page.size(); i++) {
		bool flag = Check_page(FIFO_page, page[i].pid, page[i].page_num) ? true : false; // 같은것이 있는지 없는지
		if (flag) continue; // 같은것이 있으면 다음으로
		Check_pid(FIFO_page, page[i].pid); // 해당 pid가 몇개 있는지
		if (pid_cnt < frame_num) { // pid < n
			FIFO_page.push_back({ page[i].pid, page[i].page_num , i });
		}
		else { // pid >= n
			priority_queue<Info> pq;
			for (int j = 0; j < FIFO_page.size(); j++) {
				if (FIFO_page[j].pid == page[i].pid) { // 해당 프로세스 번호가 같은것들만 우선순위큐에 삽입
					pq.push({ FIFO_page[j].pid, FIFO_page[j].page_num, FIFO_page[j].arrive });
				}
			}
			for (int j = 0; j < FIFO_page.size(); j++) { // 제일 먼저 만난 프로세스의 값들을 변경
				if (FIFO_page[j].arrive == pq.top().arrive) {
					FIFO_page[j].page_num = page[i].page_num;
					FIFO_page[j].arrive = page[i].arrive;
				}
			}
		}
		result++;
	}
	fcout << "FIFO: " << result << "\n";
	for (int i = 0; i < FIFO_page.size(); i++)
		fcout << i << ' ' << FIFO_page[i].pid << ' ' << FIFO_page[i].page_num << "\n";
}
void Page::LRU() {
	result = 0;
	for (int i = 0; i < page.size(); i++) {
		bool flag = Check_page(LRU_page, page[i].pid, page[i].page_num) ? true : false; // 같은것이 있는지 없는지
		if (flag) continue; // 같은것이 있으면 다음으로
		Check_pid(LRU_page, page[i].pid); // 해당 pid가 몇개 있는지
		if (pid_cnt < frame_num) { // pid < n
			LRU_page.push_back({ page[i].pid, page[i].page_num , -1 });
		}
		else { // pid >= n
			bool flag = false;
			vector<Info> tmp;
			for (int j = i - 1; j >= 0; j--) {
				if (page[j].pid == page[i].pid) {
					for (int k = 0; k < tmp.size(); k++) { // 이전의 값들을 봤을때 같은게 있는지 없는지
						if (tmp[k].page_num == page[j].page_num) {
							flag = true;
							break;
						}
						flag = false;
					}
					if (flag) continue; // 있으면 다음꺼 실행
					tmp.push_back({ page[j].pid, page[j].page_num, -1 }); // 없으면 push_back
				}
				if (tmp.size() == frame_num) break; // 3개가 다차면 break
			}
			for (int j = 0; j < LRU_page.size(); j++) { // tmp의 제일 마지막 값들과 결과 vector들의 값들 비교
				if (LRU_page[j].pid == tmp[tmp.size() - 1].pid && LRU_page[j].page_num == tmp[tmp.size() - 1].page_num) {
					LRU_page[j].page_num = page[i].page_num;
				}
			}
		}
		result++;
	}
	fcout << "LRU: " << result << "\n";
	for (int i = 0; i < LRU_page.size(); i++)
		fcout << i << ' ' << LRU_page[i].pid << ' ' << LRU_page[i].page_num << "\n";
}
void Page::OPT() {
	result = 0;
	for (int i = 0; i < page.size(); i++) {
		bool flag = Check_page(OPT_page, page[i].pid, page[i].page_num) ? true : false; // 같은것이 있는지 없는지
		if (flag) continue; // 같은것이 있으면 다음으로
		Check_pid(OPT_page, page[i].pid); // 해당 pid가 몇개 있는지
		if (pid_cnt < frame_num) { // pid < n
			OPT_page.push_back({ page[i].pid, page[i].page_num , i });
		}
		else { // pid >= n
			vector<Info> tmp;
			for (int j = 0; j < OPT_page.size(); j++) { // 현재 프로세스들과 같은것들을 tmp에 저장
				if (OPT_page[j].pid == page[i].pid) {
					tmp.push_back({ OPT_page[j].pid,OPT_page[j].page_num,OPT_page[j].arrive });
				}
			}
			vector<Info> tmp2;
			for (int j = i + 1; j < page.size(); j++) { // 다음 값들을 보고 결과벡터에 있으면 tmp2에 저장
				bool flag = Check_page(tmp, page[j].pid, page[j].page_num); // 다음의 값들이 tmp에 있는지 없는지
				if (!flag) continue;
				flag = Check_page(tmp2, page[j].pid, page[j].page_num); // tmp에 있을때 tmp2에 중복으로 들어가는지 아닌지
				if (flag) continue;
				tmp2.push_back({ page[j].pid,page[j].page_num,page[j].arrive }); // 위에 조건 만족하면
			}
			if (tmp2.size() == frame_num) { // frame번호랑 미래에 존재하는 값의 수가 같으면
				for (int j = 0; j < OPT_page.size(); j++) { // LRU와 동일
					if (OPT_page[j].pid == tmp2[frame_num - 1].pid && OPT_page[j].page_num == tmp2[frame_num - 1].page_num) {
						OPT_page[j].page_num = page[i].page_num;
						OPT_page[j].arrive = page[i].arrive;
					}
				}
			}
			else { // frame번호랑 미래에 존재하는 값의 수가 다르면
				for (int j = 0; j < tmp.size(); j++) { // 중복된거 삭제
					for (int k = 0; k < tmp2.size(); k++) {
						if (tmp[j].page_num == tmp2[k].page_num) {
							tmp.erase(tmp.begin()+j,tmp.begin()+j+1);
							j--;
							break;
						}
					}
				}
				priority_queue<Info> pq;
				for (int j = 0; j < tmp.size(); j++) { // 중복되지 않은 값들을 우선순위큐에 삽입
					pq.push({ tmp[j].pid, tmp[j].page_num, tmp[j].arrive });
				}
				for (int j = 0; j < OPT_page.size(); j++) { // 우선순위가 높은곳(제일 먼저 도착한곳)에 값을 대입
					if (OPT_page[j].pid == pq.top().pid && OPT_page[j].page_num == pq.top().page_num) {
						OPT_page[j].page_num = page[i].page_num;
						OPT_page[j].arrive = page[i].arrive;
					}
				}
			}
		}
		result++;
	}
	fcout << "OPT: " << result << "\n";
	for (int i = 0; i < OPT_page.size(); i++)
		fcout << i << ' ' << OPT_page[i].pid << ' ' << OPT_page[i].page_num << "\n";
}
int main() {

	Page page;
	page.Input();
	page.FIFO();
	page.LRU();
	page.OPT();
	return 0;
}