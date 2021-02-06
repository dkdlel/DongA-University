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
//		if (str[i] == ' ' || str[i] == ')' || (str[i] >= '0' && str[i] <= '9')) continue; // �ʿ���� ���ڵ�
//		else if (str[i] == '(') fcout << 'r' << preorder_idx++ << '\n'; // ���� ��ȣ �϶�
//		else {
//			string tmp = "";
//			for (int j = i + 1; ; j++) {
//				if (str[j] == ' ') break;
//				tmp += str[j];
//			}
//			fcout << str[i] << tmp << '\n'; // Ʈ�� �ܸ� ���� �϶�
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
//	fcin.ignore(); // fcin ���� ����
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

	int testcase, i; // ��ü ����Ǽ�
	int root; // ��Ʈ ��ȣ
	string str; // �Է� ���� ���ڿ�
	stack<int> st; // inorder�� ���� ���� ����
	inp >> testcase;
	inp.ignore(); // getline�� �����Ⱚ�� �����ϱ� ���ؼ�
	for (i = 0; i < testcase; i++)
	{
		getline(inp, str); // ���� �Է� �ޱ�
		out << str << '\n';
		// preorder
		root = 0;
		out << "Preorder\n";
		for (int j = 0; j < str.size(); j++)
		{
			if (str[j] == '(') // ���� ��ȣ�� ������ root��ȣ�� ��¤�
			{
				out << 'r' << root << '\n';
				root++;
			}
			else if (str[j] >= 'A' && str[j] <= 'Z')
			{
				string num = ""; // ���ĺ� �ڿ� ���ڸ� ����ϱ� ���� ����
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
			if (str[j] == '(') // ���� ��ȣ �϶� ���ÿ� ����
			{
				st.push(root);
				root++;
			}
			else if (str[j] >= 'A' && str[j] <= 'Z')
			{
				string num = ""; // ���ĺ� �ڿ� ���ڸ� ����ϱ� ���� ����
				for (int k = j + 1; str[k] != ' '; k++)
				{
					num = num + str[k];
				}
				out << str[j] << num << '\n';
				if (!st.empty()) // ������ ������� ���� ���� ���
				{
					out << 'r' << st.top() << '\n';
					st.pop();
				}
			}
		}
	}
	return 0;
}