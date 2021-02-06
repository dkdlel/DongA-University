#include <stdio.h>

FILE *inp, *out;
int total_num, ori[1001], result[1001], TEMP[1001], num, n1, cnt, answer,temp;

void input()
{
	fscanf(inp, "%d\n", &num);
	for (int j = 1; j <= num; j++) // 원래 배열 받기
	{
		fscanf(inp, "%d", &n1);
		ori[j] = n1;
	}
	for (int j = 1; j <= num; j++) // 결과 배열 받기
	{
		fscanf(inp, "%d", &n1);
		result[j] = n1;
	}
}

void sol()
{
	for (int i = num; i >= 1; i--) // 기존 배열은 마지막에서
	{
		for (int j = 1; j <= num; j++) // 결과 배열은 처음에서
		{
			if (ori[i] == result[j]) // 같을 경우
			{
				answer = i - j; // 인덱스의 값 빼기
				if (answer < 0) answer *= -1; // 음수면 양수로 바꾸기
				TEMP[ori[i]] = answer; // 출력 배열에 넣기
				for (int k = j; k < num; k++)
				{
					temp = result[k];
					result[k] = result[k + 1];
					result[k + 1] = temp;
				}
				break;
			}
		}
	}

	for (int j = 1; j <= num; j++)
	{
		fprintf(out, "%d ", TEMP[j]);
	}
	fprintf(out, "\n");
	
}

int main() {

	inp = fopen("line2.inp", "rt");
	out = fopen("line2.out", "wt");

	fscanf(inp, "%d\n", &total_num);
	for (int i = 0; i < total_num; i++) // 전체 돌기
	{
		input();
		sol();
	}

	fclose(inp);
	fclose(out);
	return 0;
}