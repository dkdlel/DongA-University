#include <stdio.h>
#include <stdlib.h>

typedef struct SNode // ���ó�� ���� ����
{
	char data;
	struct SNode *link;
}SNode;

SNode* top; // ������ top���
FILE *inp, *out;

SNode *Create_Stack()// ���� ���ó�� ����
{
	SNode* new_Node = (SNode*)malloc(sizeof(SNode));
	new_Node->link = NULL;
	return new_Node;
}

void Push(SNode* list, char x) // ���ÿ� �����ϳ� push
{
	SNode* push = Create_Stack();
	push->data = x;
	push->link = top;
	top = push;
}

char Pop(SNode* list) // ���ÿ� �����ϳ� pop
{
	char x;
	SNode* pop = top;

	if (top == NULL)	return 0;
	else
	{
		x = pop->data;
		top = pop->link;
		free(pop);
		return x;
	}
} // ���� ��

void printStack()// ���� ���
{
	SNode *Sn = Create_Stack();

	char inp_x;

	while (1)
	{
		fscanf(inp, "%c", &inp_x);
		if (inp_x == '\n')	break;
		Push(Sn, inp_x);
	}

	SNode* print = top;

	while (print)
	{
		fprintf(out, "%c", print->data);
		print = print->link;
	}
	fprintf(out, "\n");
}

typedef struct QNode // ť��� ����
{
	char data;
	struct QNode *link;
}QNode;

typedef struct  // ���� ť���� ����ϴ� ������ front�� rear�� ����ü�� ���� 
{
	QNode *front, *rear;
}Qnode;

Qnode *Create_Queue()// ���� ť��� ����
{
	Qnode *new_Node = (Qnode*)malloc(sizeof(Qnode));
	new_Node->front = NULL;
	new_Node->rear = NULL;
	return new_Node;
}

void enQueue(Qnode *list, char x) // ����ť rear�� ���� ����
{
	QNode *eq = (QNode*)malloc(sizeof(QNode));
	eq->data = x;
	eq->link = NULL;
	if (list->front == NULL) // ���� ���� ť�� ������ ���
	{
		list->rear = eq;
		list->front = eq;
	}

	else // ���� ���� ť�� ������ �ƴ� ���
	{
		list->rear->link = eq;
		list->rear = eq;
	}

}

char deQueue(Qnode *list) // ����ť front�� ���� ���� & ��ȯ
{
	QNode *old = list->front;
	char x;
	if (list->front == NULL)	return 0;
	else
	{
		x = old->data;
		list->front = list->front->link;
		if (list->front == NULL)
			list->rear = NULL;
		free(old);
		return x;
	}
}

void printQueue()
{
	Qnode *key = Create_Queue(); // key�ڵ� (����)
	Qnode *Qn = Create_Queue(); // ��ȣȭ�� ����

	char inp_x, d1, d2, tool, temp = NULL;

	while (1) // ��ȣȭ�� ���� Qn�� ��ť
	{
		fscanf(inp, "%c", &inp_x);
		if (inp_x == '\n')	break;
		enQueue(Qn, inp_x);
	}
	while (1) // key�ڵ� key�� ��ť
	{
		fscanf(inp, "%c", &inp_x);
		if (inp_x == '\n')	break;
		enQueue(key, inp_x);
	}

	while (Qn) // Qn�� �����Ҷ� ����
	{
		d1 = deQueue(Qn); // Qn���� ������
		if (d1 == ' ')	fprintf(out, " "); // ��������
		// �����̸� ���� ����ϰ� ��
		else // ���� �ƴϸ�
		{
			d2 = deQueue(key); // key ����
			if (d1 >= 'A' && d1 <= 'Z')	tool = 'A'; // �빮��
			else tool = 'a'; // �ҹ���
			temp = d1 - tool; // 0~26������ ���� ���������
			temp = (temp + '0' - d2 + 26) % 26; // '0' - d2 : �츮�� �Է��ϴ� ���� ����� ����
			// + 26 : Ȥ�� ����Ѱ��� �����ϼ��� ������
			fprintf(out, "%c", (char)(temp + tool)); // ����� ���� ��(��)���� a�� �����ָ� ���ϴ� ��� ���
			enQueue(key, d2); // key�ڵ�� �ݺ��̱� ������ �ٽ� ��ť
		}
		if (Qn->front == NULL)	break;
	}
}

int main()
{
	inp = fopen("hw3.inp", "rt");
	out = fopen("hw3.out", "wt");

	printStack();
	printQueue();
	fprintf(out, "\n*");

	fclose(inp);
	fclose(out);
	return 0;
}