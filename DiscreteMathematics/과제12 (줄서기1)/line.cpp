#include <stdio.h>
#include <math.h>

FILE *inp, *out;
int check, cnt,final_max,final_min;
double max, min, n1, n2; // n1 : Q, n2 : A
bool isEnd; // 끝인지 확인

void sol() {
	cnt = 0, final_max = 1'000'000'000, final_min = 0; // 초기화
	isEnd = true;

	fscanf(inp, "%d\n", &check);
	for (int j = 0; j < check; j++) {
		fscanf(inp, "%lf %lf", &n1, &n2);
		if (isEnd == true) { // 계산끝나고 끝날때 까지 수를 받기 위해서
			cnt++;
			max = floor((n1 - 1 - ((n2 - 1)*(n2 - 2) / 2)) / (n2 - 1)); // 버림, 그림판 참고
			min = ceil((n1 - (n2*(n2 - 1)) / 2) / n2); // 올림
			if (final_min < min) { // 계산된 min값이 기존 min값보다 클 때
				final_min = min;
			}
			if (max < final_max) { // 계산된 max값이 기존 max값보다 작을 때
				final_max = max;
			}

			if (final_max == final_min) { // 값이 같을 때
				fprintf(out, "%d %d\n", cnt, final_max);
				isEnd = false; // 여기까지가 계산이에요
			}
		}
	}
	if (isEnd == true)
		fprintf(out, "%d\n", -1);
}
int main()
{
	inp = fopen("line.inp", "rt");
	out = fopen("line.out", "wt");

	int total_num;

	fscanf(inp, "%d\n", &total_num);
	for (int i = 0; i < total_num; i++) {
		sol();
	}
		

	fclose(inp);
	fclose(out);
	return 0;
}