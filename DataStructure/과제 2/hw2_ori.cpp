#include <stdio.h>
#include <stdlib.h>

typedef struct Node // ��� ���� ����
{
	int coef; // ���
	int expo; // ����
	struct Node *link;
}Node;

typedef struct List // ��� ��� ���� ����
{
	Node *head;
}List;

List* create_list() // ���� ���׽� ����Ʈ ����
{
	List* new_list = (List*)malloc(sizeof(List)); // ������
	new_list->head = NULL;
	return new_list;
}

//void Insertnode(List* list, int coef, int expo) { // ���׽� ����Ʈ�� ���� by wang
//	Node* new_node = (Node*)malloc(sizeof(Node)); // ��� ����
//	new_node->coef = coef; // ���θ��� ��� ������ ������ �� ����
//	new_node->expo = expo; // ���θ��� ��� ����� ������ �� ����
//	new_node->link = NULL; // ���θ��� ��� link���� NULL
//
//	if (list->head == NULL) // �ʱ� ����
//	{
//		list->head = new_node;
//		return;
//	}
//	else if (list->head->link == NULL) // �ʱ� ����
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

void insert_node(List* list, int coef, int expo) // ���׽� ����Ʈ�� ���� by JeJn
{
	Node* new_node = (Node*)malloc(sizeof(Node)); // ��� ����
	Node* current_node = list->head; // ������ �ִ� ���׽�
	Node* temp_node; // new��� �����ϱ����� �ִ� ���׽�

	new_node->coef = coef; // ���θ��� ��� ������ ������ �� ����
	new_node->expo = expo; // ���θ��� ��� ����� ������ �� ����
	new_node->link = NULL; // ���θ��� ��� link���� NULL

	if (list->head == NULL) // �ʱ� ����
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
			else if (current_node->link->expo == expo)// �ΰ� ������
				return;

			if (current_node->expo < new_node->expo)
			{
				new_node->link = current_node;
				list->head = new_node;
				break;
			}

			if (current_node->link->expo > expo) // ������ �ִ� ���׽��� ������ ���ο� ���׽��� �������� Ŭ ���
			{
				current_node = current_node->link;
			}
			else if (current_node->link->expo < expo) // ������ �ִ� ���׽��� ������ ���ο� ���׽��� �������� ���� ���
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
	Node* new_node = (Node*)malloc(sizeof(Node)); // ��� ����
	Node *p;
	new_node->coef = coef; // ���θ��� ��� ������ ������ �� ����
	new_node->expo = expo; // ���θ��� ��� ����� ������ �� ����
	new_node->link = NULL; // ���θ��� ��� link���� NULL

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

void add_poly(List* P1, List* P2, List* P3) // P1���׽İ� P2���׽��� ���ؼ� P3�� ����
{
	Node* p1 = P1->head; // ù��° ���׽�
	Node* p2 = P2->head; // �ι�° ���׽�
	int sum;

	while (p1 && p2) // p1���� p2��尡 �ִµ���
	{
		if (p1->expo == p2->expo) // ������ ������
		{
			sum = p1->coef + p2->coef;
			insert_node(P3, sum, p1->expo);
			p1 = p1->link;
			p2 = p2->link;
		}

		else if (p1->expo > p2->expo) // p1�� ������ Ŭ��
		{
			insert_node(P3, p1->coef, p1->expo);
			p1 = p1->link;
		}

		else // p2�� ������ Ŭ��
		{
			insert_node(P3, p2->coef, p2->expo);
			p2 = p2->link;
		}
	}

	for (; p1 != NULL; p1 = p1->link) // ������ �����
		insert_node(P3, p1->coef, p1->expo);

	for (; p2 != NULL; p2 = p2->link) // ������ �����
		insert_node(P3, p2->coef, p2->expo);
}

void print_poly(List* list, FILE* out) // ���׽� ���
{
	Node* print_node = list->head;

	while (print_node != NULL)
	{
		fprintf(out, "%d %d ", print_node->coef, print_node->expo);
		print_node = print_node->link;
	}
	fprintf(out, "\n");
}

void delete_poly(List* list, int expo) // ���׽� ����
{
	Node* now_node;

	now_node = list->head; // �Ǿ� ��带 ����Ŵ

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

	List *P1 = create_list(); // P1 ����
	List *total = create_list(); // P1 �����ϱ� ����
	List *Temp = create_list(); // add_poly��������

	char c1 = '\n'; // ���� ����
	char c2; // ���� ����
	char temp; // \n���� ����
	int coef; // ���
	int expo; // ����

	for (int i = 0; i < 2; i++) {
		while (1) {
			if (fscanf(inp, "%d %d", &coef, &expo))		fscanf(inp, "%c", &c1);
			else if (c1 == '\n' || c1 == ' ') break;
			add_Node(P1, coef, expo);
		}

		fscanf(inp, "%c", &c1);

		if (c1 == 'I')
		{
			fscanf(inp, "%c", &c2); // \n�޴¿�
			for (;;)
			{
				fscanf(inp, "%d %d%c", &coef, &expo, &c1);
				insert_node(P1, coef, expo);

				if (c1 == '\n') 	break;
			}
		}
		else if (c1 == 'D')
		{
			fscanf(inp, "%c", &c2); // \n�޴¿�
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