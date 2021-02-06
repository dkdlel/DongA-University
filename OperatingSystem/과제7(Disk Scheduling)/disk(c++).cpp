#include<bits/stdc++.h>
using namespace std;

ifstream fcin("disk.inp");
ofstream fcout("disk.out");

typedef struct Info {
	int arrive, track;
}Info;
struct compare{
	bool operator () (Info A, Info B) {
		return A.track < B.track;
	}
};
class Disk {
public:
	string type;
	int time;
	vector<Info> disk;
	void Input();
	void FCFS();
	void SSTF();
	void LOOK();
};
void Disk::Input() {
	int arrive, track;
	fcin >> type >> time;
	disk.push_back({ 0,0 });
	while (1) {
		fcin >> arrive >> track;
		if (arrive == -1 && track == -1) break;
		disk.push_back(Info{ arrive, track });
	}
	if (type == "FCFS") FCFS();
	else if (type == "SSTF") SSTF();
	else LOOK();
}
void Disk::FCFS() {
	int result = 0;
	for (int i = 0; i < disk.size() -1 ; i++) {
		result = result > disk[i+1].arrive ? result : disk[i+1].arrive; // 그다음 도착이 클경우 그 수로 대체
		result += time + abs(disk[i].track - disk[i + 1].track);
	}
	fcout << result << " " << disk[disk.size()-1].track << "\n";
}
void Disk::SSTF() {
	disk.erase(disk.begin());
	vector<Info> ready;
	int result = 0, pre = 0, idx;
	while (!disk.empty() || !ready.empty()) { // 두개의 벡터가 빌때 까지
		for (int i = 0; i < disk.size(); i++) { // 도착시간이 결과값보다 작은 경우 ready벡터에 삽입
			if (disk[i].arrive <= result) {
				ready.push_back(Info{ disk[i].arrive, disk[i].track });
				disk.erase(disk.begin() + i--);
			}
		}
		if (ready.empty()) { // ready가 비어있으면 바로 다음 arrive를 받음
			result = disk[0].arrive;
			continue;
		}
		int minimum = 999999; // 초기값
		for (int i = 0; i < ready.size(); i++) {
			if (minimum > abs(pre - ready[i].track)) { // 차이가 제일 작은값 받아오기
				minimum = abs(pre - ready[i].track);
				idx = i; // 밑에 erase할때 index가 필요하니까
			}
		}
		result += minimum + time;
		pre = ready[idx].track;
		ready.erase(ready.begin() + idx);
	}
	fcout << result << " " << pre << "\n";
}
void Disk::LOOK() {
	disk.erase(disk.begin());
	vector<Info> ready;
	int result = 0, pre = 0;
	bool flag = true; // 끝까지 갔는지 아닌지 확인
	while (!disk.empty() || !ready.empty()) {
		for (int i = 0; i < disk.size(); i++) {
			if (disk[i].arrive <= result) {
				ready.push_back(Info{ disk[i].arrive, disk[i].track });
				disk.erase(disk.begin() + i--);
			}
		}
		if (ready.empty()) {
			result = disk[0].arrive;
			continue;
		}
		sort(ready.begin(), ready.end(), compare());
		for (int i = 0; i < ready.size(); i++) {
			if (flag) { // 오른쪽으로
				if (pre <= ready[i].track) {
					result += time + abs(pre - ready[i].track);
					pre = ready[i].track;
					ready.erase(ready.begin() + i--);
					break;
				}
				else if (flag && ready.back().track < pre) { // ready벡터의 마지막이 이전의 track보다 작으면
					flag = false;
					i = ready.size() - 2; // 뒤에서 부터 읽기 위해서
					continue;
				}
			}
			else { // 왼쪽으로
				if (pre >= ready[i].track) {
					result += time + abs(pre - ready[i].track);
					pre = ready[i].track;
					ready.erase(ready.begin() + i--);
					break;
				}
				else if (!flag && ready.front().track > pre) {
					flag = true;
					i--; // 앞에서 부터 읽기 위해서
					continue;
				}
			}
		}
	}
	fcout << result << " " << pre << "\n";
}
int main() {

	Disk disk;
	disk.Input();
	return 0;
}