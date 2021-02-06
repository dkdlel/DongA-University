#include <stdio.h>
#include <stdlib.h>

typedef struct SNode // 스택노드 구조 정의
{
	char data;
	struct SNode *link;
}SNode;

SNode* top; // 스택의 top노드
FILE *inp, *out;

SNode *Create_Stack()// 공백 스택노드 생성
{
	SNode* new_Node = (SNode*)malloc(sizeof(SNode));
	new_Node->link = NULL;
	return new_Node;
}

void Push(SNode* list, char x) // 스택에 문자하나 push
{
	SNode* push = Create_Stack();
	push->data = x;
	push->link = top;
	top = push;
}

char Pop(SNode* list) // 스택에 문자하나 pop
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
} // 스택 팝

void printStack()// 스택 출력
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

typedef struct QNode // 큐노드 정의
{
	char data;
	struct QNode *link;
}QNode;

typedef struct  // 연결 큐에서 사용하는 포인터 front와 rear를 구조체로 정의 
{
	QNode *front, *rear;
}Qnode;

Qnode *Create_Queue()// 공백 큐노드 생성
{
	Qnode *new_Node = (Qnode*)malloc(sizeof(Qnode));
	new_Node->front = NULL;
	new_Node->rear = NULL;
	return new_Node;
}

void enQueue(Qnode *list, char x) // 연결큐 rear에 원소 삽입
{
	QNode *eq = (QNode*)malloc(sizeof(QNode));
	eq->data = x;
	eq->link = NULL;
	if (list->front == NULL) // 현재 연결 큐가 공백인 경우
	{
		list->rear = eq;
		list->front = eq;
	}

	else // 현재 연결 큐가 공백이 아닌 경우
	{
		list->rear->link = eq;
		list->rear = eq;
	}

}

char deQueue(Qnode *list) // 연결큐 front에 원소 삭제 & 반환
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
	Qnode *key = Create_Queue(); // key코드 (숫자)
	Qnode *Qn = Create_Queue(); // 암호화된 문자

	char inp_x, d1, d2, tool, temp = NULL;

	while (1) // 암호화된 문자 Qn에 인큐
	{
		fscanf(inp, "%c", &inp_x);
		if (inp_x == '\n')	break;
		enQueue(Qn, inp_x);
	}
	while (1) // key코드 key에 인큐
	{
		fscanf(inp, "%c", &inp_x);
		if (inp_x == '\n')	break;
		enQueue(key, inp_x);
	}

	while (Qn) // Qn이 존재할때 까지
	{
		d1 = deQueue(Qn); // Qn에서 빼내고
		if (d1 == ' ')	fprintf(out, " "); // 공백인지
		// 공백이면 공백 출력하고 끝
		else // 공백 아니면
		{
			d2 = deQueue(key); // key 빼냄
			if (d1 >= 'A' && d1 <= 'Z')	tool = 'A'; // 대문자
			else tool = 'a'; // 소문자
			temp = d1 - tool; // 0~26까지의 수를 만들기위해
			temp = (temp + '0' - d2 + 26) % 26; // '0' - d2 : 우리가 입력하는 수를 만들기 위해
			// + 26 : 혹시 계산한값이 음수일수도 있으니
			fprintf(out, "%c", (char)(temp + tool)); // 계산한 값에 대(소)문자 a를 더해주면 원하는 결과 출력
			enQueue(key, d2); // key코드는 반복이기 때문에 다시 인큐
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