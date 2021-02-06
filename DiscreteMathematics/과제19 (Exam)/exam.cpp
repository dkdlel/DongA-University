#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ifstream inp("exam.inp");
ofstream out("exam.out");

int total_num, qurey;
string good_string, case_string, check_string;


bool check_questionmark(int j) {

	for (int i = 0; i < good_string.length(); i++) {
		if (check_string[j] == good_string[i]) { // ������ ������
			return true;
		}
	}
	return false; // ������ ������
}

bool check_questionmark_2(int end_num) {

	for (int i = check_string.length() - 1; i > end_num; i--) {
		for (int j = 0; j < good_string.length(); j++) {
			if (check_string[i] == good_string[j]) { // ������ ������
				return true;
			}
		}
	}
	return false; // ������ ������
}

bool check_starmark(int start_num, int end_num) {
	for (int i = case_string.length() - 1; i > start_num; i--) {
		if (case_string[i] == '?') {
			if (!check_questionmark_2(end_num)) // ? �κ��� Ʋ���� ��
				return false;
		}
	}
}

bool check() {

	for (int j = 0; j < case_string.length(); j++) {
		if (case_string[j] == '?') {
			if (!check_questionmark(j)) // ? �κ��� Ʋ���� ��
				return false;
		}
		else if (case_string[j] == '*') {
			int starlength = check_string.length() - case_string.length() + 1;
			int cnt = 0;
			// *�� �� ���� ��
			for (int i = j; i < j + starlength; i++) { // * �ȿ� ��
				for (int k = 0; k < good_string.length(); k++) {
					if (check_string[i] == good_string[k]) { // ������ cnt++
						cnt++;
						break;
					}
				}
			}
			if (starlength != 0 && cnt == starlength) // * �ȿ� ���ڳ������ ���� ���ڿ� �ȿ� �� ���� ��
				return false;
			//case_string�̶� check_string ���� ������
			check_string.erase(j, starlength); // �迭�� ��  �����
			check_string.insert(j, "*"); // �迭�� * ����
		}
		else if (case_string[j] != check_string[j]) // �� ���ڰ� �ٸ���
			return false;
	}
	return true; // *����, ?���� �����ϸ�
}

int main() {

	inp >> total_num;
	for (int t = 0; t < total_num; t++) {

		inp >> good_string >> case_string >> qurey;
		out << "Test Case: #" << t + 1 << endl;
		for (int i = 0; i < qurey; i++) {
			inp >> check_string;
			if (check())
				out << "Yes" << endl;
			else
				out << "No" << endl;
		}
	}

	inp.close();
	out.close();
	return 0;
}