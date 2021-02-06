#include <stdio.h>
#include <stdlib.h>

typedef struct Node // 노드 구조 정의
{
	int coef; // 계수
	int expo; // 지수
	struct Node *link;
}Node;

typedef struct List // 헤더 노드 구조 정의
{
	Node *head;
}List;

List* create_list() // 공백 다항식 리스트 생성
{
	List* new_list = (List*)malloc(sizeof(List)); // 헤더노드
	new_list->head = NULL;
	return new_list;
}

//void Insertnode(List* list, int coef, int expo) { // 다항식 리스트에 삽입 by wang
//	Node* new_node = (Node*)malloc(sizeof(Node)); // 노드 생성
//	new_node->coef = coef; // 새로만든 노드 지수에 선언한 값 대입
//	new_node->expo = expo; // 새로만든 노드 계수에 선언한 값 대입
//	new_node->link = NULL; // 새로만든 노드 link값은 NULL
//
//	if (list->head == NULL) // 초기 공백
//	{
//		list->head = new_node;
//		return;
//	}
//	else if (list->head->link == NULL) // 초기 공백
//	{
//		if (list->head->expo > expo) 		list->head->link = new_node;
//		else if (list->head->expo < expo) {
//			new_node->link = list->head;
//			list->head = new_node;
//		}
//		return;
//	}
//	else {
//		Node *p = list->head;
//		if (list->head->expo < expo) {
//			new_node->link = list->head;
//			list->head = new_node;
//			return;
//		}
//		else {
//			while (p->link!=NULL) {
//				if (p->link->expo > expo) p = p->link;
//				else if (p->link->expo == expo) return;
//				else {
//					new_node->link = p->link;
//					p->link = new_node;
//					return;
//				}
//			}
//			p->link = new_node;
//		}
//	}
//}

void insert_node(List* list, int coef, int expo) // 다항식 리스트에 삽입 by JeJn
{
	Node* new_node = (Node*)malloc(sizeof(Node)); // 노드 생성
	Node* current_node = list->head; // 기존에 있는 다항식
	Node* temp_node; // new노드 삽입하기위해 있는 다항식

	new_node->coef = coef; // 새로만든 노드 지수에 선언한 값 대입
	new_node->expo = expo; // 새로만든 노드 계수에 선언한 값 대입
	new_node->link = NULL; // 새로만든 노드 link값은 NULL

	if (list->head == NULL) // 초기 공백
	{
		list->head = new_node;
		return;
	}

	if (current_node->link == NULL)
	{
		if (current_node->expo > new_node->expo)
		{
			current_node->link = new_node;
		}
		else if (current_node->expo < new_node->expo)
		{
			new_node->link = current_node;
			list->head = new_node;
		}
	}
	else {
		while (current_node->link != NULL)
		{

			if (current_node->expo == expo)
				return;
			else if (current_node->link->expo == expo)// 두개 같으면
				return;

			if (current_node->expo < new_node->expo)
			{
				new_node->link = current_node;
				list->head = new_node;
				break;
			}

			if (current_node->link->expo > expo) // 기존에 있는 다항식의 지수가 새로운 다항식의 지수보다 클 경우
			{
				current_node = current_node->link;
			}
			else if (current_node->link->expo < expo) // 기존에 있는 다항식의 지수가 새로운 다항식의 지수보다 작을 경우
			{
				temp_node = new_node;
				new_node = new_node->link;
				temp_node->link = current_node->link;
				current_node->link = temp_node;
				break;
			}


			if (current_node->link == NULL)
			{
				current_node->link = new_node;
			}
		}
	}
}

void add_Node(List* list, int coef, int expo) {
	Node* new_node = (Node*)malloc(sizeof(Node)); // 노드 생성
	Node *p;
	new_node->coef = coef; // 새로만든 노드 지수에 선언한 값 대입
	new_node->expo = expo; // 새로만든 노드 계수에 선언한 값 대입
	new_node->link = NULL; // 새로만든 노드 link값은 NULL

	if (list->head == NULL) {
		list->head = new_node;
		return;
	}
	else {
		p = list->head;
		while (p->link != NULL) p = p->link;
		p->link = new_node;
	}
}

void add_poly(List* P1, List* P2, List* P3) // P1다항식과 P2다항식을 더해서 P3에 저장
{
	Node* p1 = P1->head; // 첫번째 다항식
	Node* p2 = P2->head; // 두번째 다항식
	int sum;

	while (p1 && p2) // p1노드와 p2노드가 있는동안
	{
		if (p1->expo == p2->expo) // 지수가 같을때
		{
			sum = p1->coef + p2->coef;
			insert_node(P3, sum, p1->expo);
			p1 = p1->link;
			p2 = p2->link;
		}

		else if (p1->expo > p2->expo) // p1의 지수가 클때
		{
			insert_node(P3, p1->coef, p1->expo);
			p1 = p1->link;
		}

		else // p2의 지수가 클때
		{
			insert_node(P3, p2->coef, p2->expo);
			p2 = p2->link;
		}
	}

	for (; p1 != NULL; p1 = p1->link) // 나머지 다출력
		insert_node(P3, p1->coef, p1->expo);

	for (; p2 != NULL; p2 = p2->link) // 나머지 다출력
		insert_node(P3, p2->coef, p2->expo);
}

void print_poly(List* list, FILE* out) // 다항식 출력
{
	Node* print_node = list->head;

	while (print_node != NULL)
	{
		fprintf(out, "%d %d ", print_node->coef, print_node->expo);
		print_node = print_node->link;
	}
	fprintf(out, "\n");
}

void delete_poly(List* list, int expo) // 다항식 삭제
{
	Node* now_node;

	now_node = list->head; // 맨압 노드를 가르킴

	if (list->head == NULL) return;

	if (list->head->expo == expo)
	{
		list->head = list->head->link;
		return;
	}

	else
	{
		while (now_node->link != NULL)
		{
			if (now_node->link->expo == expo)
			{
				now_node->link = now_node->link->link;
				break;
			}
			now_node = now_node->link;
		}
	}
}

int main() {

	FILE *inp = fopen("hw2.inp", "rt");
	FILE *out = fopen("hw2.out", "wt");

	List *P1 = create_list(); // P1 생성
	List *total = create_list(); // P1 저장하기 위한
	List *Temp = create_list(); // add_poly쓰기위함

	char c1 = '\n'; // 비교할 문자
	char c2; // 비교할 문자
	char temp; // \n받을 문자
	int coef; // 계수
	int expo; // 지수

	for (int i = 0; i < 2; i++) {
		while (1) {
			if (fscanf(inp, "%d %d", &coef, &expo))		fscanf(inp, "%c", &c1);
			else if (c1 == '\n' || c1 == ' ') break;
			add_Node(P1, coef, expo);
		}

		fscanf(inp, "%c", &c1);

		if (c1 == 'I')
		{
			fscanf(inp, "%c", &c2); // \n받는용
			for (;;)
			{
				fscanf(inp, "%d %d%c", &coef, &expo, &c1);
				insert_node(P1, coef, expo);

				if (c1 == '\n') 	break;
			}
		}
		else if (c1 == 'D')
		{
			fscanf(inp, "%c", &c2); // \n받는용
			for (;;)
			{
				fscanf(inp, "%d%c", &expo, &c1);
				delete_poly(P1, expo);
				if (c1 == '\n') break;
			}
		}
		print_poly(P1, out);
		add_poly(P1, total, Temp);
		total = Temp;
		P1 = create_list();
		Temp = create_list();
	}
	print_poly(total, out);

	fprintf(out, "*");

	fclose(inp);
	fclose(out);

	return 0;
}