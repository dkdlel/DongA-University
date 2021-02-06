#include <fstream>
#include <string.h>
#define MAX 1001
using namespace std;

ifstream fcin("entrance.inp");
ofstream fcout("entrance.out");

int total_num, check_num, input_num; 
// total_num : ��ü ����Ǽ� check_num : ��� ���� ������ input_num : ���� ��
int arr[MAX];

void entrance() {
	int index = 0, cnt = 0;
	memset(arr, 0, sizeof(arr));
	fcin >> check_num;
	for (int j = 0; j < check_num; j++) {
		fcin >> input_num;
		for (int i = 0; i < check_num; i++) {
			// ���� �迭�� ������ ������ ���� ũ��
			if (arr[i] < input_num) {
				arr[i] = input_num;
				break;
			}
			// ���� �迭�� ���� ũ��
			else if (arr[i] > input_num && arr[i+1] == 0) {
				cnt++;
				arr[i+1] = input_num;
				break;
			}
			else continue;
		}
	}
	fcout << cnt+1 << endl;
}

int main() {

	fcin >> total_num;
	while (total_num--)
		entrance();

	fcin.close();
	fcout.close();
	return 0;
}