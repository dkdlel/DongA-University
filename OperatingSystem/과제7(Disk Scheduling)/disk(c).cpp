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
char type[4]; // ó�� ���� 4��
int cost; // �׵� ���� 
info arr[10000]; // �Է¹��� �迭
int arr_index = 0; // �Է¹��� �迭�� ũ��
void FCFS() {
	int result = 0; // ���� ���
	int pre = 0; // ������ track_num�� ����
	for (int i = 0; i < arr_index; i++) {
		if (result > arr[i].request_time) { // ������� �� Ŭ���
			result = result; // �׳� result�� �״�� ���
			result += +cost + abs(pre - arr[i].track_num);
		}
		else {
			result = arr[i].request_time; // �ƴҰ�� ���� request_time�� ���
			result += cost + abs(pre - arr[i].track_num);
		}
		pre = arr[i].track_num; // ������ Ʈ����ȣ�� ����
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
			if (arr[i].request_time <= result) { // result�� Ŭ���
				ready[ready_index].request_time = arr[i].request_time; // ready�迭�� �ְ�
				ready[ready_index].track_num = arr[i].track_num;
				for (int j = i; j < arr_index; j++) { // �ؿ� �ִ°� ���� �ø���
					arr[j].request_time = arr[j + 1].request_time;
					arr[j].track_num = arr[j + 1].track_num;
				}
				arr_index--; i--; ready_index++; cnt++;
			}
		}
		if (ready_index == 0 && cnt == 0) { // ready�� ����ְ� ���̻� �� �ִ°� ���� ���
			result = arr[0].request_time;
			continue;
		}
		int MIN = 2147483647; // �ּҰ��� ã�� ���� int �ִ� ���� �Է�
		for (int i = 0; i < ready_index; i++) { // �ּҰ� ã��
			if (MIN > abs(pre - ready[i].track_num)) {
				MIN = abs(pre - ready[i].track_num);
				idx = i;
			}
		}
		result += MIN + cost; // ��� ���
		pre = ready[idx].track_num; // ������ track��ȣ �Է�
		bool flag = false;
		for (int i = idx; i < ready_index; i++) { // ����� ���� ready���� ����
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
		int tmp; // �������� ����
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
			if (flag) { // ���������� ���� ������
				if (pre <= ready[i]) { // ���� �� Ŭ��� ���������� 
					result += cost + abs(pre - ready[i]);
					pre = ready[i];
					for (int j = i; j < ready_index; j++) { // ����� ready ����
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
			else { // �������� ���� ������
				if (pre >= ready[i]) { // ���� �� Ŭ��� ���������� 
					result += cost + abs(pre - ready[i]);
					pre = ready[i];
					for (int j = i; j < ready_index; j++) { // ����� ready ����
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

	int request_time, track_num; // ��û�ð��� �׶��� Ʈ�� ��ȣ
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