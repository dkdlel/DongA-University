#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int N(int num) // N함수
{
	return num; // 입력받은 num 반환
}

int Log(int num) // log2 함수
{
	return (int)(log(num) / log(2)); // log num 반환
}

int Logn(int num) // nlog2n 함수
{
	return (int)(num*Log(num)); // numlog2num 반환
}
int Mul(int num) // 2의n승 함수
{
	int result=1; // 결과값(0승은 1이니까 1로 초기화)

			for (int j = 0; j < num; j++) // n승 구하기
				result = 2 * result;

	return result; // 최종 결과 반환
}
int Fac(int num) // 팩토리얼 함수
{
	if (num <= 1) // 1보다 작을때
		return 1;
	else
		return num * Fac(num - 1); // 팩토리얼 반환
}
int main(void)
{
	FILE *input_fp = fopen("hw1.inp", "rt"); //hw1 open
	FILE *output_fp = fopen("hw1.out", "wt"); //hw2 open

	int num = 0; // 수열의 수의 개수
	char star; // 별 받을꺼임
	float *big_o = NULL;

	if ((input_fp = fopen("hw1.inp", "rt")) == NULL)
	{
		fprintf(stderr, "can't open %s\n", "hw1.inp");
	}

	if ((output_fp = fopen("hw1.out", "wt")) == NULL)
	{
		fprintf(stderr, "can't open %s\n", "hw1.out");
	}
	// calloc(num, sizeof(float))
	if ((big_o = (float*)malloc(sizeof(float)*5)) == NULL)
	{
		fprintf(stderr, "memory allocation error\n");
	}

	for(;;) // 입력과 출력을 한번에하기위한 반복문
	{
		fscanf(input_fp, "%d", &num); // 숫자받음
		fscanf(input_fp, "%c", &star); // \n이랑 *받을꺼임
		if (star == '*') // *받으면 탈출
			break;
		big_o[0] = N(num); //big_o에 대입
		big_o[1] = Log(num);
		big_o[2] = Logn(num);
		big_o[3] = Mul(num);
		big_o[4] = Fac(num);
		fprintf(output_fp, "1)%d 2)%d 3)%d 4)%d 5)%d\n", (int)big_o[0], (int)big_o[1], (int)big_o[2], (int)big_o[3], (int)big_o[4]); //출력
	}
	fprintf(output_fp, "*"); // 마지막 별

	fclose(input_fp); // hw1 close
	fclose(output_fp); // hw2 close
	free(big_o);

	return 0;
}