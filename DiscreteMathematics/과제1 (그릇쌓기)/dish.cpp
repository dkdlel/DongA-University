#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *inp, *out;

int main() {

	inp = fopen("dish.inp", "rt"); // dish.inp open
	out = fopen("dish.out", "wt"); // dish.out open

	int total_num; // 총 경우의 수
	int num; // 그릇의 갯수
	char dir; // 방향
	char dish_dir[1000];

	fscanf(inp, "%d", &total_num); // 첫째줄(총 경우의 수)

	for (int j = 0; j < total_num; j++) {

		int heigth = 10; // 그릇의 높이 10으로 초기화
		fscanf(inp, "%d\n", &num); // 그릇의 갯수

		for (int i = 0; i < num; i++) {
			fscanf(inp, "%c", &dir);
			dish_dir[i] = dir;
		}
		for (int i = 0; i < num - 1; i++) {
			if (dish_dir[i] == dish_dir[i + 1]) {
				heigth = heigth + 5;
			}
			else if (dish_dir[i] != dish_dir[i + 1]) {
				heigth = heigth + 10;
			}
		}
		fprintf(out, "%d\n", heigth);

	}
		

	fclose(inp);
	fclose(out);

	return 0;
}