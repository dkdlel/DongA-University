#include <stdio.h>
#include <stdlib.h>

FILE *inp, *out;

int main(void) {

	inp = fopen("matrix.inp", "rt");
	out = fopen("matrix.out", "wt");

	int matrix[300][300];
	int total_num, len, n1 = 0, n2, n3,n4;

	fscanf(inp, "%d\n", &total_num); // 총 횟수

	for (int a = 0; a < total_num; a++) { // 전체 반복
		fscanf(inp, "%d\n", &len); // 몇 정방 행렬인지
		for (int i = 0; i < len; i++) // 행렬 넣기
		{
			for (int j = 0; j < len; j++) {
				fscanf(inp, "%d", &n1);
				matrix[i][j] = n1;
			}
		}
		n3 = len * len; // 전체 갯수
		n2 = 0;
		for (int i = 0; i < len; i++) {
			for (int j = 0; j < len; j++) {
				if (matrix[i][j] == 1)
				{
					n3 -= 1; // 전체 행렬갯수에서 1의 갯수만큼 빼기
					continue;
				}
				else {
					n4 = 0;
					for (int k = 0; k < len; k++) {
						for (int l = 0; l < len; l++) {
							if (matrix[i][l] + matrix[k][j] == matrix[i][j]) // 연산
							{
								n2 += 1;
								n4 += 1;
								break;
							}
						}
						if (n4 == 1)	break;
					}
				}
			}
		}
		fprintf(out, "%d\n", (n2 == n3) ? 1 : 0);
	}
	

	return 0;
}