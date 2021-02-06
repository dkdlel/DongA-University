#include <fstream>
using namespace std;

ifstream inp("frog.inp");
ofstream out("frog.out");

typedef struct Stone {
	char stone_sort;
	int width;
	bool check;
}Stone;

Stone S[102];

int total_num, stone_cnt, river_width;
int max1,max2, final_max;
char stone, bar;
int  d, distance_sub;

void LEFT_to_RIGHT() {
	// 왼쪽에서 오른쪽으로 건너기		
	for (int i = 0; i <= stone_cnt; i++) {

		// Big -> Big
		if (S[i].stone_sort == 'B' && S[i + 1].stone_sort == 'B') {
			// 두 거리간 차이 구하기
			distance_sub = S[i].width - S[i + 1].width;
			// 음수이면
			if (distance_sub < 0) distance_sub *= -1;
			// 작은값 찾기
			if (distance_sub > max1) max1 = distance_sub;
			// 밟은거 확인
			S[i + 1].check = true;
		}

		// Big -> Small
		else if (S[i].stone_sort == 'B' && S[i + 1].stone_sort == 'S') {
			distance_sub = S[i].width - S[i + 1].width;
			if (distance_sub < 0) distance_sub *= -1;
			if (distance_sub > max1) max1 = distance_sub;
			S[i + 1].check = true;
		}

		// Small -> Big
		else if (S[i].stone_sort == 'S' && S[i + 1].stone_sort == 'B') {
			// 밟은 S이면
			if (!S[i].stone_sort) {
				distance_sub = S[i].width - S[i + 1].width;
				if (distance_sub < 0) distance_sub *= -1;
				if (distance_sub > max1) max1 = distance_sub;
			}
			//안밟은 S이면
			else {
				distance_sub = S[i - 1].width - S[i + 1].width;
				if (distance_sub < 0) distance_sub *= -1;
				if (distance_sub > max1) max1 = distance_sub;
			}
		}

		// Small -> Small
		else if (S[i].stone_sort == 'S' && S[i + 1].stone_sort == 'S') {
			// 앞에 S는 밟았고 뒤에 S는 안밟았을때
			if (S[i].check && !S[i + 1].check) continue;
			// 앞에 S는 안밟았고 뒤에 S는 밟았을때
			else {
				distance_sub = S[i - 1].width - S[i + 1].width;
				if (distance_sub < 0) distance_sub *= -1;
				if (distance_sub > max1) max1 = distance_sub;
  				S[i + 1].check = true;
			}
		}
	}
}

void RIGHT_to_LEFT() {
	// 오른쪽에서 왼쪽으로 건너기
	for (int i = stone_cnt+1; i > 0; i--) {

		// Big -> Big
		if (S[i].stone_sort == 'B' && S[i - 1].stone_sort == 'B') {
				// 두 거리간 차이 구하기
				distance_sub = S[i].width - S[i - 1].width;
				// 음수이면
				if (distance_sub < 0) distance_sub *= -1;
				// 작은값 찾기
				if (distance_sub > max2) max2 = distance_sub;
		}

		// Big -> Small
		else if (S[i].stone_sort == 'B' && S[i - 1].stone_sort == 'S') {
			// Small돌을 밟지 않았을 때
			if (!S[i - 1].check) {
				distance_sub = S[i].width - S[i - 1].width;
				if (distance_sub < 0) distance_sub *= -1;
				if (distance_sub > max2) max2 = distance_sub;
				S[i - 1].check = true;
			}
		}

		// Small -> Big
		else if (S[i].stone_sort == 'S' && S[i - 1].stone_sort == 'B') {

			// small이 밟은거 일때
			if (S[i].check) {
				distance_sub = S[i + 1].width - S[i - 1].width;
				if (distance_sub < 0) distance_sub *= -1;
				if (distance_sub > max2) max2 = distance_sub;
				S[i - 1].check = true;
			}
		}

		// Small -> Small
		else if (S[i].stone_sort == 'S' && S[i - 1].stone_sort == 'S') {
			// 앞에 S는 밟았고 뒤에 S는 안밟았을때
			if (S[i].check && !S[i - 1].check) {
				distance_sub = S[i+1].width - S[i - 1].width;
				if (distance_sub < 0) distance_sub *= -1;
				if (distance_sub > max2) max2 = distance_sub;
				S[i - 1].check = true;
			}
		}
	}
}

int main() {


	inp >> total_num;

	for (int T = 1; T <= total_num; T++) {
		max1 = 0; max2 = 0;
		inp >> stone_cnt >> river_width;

		for (int i = 1; i <= stone_cnt; i++) {
			inp >> stone >> bar >> d;
			S[i].stone_sort = stone;
			S[i].width = d;
		}

		//시작과 끝점은 B, false로 설정
		S[0].stone_sort = 'B'; S[stone_cnt + 1].stone_sort = 'B';
		S[0].check = false; S[stone_cnt + 1].check = false;
		S[0].width = 0; S[stone_cnt + 1].width = river_width;
		//왼쪽에서 오른쪽으로
		LEFT_to_RIGHT();

		//시작과 끝점은 B로 설정
		S[0].stone_sort = 'B'; S[stone_cnt + 1].stone_sort = 'B';
		S[0].check = false; S[stone_cnt + 1].check = false;
		S[0].width = 0; S[stone_cnt + 1].width = river_width;
		//오른쪽에서 왼쪽
		RIGHT_to_LEFT();

		max1 < max2 ? final_max = max2 : final_max = max1;

		out << "Case " << T << ": " << final_max << endl;

		for (int i = 1; i <= stone_cnt; i++) {
			S[i].stone_sort = '\0';
			S[i].width = 0;
			S[i].check = false;
		}
	}
	return 0;
}