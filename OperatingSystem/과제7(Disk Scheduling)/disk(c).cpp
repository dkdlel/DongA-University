#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <algorithm>
#include <stdlib.h>
using namespace std;
#pragma warning(disable: 4996)

FILE *inp = fopen("disk.inp", "rt");
FILE *out = fopen("disk.out", "wt");

struct info {
	int request_time, track_num;
};
char type[4]; // 처음 영문 4개
int cost; // 그뒤 숫자 
info arr[10000]; // 입력받은 배열
int arr_index = 0; // 입력받은 배열의 크기
void FCFS() {
	int result = 0; // 최종 결과
	int pre = 0; // 이전의 track_num을 저장
	for (int i = 0; i < arr_index; i++) {
		if (result > arr[i].request_time) { // 결과값이 더 클경우
			result = result; // 그냥 result를 그대로 사용
			result += +cost + abs(pre - arr[i].track_num);
		}
		else {
			result = arr[i].request_time; // 아닐경우 다음 request_time을 사용
			result += cost + abs(pre - arr[i].track_num);
		}
		pre = arr[i].track_num; // 이전의 트랙번호를 저장
	}
	fprintf(out, "%d %d\n", result, arr[arr_index - 1].track_num);
}
void SSTF() {
	info ready[10000];
	int ready_index = 0;
	int result = 0, pre = 0, idx;
	int cnt;
	while (ready_index != 0 || arr_index != 0) {
		cnt = 0;
		for (int i = 0; i < arr_index; i++) {
			if (arr[i].request_time <= result) { // result가 클경우
				ready[ready_index].request_time = arr[i].request_time; // ready배열에 넣고
				ready[ready_index].track_num = arr[i].track_num;
				for (int j = i; j < arr_index; j++) { // 밑에 있는걸 위로 올리기
					arr[j].request_time = arr[j + 1].request_time;
					arr[j].track_num = arr[j + 1].track_num;
				}
				arr_index--; i--; ready_index++; cnt++;
			}
		}
		if (ready_index == 0 && cnt == 0) { // ready가 비어있고 더이상 들어가 있는게 없을 경우
			result = arr[0].request_time;
			continue;
		}
		int MIN = 2147483647; // 최소값을 찾기 위해 int 최대 법위 입력
		for (int i = 0; i < ready_index; i++) { // 최소값 찾기
			if (MIN > abs(pre - ready[i].track_num)) {
				MIN = abs(pre - ready[i].track_num);
				idx = i;
			}
		}
		result += MIN + cost; // 결과 계산
		pre = ready[idx].track_num; // 이전의 track번호 입력
		bool flag = false;
		for (int i = idx; i < ready_index; i++) { // 사용한 수를 ready에서 삭제
			ready[i].request_time = ready[i + 1].request_time;
			ready[i].track_num = ready[i + 1].track_num;
			flag = true;
		}
		if (flag) ready_index--;
	}
	fprintf(out, "%d %d\n", result, pre);
}
void LOOK() {
	int ready[10000];
	int ready_index = 0;
	int result = 0, pre = 0, idx;
	int cnt;
	bool flag = true;
	while (ready_index != 0 || arr_index != 0) {
		cnt = 0;
		for (int i = 0; i < arr_index; i++) {
			if (arr[i].request_time <= result) {
				ready[ready_index] = arr[i].track_num;
				for (int j = i; j < arr_index; j++) {
					arr[j].request_time = arr[j + 1].request_time;
					arr[j].track_num = arr[j + 1].track_num;
				}
				arr_index--; i--; ready_index++; cnt++;
			}
		}
		if (ready_index == 0 && cnt == 0) {
			result = arr[0].request_time;
			continue;
		}
		int tmp; // 오름차순 정렬
		for (int i = 0; i < ready_index - 1; i++) {
			for (int j = 0; j < ready_index - 1 - i; j++) {
				if (ready[j] > ready[j + 1]) {
					tmp = ready[j];
					ready[j] = ready[j + 1];
					ready[j + 1] = tmp;
				}
			}
		}
		for (int i = 0; i < ready_index; i++) {
			if (flag) { // 오른쪽으로 갈수 있으면
				if (pre <= ready[i]) { // 값이 더 클경우 오른쪽으로 
					result += cost + abs(pre - ready[i]);
					pre = ready[i];
					for (int j = i; j < ready_index; j++) { // 사용한 ready 삭제
						ready[j] = ready[j + 1];
					}
					ready_index--;
					break;
				}
				else if (flag && ready[ready_index - 1] < pre) {
					flag = false;
					i = ready_index - 2;
					continue;
				}
			}
			else { // 왼쪽으로 갈수 있으면
				if (pre >= ready[i]) { // 값이 더 클경우 오른쪽으로 
					result += cost + abs(pre - ready[i]);
					pre = ready[i];
					for (int j = i; j < ready_index; j++) { // 사용한 ready 삭제
						ready[j] = ready[j + 1];
					}
					ready_index--;
					break;
				}
				else if (!flag && ready[0] > pre) {
					flag = true;
					i--;
					continue;
				}
			}
		}
	}
	fprintf(out, "%d %d\n", result, pre);
}
int main() {

	int request_time, track_num; // 요청시간과 그때의 트랙 번호
	for (int i = 0; i < 4; i++) {
		fscanf(inp, "%c", &type[i]);
	}
	fscanf(inp, "%d", &cost);
	for (int i = 0; ; i++) {
		fscanf(inp, "%d %d", &request_time, &track_num);
		if (request_time == -1 && track_num == -1) break;
		arr[i].request_time = request_time;
		arr[i].track_num = track_num;
		arr_index++;
	}
	if (type[0] == 'F') FCFS();
	else if (type[0] == 'S') SSTF();
	else LOOK();
	fclose(inp);
	fclose(out);
	return 0;
}