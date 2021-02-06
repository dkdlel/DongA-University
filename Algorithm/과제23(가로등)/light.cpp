#include<bits/stdc++.h>
using namespace std;

ifstream fcin("light.inp");
ofstream fcout("light.out");

typedef struct  inf {
	int start, end; // 가로등의 시작과 끝
};
bool operator<(inf A, inf B) {
	return A.start < B.start;
}

bool cmp(const int& A, const inf& B) { return A < B.start; }

class Light {
public:
	int N, K; // N : 가로등의 개수, K : 밝혀야 할 가로등
	int idx, cnt; // 현재 인덱스, 필요한 가로등의 갯수
	bool flag, flag2; // flag : 더이상 확인을 안해도 될때, flag2 : 밝힐수 없을때
	vector < inf > street; // 가로등을 표시할 거리
	vector < inf > lamp; // 밝혀야 할 가로등
	void Input();
	void Sol();
};
void Light::Input() {
	int s, e;
	fcin >> N;
	while (N--) {
		fcin >> s >> e;
		street.push_back({ s,e });
	}
	sort(street.begin(), street.end());
	fcin >> K;
	for (int i = 0; i < K; i++) {
		fcin >> s >> e;
		lamp.push_back({ s,e });
	}
}
void Light::Sol() {
	for (int i = 0; i < K; i++) {
		flag = flag2 = false; idx = -1;
		int s = lamp[i].start;
		for (cnt = 0; ; cnt++) {

			if (flag) break; // 가로등을 밝힐수 없거나 밝힐 필요가 없을 경우

			int check_idx = idx;
			int max = -987654321;
			idx = upper_bound(street.begin(), street.end(), s, cmp) - street.begin();

			if (idx == check_idx) { // 가로등을 밝힐수 없을 때
				flag2 = true;
				break;
			}

			for (int j = idx - 1; j >= 0; j--) {
				if (s < street[j].end) {
					s = street[j].end;
				}
				if (lamp[i].end <= street[j].end) {
					flag = true;
					break;
				}
			}
		}

		if (flag2) fcout << "-1\n";
		else fcout << cnt << '\n';
	}
}
int main() {

	Light light;
	light.Input();
	light.Sol();

	return 0;
}