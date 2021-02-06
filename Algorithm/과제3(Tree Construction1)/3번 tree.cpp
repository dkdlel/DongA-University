//#include<bits/stdc++.h>
//using namespace std;
//
//ifstream fcin("tree.inp");
//ofstream fcout("tree.out");
//
//string str;
//
//class Tree {
//public:
//	void Preorder();
//	void Inorder();
//};
//void Tree::Preorder() {
//	fcout << "Preorder\n";
//	int preorder_idx = 0;
//	for (int i = 0; i < str.size(); i++) {
//		if (str[i] == ' ' || str[i] == ')' || (str[i] >= '0' && str[i] <= '9')) continue; // 필요없는 문자들
//		else if (str[i] == '(') fcout << 'r' << preorder_idx++ << '\n'; // 여는 괄호 일때
//		else {
//			string tmp = "";
//			for (int j = i + 1; ; j++) {
//				if (str[j] == ' ') break;
//				tmp += str[j];
//			}
//			fcout << str[i] << tmp << '\n'; // 트리 단말 문자 일때
//		}
//	}
//}
//void Tree::Inorder() {
//	fcout << "Inorder\n";
//	stack<int> stack;
//	bool flag = true;
//	int inorder_idx = 0;
//	for (int i = 0; i < str.size(); i++) {
//		if (str[i] == ' ' || str[i] == ')' || (str[i] >= '0' && str[i] <= '9')) continue;
//		else if (str[i] == '(') stack.push(inorder_idx++);
//		else{
//			string tmp = "";
//			for (int j = i + 1; ; j++) {
//				if (str[j] == ' ') break;
//				tmp += str[j];
//			}
//			fcout << str[i] << tmp << '\n';
//			if (!stack.empty()) {
//				fcout << 'r' << stack.top() << '\n';
//				stack.pop();
//			}
//		}
//	}
//}
//int main() {
//
//	Tree tree;
//
//	int total_num;
//	fcin >> total_num;
//	fcin.ignore(); // fcin 버퍼 제거
//	for (int i = 0; i < total_num; i++) {
//		getline(fcin, str);
//		fcout << str << '\n';
//		tree.Preorder();
//		tree.Inorder();
//	}
//
//	return 0;
//}

#include<fstream>
#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main()
{

	ifstream inp("tree.inp");
	ofstream out("tree.out");

	int testcase, i; // 전체 경우의수
	int root; // 루트 번호
	string str; // 입력 받을 문자열
	stack<int> st; // inorder에 쓰기 위한 스택
	inp >> testcase;
	inp.ignore(); // getline의 쓰레기값을 무시하기 위해서
	for (i = 0; i < testcase; i++)
	{
		getline(inp, str); // 한줄 입력 받기
		out << str << '\n';
		// preorder
		root = 0;
		out << "Preorder\n";
		for (int j = 0; j < str.size(); j++)
		{
			if (str[j] == '(') // 여는 괄호를 만날때 root번호를 출력ㅇ
			{
				out << 'r' << root << '\n';
				root++;
			}
			else if (str[j] >= 'A' && str[j] <= 'Z')
			{
				string num = ""; // 알파벳 뒤에 숫자를 출력하기 위해 저장
				for (int k = j + 1; str[k] != ' '; k++)
				{
					num = num + str[k];
				}
				out << str[j] << num << '\n';
			}
		}
		// inorder
		root = 0;
		out << "Inorder\n";
		for(int j = 0 ; j< str.size() ; j++)
		{
			if (str[j] == '(') // 여는 괄호 일때 스택에 저장
			{
				st.push(root);
				root++;
			}
			else if (str[j] >= 'A' && str[j] <= 'Z')
			{
				string num = ""; // 알파벳 뒤에 숫자를 출력하기 위해 저장
				for (int k = j + 1; str[k] != ' '; k++)
				{
					num = num + str[k];
				}
				out << str[j] << num << '\n';
				if (!st.empty()) // 스택이 비어있지 않을 때만 출력
				{
					out << 'r' << st.top() << '\n';
					st.pop();
				}
			}
		}
	}
	return 0;
}