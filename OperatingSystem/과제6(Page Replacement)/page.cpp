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
bool Page::Check_page(vector<Info> page, int pid, int page_num) { // ���� ���μ��� ��ȣ�� ��������ȣ�� �����°��� �ִ��� ������ Ȯ��
	for (int i = 0; i < page.size(); i++) {
		if (page[i].pid == pid && page[i].page_num == page_num) return true;
	}
	return false;
}
void Page::Check_pid(vector<Info> page, int pid) { // ��� vector�� �ش� ���μ��� ��ȣ�� � �ִ���
	pid_cnt = 0;
	for (int i = 0; i < page.size(); i++) {
		if (page[i].pid == pid) pid_cnt++;
	}
}
void Page::FIFO() {
	result = 0;
	for (int i = 0; i < page.size(); i++) {
		bool flag = Check_page(FIFO_page, page[i].pid, page[i].page_num) ? true : false; // �������� �ִ��� ������
		if (flag) continue; // �������� ������ ��������
		Check_pid(FIFO_page, page[i].pid); // �ش� pid�� � �ִ���
		if (pid_cnt < frame_num) { // pid < n
			FIFO_page.push_back({ page[i].pid, page[i].page_num , i });
		}
		else { // pid >= n
			priority_queue<Info> pq;
			for (int j = 0; j < FIFO_page.size(); j++) {
				if (FIFO_page[j].pid == page[i].pid) { // �ش� ���μ��� ��ȣ�� �����͵鸸 �켱����ť�� ����
					pq.push({ FIFO_page[j].pid, FIFO_page[j].page_num, FIFO_page[j].arrive });
				}
			}
			for (int j = 0; j < FIFO_page.size(); j++) { // ���� ���� ���� ���μ����� ������ ����
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
		bool flag = Check_page(LRU_page, page[i].pid, page[i].page_num) ? true : false; // �������� �ִ��� ������
		if (flag) continue; // �������� ������ ��������
		Check_pid(LRU_page, page[i].pid); // �ش� pid�� � �ִ���
		if (pid_cnt < frame_num) { // pid < n
			LRU_page.push_back({ page[i].pid, page[i].page_num , -1 });
		}
		else { // pid >= n
			bool flag = false;
			vector<Info> tmp;
			for (int j = i - 1; j >= 0; j--) {
				if (page[j].pid == page[i].pid) {
					for (int k = 0; k < tmp.size(); k++) { // ������ ������ ������ ������ �ִ��� ������
						if (tmp[k].page_num == page[j].page_num) {
							flag = true;
							break;
						}
						flag = false;
					}
					if (flag) continue; // ������ ������ ����
					tmp.push_back({ page[j].pid, page[j].page_num, -1 }); // ������ push_back
				}
				if (tmp.size() == frame_num) break; // 3���� ������ break
			}
			for (int j = 0; j < LRU_page.size(); j++) { // tmp�� ���� ������ ����� ��� vector���� ���� ��
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
		bool flag = Check_page(OPT_page, page[i].pid, page[i].page_num) ? true : false; // �������� �ִ��� ������
		if (flag) continue; // �������� ������ ��������
		Check_pid(OPT_page, page[i].pid); // �ش� pid�� � �ִ���
		if (pid_cnt < frame_num) { // pid < n
			OPT_page.push_back({ page[i].pid, page[i].page_num , i });
		}
		else { // pid >= n
			vector<Info> tmp;
			for (int j = 0; j < OPT_page.size(); j++) { // ���� ���μ������ �����͵��� tmp�� ����
				if (OPT_page[j].pid == page[i].pid) {
					tmp.push_back({ OPT_page[j].pid,OPT_page[j].page_num,OPT_page[j].arrive });
				}
			}
			vector<Info> tmp2;
			for (int j = i + 1; j < page.size(); j++) { // ���� ������ ���� ������Ϳ� ������ tmp2�� ����
				bool flag = Check_page(tmp, page[j].pid, page[j].page_num); // ������ ������ tmp�� �ִ��� ������
				if (!flag) continue;
				flag = Check_page(tmp2, page[j].pid, page[j].page_num); // tmp�� ������ tmp2�� �ߺ����� ������ �ƴ���
				if (flag) continue;
				tmp2.push_back({ page[j].pid,page[j].page_num,page[j].arrive }); // ���� ���� �����ϸ�
			}
			if (tmp2.size() == frame_num) { // frame��ȣ�� �̷��� �����ϴ� ���� ���� ������
				for (int j = 0; j < OPT_page.size(); j++) { // LRU�� ����
					if (OPT_page[j].pid == tmp2[frame_num - 1].pid && OPT_page[j].page_num == tmp2[frame_num - 1].page_num) {
						OPT_page[j].page_num = page[i].page_num;
						OPT_page[j].arrive = page[i].arrive;
					}
				}
			}
			else { // frame��ȣ�� �̷��� �����ϴ� ���� ���� �ٸ���
				for (int j = 0; j < tmp.size(); j++) { // �ߺ��Ȱ� ����
					for (int k = 0; k < tmp2.size(); k++) {
						if (tmp[j].page_num == tmp2[k].page_num) {
							tmp.erase(tmp.begin()+j,tmp.begin()+j+1);
							j--;
							break;
						}
					}
				}
				priority_queue<Info> pq;
				for (int j = 0; j < tmp.size(); j++) { // �ߺ����� ���� ������ �켱����ť�� ����
					pq.push({ tmp[j].pid, tmp[j].page_num, tmp[j].arrive });
				}
				for (int j = 0; j < OPT_page.size(); j++) { // �켱������ ������(���� ���� �����Ѱ�)�� ���� ����
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