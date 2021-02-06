#include <bits/stdc++.h>
using namespace std;

string str; // 초기 입력 식
int index = 0; // 해당 식의 인덱스
bool Expr();

bool isdigit() { // 숫자 판단
	if (str[index] >= '0' && str[index] <= '9') return true;
	else return false;
}

bool isid() { // 소문자 판단
	if (str[index] >= 'a' && str[index] <= 'z') return true;
	else return false;
}

bool isID() { // 대문자 판단
	if (str[index] >= 'A' && str[index] <= 'Z') return true;
	else return false;
}

bool Factor() { // Factor -> num / id / ( Expr )
	if (str[index] == '(') {
		index++; // word <- nextword
		if (Expr() == false) return false;
		else if (str[index] != ')')	return false;
	}
	else if (str[index] == ' ') { // 공백일 경우
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
	else if (str[index] == ' ') { // 공백일 경우
		index++; // word <- nextword
		return TPrime();
	}
	// TPrime -> 아무것도아님
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
	else if (str[index] == ' ') { // 공백일 경우
		index++; // word <- nextword
		return EPrime();
	}
	// EPrime -> 아무것도 아님
	return true;
}

bool Expr() { // Expr -> Term / EPrime
	if (Term() == false) return false;
	else return EPrime();
}

int main() {

	getline(cin, str);

	if (Expr() == true) {
		if(index < str.size()) cout << "Error\n"; // 전부 true지만 입력 string을 다 읽지 않았을 경우
		else cout << "Good\n";
	}
	else cout << "Error\n"; // 구문 오류
	return 0;
}