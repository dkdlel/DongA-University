#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 100000

FILE *inp, *out;
int total_num,num;

typedef struct HEAP // // ������ ���� 1���� �迭�� ���� ������ ���� ����
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

void insertheap(HEAP *heap, long long int x) // ����
{
	long long int i=0;

	heap->heap_size = heap->heap_size + 1; // ���� �ϳ� Ŀ���ϱ� ũ�⵵ 1 ����
	i = heap->heap_size; // i�� ũ�Ⱚ �ֱ�
	
	while ((i != 1) && (x < heap->heap[i / 2])) { // i�� ó���� �ƴϰ� ���԰��� �θ��� ������ ���� ��
		heap->heap[i] = heap->heap[i / 2]; // �θ� ����� ���� �ڽĳ�忡 ����
		i /= 2; // �θ��� �ּ� ã��
	}
	heap->heap[i] = x; // �ش���ġ�� ����
}

long long int pop(HEAP *heap)
{
	int parent = 1, child =2; // parent ����, chile �ڽ��߿� �� ����
	long long int x, temp;

	x = heap->heap[1]; // ���� ó���� ����
	temp = heap->heap[heap->heap_size]; // temp�� ���� �������� ����
	heap->heap_size = heap->heap_size - 1; // pop�����ϱ� ��ü ũ�� 1�� ���̱�

	while (child <= heap->heap_size) // �ڽ� �������� ��üũ�⺸�� �۰ų� ������ ����
	{
		if ((child < heap->heap_size) && (heap->heap[child] > heap->heap[child + 1])) // �ڽĹ������� ��üũ�⺸�� �۰� �ڽĹ������� ���� �� ������ ������ Ŭ���
		{ // �ڽ��߿� ������ ã��
			child++; // �ڽ� ������ ���� ������
		}
		if (temp <= heap->heap[child]) break; //��üũ��� temp�� ���� ������ ��
		else
		{
			heap->heap[parent] = heap->heap[child]; // �ڽ��߿� ������ �� ����
			parent = child; // ū���� �θ�� ����
			child = child * 2; // �ڽ��� *2 �� �����ϴϱ�
		}
	}
	heap->heap[parent] = temp; // �������� �ֱ�
	return x; // �� ������ ��ȯ
}
long long int sol(HEAP *heap, int num) // �ذ�
{
	long long int cost = 0; // ���� �����

	while (1)
	{
		long long int x = pop(heap);
		long long int y = pop(heap); // �������� �� 2�� �̱�

		cost = cost + x + y;

		if (heap->heap_size != 0) // pop�Ұ��� ���� ��
		{
			insertheap(heap, x + y); // �ΰ� ���Ѱ��� �ٽ� ����
		}
		else // pop�Ұ��� ���� ��
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
		if (total_num == 0) break; // 0�̸� ��
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