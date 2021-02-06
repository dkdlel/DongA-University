#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 100000

FILE *inp, *out;
int total_num,num;

typedef struct HEAP // // 히프에 대한 1차원 배열과 히프 원소의 갯수 선언
{
	long long int heap[MAX_ELEMENT];
	long long int heap_size;
}HEAP;

HEAP* createheap()
{
	HEAP *heap = (HEAP*)malloc(sizeof(HEAP));
	heap->heap_size = 0;
	return heap;
}

void insertheap(HEAP *heap, long long int x) // 삽입
{
	long long int i=0;

	heap->heap_size = heap->heap_size + 1; // 숫자 하나 커지니까 크기도 1 증가
	i = heap->heap_size; // i에 크기값 넣기
	
	while ((i != 1) && (x < heap->heap[i / 2])) { // i가 처음이 아니고 삽입값이 부모의 값보다 작을 때
		heap->heap[i] = heap->heap[i / 2]; // 부모 노드의 값을 자식노드에 대입
		i /= 2; // 부모노드 주소 찾기
	}
	heap->heap[i] = x; // 해당위치에 삽입
}

long long int pop(HEAP *heap)
{
	int parent = 1, child =2; // parent 맨위, chile 자식중에 맨 왼쪽
	long long int x, temp;

	x = heap->heap[1]; // 제일 처음값 대입
	temp = heap->heap[heap->heap_size]; // temp에 제일 마지막값 대입
	heap->heap_size = heap->heap_size - 1; // pop했으니까 전체 크기 1씩 줄이기

	while (child <= heap->heap_size) // 자식 번지수가 전체크기보다 작거나 같을때 까지
	{
		if ((child < heap->heap_size) && (heap->heap[child] > heap->heap[child + 1])) // 자식번지수가 전체크기보다 작고 자식번지수의 값이 그 다음의 값보다 클경우
		{ // 자식중에 작은거 찾기
			child++; // 자식 번지수 다음 번지로
		}
		if (temp <= heap->heap[child]) break; //전체크기랑 temp의 수랑 같으면 끝
		else
		{
			heap->heap[parent] = heap->heap[child]; // 자식중에 작은값 맨 위로
			parent = child; // 큰값을 부모로 저장
			child = child * 2; // 자식은 *2 로 시작하니까
		}
	}
	heap->heap[parent] = temp; // 맨위에값 넣기
	return x; // 맨 위에값 반환
}
long long int sol(HEAP *heap, int num) // 해결
{
	long long int cost = 0; // 최종 결과값

	while (1)
	{
		long long int x = pop(heap);
		long long int y = pop(heap); // 제일작은 수 2개 뽑기

		cost = cost + x + y;

		if (heap->heap_size != 0) // pop할것이 있을 때
		{
			insertheap(heap, x + y); // 두개 더한값을 다시 삽입
		}
		else // pop할것이 없을 때
			return cost;
	}


}

int main()
{
	inp = fopen("add.inp", "rt");
	out = fopen("add.out", "wt");

	HEAP *heap = createheap();
	while (1)
	{
		fscanf(inp, "%d\n", &total_num);
		if (total_num == 0) break; // 0이면 끝
		for (int i = 0; i < total_num; i++)
		{
			fscanf(inp, "%d", &num);
			insertheap(heap, num);
		}
		fprintf(out, "%lld\n", sol(heap, total_num));
	}
	fclose(inp);
	fclose(out);
	return 0;
}