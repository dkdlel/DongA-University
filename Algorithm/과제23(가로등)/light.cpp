#include<bits/stdc++.h>
using namespace std;

ifstream fcin("light.inp");
ofstream fcout("light.out");

typedef struct  inf {
	int start, end; // ���ε��� ���۰� ��
};
bool operator<(inf A, inf B) {
	return A.start < B.start;
}

bool cmp(const int& A, const inf& B) { return A < B.start; }

class Light {
public:
	int N, K; // N : ���ε��� ����, K : ������ �� ���ε�
	int idx, cnt; // ���� �ε���, �ʿ��� ���ε��� ����
	bool flag, flag2; // flag : ���̻� Ȯ���� ���ص� �ɶ�, flag2 : ������ ������
	vector < inf > street; // ���ε��� ǥ���� �Ÿ�
	vector < inf > lamp; // ������ �� ���ε�
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

			if (flag) break; // ���ε��� ������ ���ų� ���� �ʿ䰡 ���� ���

			int check_idx = idx;
			int max = -987654321;
			idx = upper_bound(street.begin(), street.end(), s, cmp) - street.begin();

			if (idx == check_idx) { // ���ε��� ������ ���� ��
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