#include <fstream>
#include <string.h>
#define MAX 1001
using namespace std;

ifstream fcin("entrance.inp");
ofstream fcout("entrance.out");

int total_num, check_num, input_num; 
// total_num : 전체 경우의수 check_num : 몇개의 수가 들어가느냐 input_num : 들어가는 수
int arr[MAX];

void entrance() {
	int index = 0, cnt = 0;
	memset(arr, 0, sizeof(arr));
	fcin >> check_num;
	for (int j = 0; j < check_num; j++) {
		fcin >> input_num;
		for (int i = 0; i < check_num; i++) {
			// 기존 배열의 값보다 들어오는 수가 크면
			if (arr[i] < input_num) {
				arr[i] = input_num;
				break;
			}
			// 기존 배열의 값이 크면
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