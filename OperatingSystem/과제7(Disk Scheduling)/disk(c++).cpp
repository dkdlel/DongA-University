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
		result = result > disk[i+1].arrive ? result : disk[i+1].arrive; // �״��� ������ Ŭ��� �� ���� ��ü
		result += time + abs(disk[i].track - disk[i + 1].track);
	}
	fcout << result << " " << disk[disk.size()-1].track << "\n";
}
void Disk::SSTF() {
	disk.erase(disk.begin());
	vector<Info> ready;
	int result = 0, pre = 0, idx;
	while (!disk.empty() || !ready.empty()) { // �ΰ��� ���Ͱ� ���� ����
		for (int i = 0; i < disk.size(); i++) { // �����ð��� ��������� ���� ��� ready���Ϳ� ����
			if (disk[i].arrive <= result) {
				ready.push_back(Info{ disk[i].arrive, disk[i].track });
				disk.erase(disk.begin() + i--);
			}
		}
		if (ready.empty()) { // ready�� ��������� �ٷ� ���� arrive�� ����
			result = disk[0].arrive;
			continue;
		}
		int minimum = 999999; // �ʱⰪ
		for (int i = 0; i < ready.size(); i++) {
			if (minimum > abs(pre - ready[i].track)) { // ���̰� ���� ������ �޾ƿ���
				minimum = abs(pre - ready[i].track);
				idx = i; // �ؿ� erase�Ҷ� index�� �ʿ��ϴϱ�
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
	bool flag = true; // ������ ������ �ƴ��� Ȯ��
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
			if (flag) { // ����������
				if (pre <= ready[i].track) {
					result += time + abs(pre - ready[i].track);
					pre = ready[i].track;
					ready.erase(ready.begin() + i--);
					break;
				}
				else if (flag && ready.back().track < pre) { // ready������ �������� ������ track���� ������
					flag = false;
					i = ready.size() - 2; // �ڿ��� ���� �б� ���ؼ�
					continue;
				}
			}
			else { // ��������
				if (pre >= ready[i].track) {
					result += time + abs(pre - ready[i].track);
					pre = ready[i].track;
					ready.erase(ready.begin() + i--);
					break;
				}
				else if (!flag && ready.front().track > pre) {
					flag = true;
					i--; // �տ��� ���� �б� ���ؼ�
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