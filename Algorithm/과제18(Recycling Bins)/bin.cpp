#include<bits/stdc++.h>
#define INF 999999999
using namespace std;

ifstream fcin("bin.inp");
ofstream fcout("bin.out");

class Bin {
public:
	int testcase, house_num, trash_num; // house_num : 집의 수, trash_num : 쓰레기통 수
	vector<int> vec; // 입력 배열
	vector < vector < int > > distance, cache; // distacne : 쓰레기통이 한개일 때 거리들의 합, cache : 앞의 집들에서 쓰레기통을 나누는 경우를 저장
	void Init(); // 초기화
	void Once(); //쓰레기통이 한개일때 최솟값
	void Sol();
};
void Bin::Once() {
	for (int i = 1; i <= house_num; i++) {
		for (int j = i + 1; j <= house_num; j++) {
			int mid = (i + j) / 2;
			distance[i][j] = distance[i][j - 1] + abs(vec[j] - vec[mid]);
		}
	}
}
void Bin::Init() {
	vec.clear(); vec.resize(house_num + 1);
	distance.clear(); distance.resize(house_num + 1, vector<int>(house_num + 1, 0));
	cache.clear(); cache.resize(house_num + 1, vector<int>(trash_num + 1, INF));
	for (int i = 1; i <= house_num; i++) fcin >> vec[i];
	for (int i = 0; i <= trash_num; i++) cache[0][i] = 0;
	sort(vec.begin(), vec.end());
}
void Bin::Sol() {
	for (int i = 1; i <= house_num; i++) {
		for (int j = 1; j <= trash_num; j++) {
			for (int k = 1; k <= i; k++) {
				cache[i][j] = min(cache[i][j], cache[i - k][j - 1] + distance[i - k + 1][i]);
			}
		}
	}
	fcout << cache[house_num][trash_num] << '\n';
}
int main() {

	Bin bin;
	fcin >> bin.testcase;
	while (bin.testcase--) {
		fcin >> bin.house_num >> bin.trash_num;
		bin.Init();
		bin.Once();
		bin.Sol();
	}
	return 0;
}