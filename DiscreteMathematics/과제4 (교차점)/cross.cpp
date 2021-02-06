#include <stdio.h>

int main()
{
	FILE *inp = fopen("cross.inp", "rt");
	FILE *out = fopen("cross.out", "wt");
	int total_num, len, arr_1[10000], arr_2[10000],n1,result;

	fscanf(inp, "%d\n", &total_num);

	for (int t = 0; t < total_num; t++)
	{
		result = 0;
		fscanf(inp, "%d\n", &len);
		for (int i = 1; i <= len; i++) // 첫번째 배열 대입
		{
			fscanf(inp, "%d", &n1);
			arr_1[n1] = i; // 주소번지와 값의 위치를 바꿈
		}
		for (int i = 1; i <= len; i++) // 두번째 배열 대입
		{
			fscanf(inp, "%d", &n1);
			arr_2[n1] = i;
		}

		for (int i = 1; i <= len; i++)
		{
			for (int j = 1; j <= len; j++)
			{
				if (arr_1[i] < arr_1[j] && arr_2[i] > arr_2[j])	result++; // 첫번째 배열 왼쪽과 두번쨰 배열 오른쪽 수들을 비교
			}
		}
		fprintf(out, "Case %d: %d\n", t+1,result);
	}

	fclose(inp);
	fclose(out);
	return 0;
}