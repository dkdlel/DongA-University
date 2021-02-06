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
		if (check_string[j] == good_string[i]) { // 같은게 있으면
			return true;
		}
	}
	return false; // 같은거 없으면
}

bool check_questionmark_2(int end_num) {

	for (int i = check_string.length() - 1; i > end_num; i--) {
		for (int j = 0; j < good_string.length(); j++) {
			if (check_string[i] == good_string[j]) { // 같은게 있으면
				return true;
			}
		}
	}
	return false; // 같은거 없으면
}

bool check_starmark(int start_num, int end_num) {
	for (int i = case_string.length() - 1; i > start_num; i--) {
		if (case_string[i] == '?') {
			if (!check_questionmark_2(end_num)) // ? 부분이 틀렸을 때
				return false;
		}
	}
}

bool check() {

	for (int j = 0; j < case_string.length(); j++) {
		if (case_string[j] == '?') {
			if (!check_questionmark(j)) // ? 부분이 틀렸을 때
				return false;
		}
		else if (case_string[j] == '*') {
			int starlength = check_string.length() - case_string.length() + 1;
			int cnt = 0;
			// *에 들어갈 내용 비교
			for (int i = j; i < j + starlength; i++) { // * 안에 비교
				for (int k = 0; k < good_string.length(); k++) {
					if (check_string[i] == good_string[k]) { // 같으면 cnt++
						cnt++;
						break;
					}
				}
			}
			if (starlength != 0 && cnt == starlength) // * 안에 문자내용들이 좋은 문자열 안에 다 있을 때
				return false;
			//case_string이랑 check_string 길이 같게함
			check_string.erase(j, starlength); // 배열에 값  지우기
			check_string.insert(j, "*"); // 배열에 * 삽입
		}
		else if (case_string[j] != check_string[j]) // 두 문자가 다르면
			return false;
	}
	return true; // *없고, ?들이 성립하면
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