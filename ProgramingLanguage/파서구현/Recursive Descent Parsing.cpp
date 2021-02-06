#include <bits/stdc++.h>
using namespace std;

string str; // �ʱ� �Է� ��
int index = 0; // �ش� ���� �ε���
bool Expr();

bool isdigit() { // ���� �Ǵ�
	if (str[index] >= '0' && str[index] <= '9') return true;
	else return false;
}

bool isid() { // �ҹ��� �Ǵ�
	if (str[index] >= 'a' && str[index] <= 'z') return true;
	else return false;
}

bool isID() { // �빮�� �Ǵ�
	if (str[index] >= 'A' && str[index] <= 'Z') return true;
	else return false;
}

bool Factor() { // Factor -> num / id / ( Expr )
	if (str[index] == '(') {
		index++; // word <- nextword
		if (Expr() == false) return false;
		else if (str[index] != ')')	return false;
	}
	else if (str[index] == ' ') { // ������ ���
		index++; // word <- nextword
		return Factor();
	}
	else if (!isdigit() && !isid() && !isID()) return false; // Factor -> number || ident
	index++; // word <- nextword
	return true;
}

bool TPrime() { // TPrime -> * , Factor , TPrime || / , Factor , TPrime
	if (str[index] == '*' || str[index] == '/') {
		index++; // word <- nextword
		if (Factor() == false) return false;
		else return TPrime();
	}
	else if (str[index] == ' ') { // ������ ���
		index++; // word <- nextword
		return TPrime();
	}
	// TPrime -> �ƹ��͵��ƴ�
	return true;
}

bool Term() { // Term -> Factor , TPrime
	if (Factor() == false) return false;
	else return TPrime();
}

bool EPrime() { // Eprime -> + , Term , EPrime || - , Term , Eprime
	if (str[index] == '+' || str[index] == '-') {
		index++; // word <- nextword
		if (Term() == false) return false;
		else return EPrime();
	}
	else if (str[index] == ' ') { // ������ ���
		index++; // word <- nextword
		return EPrime();
	}
	// EPrime -> �ƹ��͵� �ƴ�
	return true;
}

bool Expr() { // Expr -> Term / EPrime
	if (Term() == false) return false;
	else return EPrime();
}

int main() {

	getline(cin, str);

	if (Expr() == true) {
		if(index < str.size()) cout << "Error\n"; // ���� true���� �Է� string�� �� ���� �ʾ��� ���
		else cout << "Good\n";
	}
	else cout << "Error\n"; // ���� ����
	return 0;
}