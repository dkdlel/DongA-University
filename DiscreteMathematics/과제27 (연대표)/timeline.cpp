// ������
#include <fstream>
#include <algorithm>
#include <vector>
#define MAX 100000
using namespace std;

ifstream fcin("timeline.inp");
ofstream fcout("timeline.out");

struct Start_sorted{
	int S_Y, S_M, S_D, S_total;
};

struct End_sorted {
	int E_Y, E_M, E_D, E_total;
};

vector <Start_sorted> start_sorted;
vector <End_sorted> end_sorted;
int total_num, input_num;

bool S_compare(Start_sorted &a, Start_sorted &b) {
	return a.S_total < b.S_total;
}
bool E_compare(End_sorted &a, End_sorted &b) {
	return a.E_total < b.E_total;
}
int S_day_cal(int i) // ���� �⵵ �� �ϼ� ���
{
   	return start_sorted[i].S_total = start_sorted[i].S_Y * 372 + start_sorted[i].S_M * 31 + start_sorted[i].S_D;
}
int E_day_cal(int i) // �� �⵵ �� �ϼ� ���
{
	return end_sorted[i].E_total = end_sorted[i].E_Y * 372 + end_sorted[i].E_M * 31 + end_sorted[i].E_D;
}

int timeline() {

	int i = 0, j = 0;
	while(1) {
		// ���⵵�� �ִ� ���� ���۳⵵���� ���� ��
		if (end_sorted[j].E_total <= start_sorted[i].S_total) {
			end_sorted[j].E_total = start_sorted[i].S_total;
			i++; j++;
		}
		// �ƴϸ� ���۳⵵ �ڷ� ����
		else
			i++;
		// ���� �⵵�� ������ ����
		if (i == start_sorted.size() || j == end_sorted.size()+1) break;
		
	}
	return i - j;
}

int main() {

	char dot;

	fcin >> total_num;
	while (total_num--) {

		fcin >> input_num;
		start_sorted.resize(input_num);
		end_sorted.resize(input_num);

		for (int i = 0; i < input_num; i++) {
			fcin >> start_sorted[i].S_Y >> dot >> start_sorted[i].S_M >> dot >> start_sorted[i].S_D;
			fcin >> end_sorted[i].E_Y >> dot >> end_sorted[i].E_M >> dot >> end_sorted[i].E_D;
			start_sorted[i].S_total = S_day_cal(i);
			end_sorted[i].E_total = E_day_cal(i);
		}
		sort(start_sorted.begin(), start_sorted.end(), S_compare);
		sort(end_sorted.begin(), end_sorted.end(), E_compare);

		fcout << timeline() << '\n';
	}

	fcin.close();
	fcout.close();
	return 0;
}







// ö��'s
//#include <fstream>
//#include <string>
//#include <algorithm>
//#include <vector>
//#define MAX 200000
//using namespace std;
//
//ifstream fcin("timeline.inp");
//ofstream fcout("timeline.out");
//
//struct Time {
//	int year,month,day, total_day, check;
//};
//
//vector <Time> total_sorted;
//vector <int> result;
//int total_num, input_num, maximum, output;
//char dot;
//
//bool compare(Time &a, Time &b) {
//	if (a.total_day == b.total_day) // ���� ���� �ϼ��̸� ������ �⵵�� ���� ����
//		return a.check > b.check;
//	return a.total_day < b.total_day; // �� �ϼ��� ū�� ��ȯ
//}
//int day_cal(int i) // �� �ϼ� ���
//{
//	return total_sorted[i].total_day = total_sorted[i].year * 372 + total_sorted[i].month * 31 + total_sorted[i].day;
//}
//
//void timeline() {
//
//	for (int i = 0; i < total_sorted.size() ; i++) {
//		 ���� �⵵ �̸�
//		if (total_sorted[i].check == 0)
//			maximum++;
//		 ���⵵ �̸�
//		else if (total_sorted[i].check == 1)
//			maximum--;
//		if (output < maximum) output = maximum;
//	}
//}
//
//int main() {
//
//	fcin >> total_num;
//	while (total_num--) {
//
//		maximum = 0; output = 0;
//		fcin >> input_num;
//		total_sorted.resize(input_num*2);
//		result.resize(input_num*2);
//
//		for (int i = 0; i < input_num*2; i++) {
//			fcin >> total_sorted[i].year >> dot >> total_sorted[i].month >> dot >> total_sorted[i].day;
//			if (i % 2 == 0)
//				total_sorted[i].check = 0; // 0�̸� ���۳⵵
//			else
//				total_sorted[i].check = 1; // 1�̸� �� �⵵
//			day_cal(i);
//		}
//
//		sort(total_sorted.begin(), total_sorted.begin() + (input_num*2), compare);
//
//		timeline();
//
//		fcout << output << endl;
//
//		total_sorted.clear();
//		result.clear();
//	}
//
//	fcin.close();
//	fcout.close();
//	return 0;
//}