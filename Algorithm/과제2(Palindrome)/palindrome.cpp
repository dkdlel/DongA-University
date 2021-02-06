//#include<bits/stdc++.h>
//using namespace std;
//
//ifstream fcin("palindrome.inp");
//ofstream fcout("palindrome.out");
//
//class Palindrome {
//public:
//	string ori_str, reverse_str;
//	int lcs[1001][1001];
//	void Input();
//	void Cal_Pali();
//};
//void Palindrome::Input() {
//	string tmp;
//	fcin >> tmp;
//	for (int i = tmp.size()-1; i >= 0; i--) reverse_str += tmp[i];
//	ori_str = '0' + tmp;
//}
//void Palindrome::Cal_Pali() {
//	for (int i = 0; i < ori_str.size(); i++) {
//		for (int j = 0; j < reverse_str.size(); j++) {
//			if (i == 0 || j == 0) {
//				lcs[i][j] = 0;
//				continue;
//			}
//			if (ori_str[i] == reverse_str[j]) { // 같은 문자열이면
//				lcs[i][j] = lcs[i - 1][j - 1] + 1;
//			}
//			else {
//				int large_lcs;
//				large_lcs = lcs[i - 1][j] > lcs[i][j - 1] ? lcs[i - 1][j] : lcs[i][j - 1];
//				lcs[i][j] = large_lcs;
//			}
//		}
//	}
//	fcout << ori_str.size() - lcs[ori_str.size() - 1][reverse_str.size() - 1] << "\n";
//}
//int main() {
//
//	Palindrome pali;
//	int case_num;
//	fcin >> case_num;
//
//	for (int i = 0; i < case_num; i++) {
//		pali.reverse_str = '0';
//		pali.Input();
//		pali.Cal_Pali();
//	}
//
//	return 0;
//}

#include<bits/stdc++.h>
using namespace std;

ifstream fcin("palindrome.inp");
ofstream fcout("palindrome.out");

string ori_str, reverse_str;
int lcs[1001][1001];
int result;

void Input() {
	string tmp;
	fcin >> tmp;
	for (int i = tmp.size() - 1; i >= 0; i--) reverse_str += tmp[i];
	ori_str = '0' + tmp;
}
void Cal_Pali() {
	for (int i = 0; i < ori_str.size(); i++) {
		for (int j = 0; j < reverse_str.size(); j++) {
			if (i == 0 || j == 0) {
				lcs[i][j] = 0;
				continue;
			}
			if (ori_str[i] == reverse_str[j]) { // 같은 문자열이면
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
			}
			else {
				int large_lcs;
				large_lcs = lcs[i - 1][j] > lcs[i][j - 1] ? lcs[i - 1][j] : lcs[i][j - 1];
				lcs[i][j] = large_lcs;
			}
		}
	}
	if (ori_str.size() - lcs[ori_str.size() - 1][reverse_str.size() - 1] - 1 >= 3) result = -1;
	else result = ori_str.size() - lcs[ori_str.size() - 1][reverse_str.size() - 1] - 1;
	fcout << result << "\n";
}
int main() {

	int case_num;
	fcin >> case_num;

	for (int i = 0; i < case_num; i++) {
		reverse_str = '0';
		Input();
		Cal_Pali();
	}

	return 0;
}

//#include<stdio.h>
//#include<string.h>
//int main()
//
//{
//
//	FILE* inp = fopen("tree.inp", "rt");//파일 선언
//	FILE* out = fopen("tree.out", "wt");
//
//	char str[1001];
//	char tmp[1001];//뒤집을 배열
//	int testcase, i, j;//돌림횟수 선언
//	int sujin[1001][1001];
//	int len = 0;//총길이
//	int result; // 최종결과
//	fscanf(inp, "%d", &testcase);
//
//
//
//	for (i = 0; i < testcase; i++)
//	{
//		memset(sujin, 0, sizeof(sujin));//배열을 0으로 초기화시킨다.
//		len = 0;
//		fscanf(inp, "%s", str);
//
//		for (j = 0; j < 1001; j++)
//		{
//			if (str[j] == '\0')
//				break;
//
//			else {
//				len++;
//			}
//
//		}//길이를 찾는 소스
//
//		int idx = 0;
//		for (j = len - 1; j >= 0; j--)
//		{
//			tmp[idx++] = str[j];
//		}//뒤집어서 들어가짐
//
//
//		for (int i = len; i >= 0; i--) { // 맨앞에 0 추가
//			str[i + 1] = str[i];
//			tmp[i + 1] = tmp[i];
//		}
//		str[0] = tmp[0] = '0';
//
//		for (int i = 0; i <= len; i++)
//		{
//			for (int j = 0; j <= len; j++)
//			{
//
//				if (i == 0 || j == 0) {
//					sujin[i][j] = 0;
//					continue;
//				}
//				if (str[i] == tmp[j])
//				{
//					sujin[i][j] = sujin[i - 1][j - 1] + 1;
//
//				}
//				else
//				{
//					if (sujin[i - 1][j] > sujin[i][j - 1])
//						sujin[i][j] = sujin[i - 1][j];
//					else
//						sujin[i][j] = sujin[i][j - 1];
//				}
//			}
//		}
//
//		if (len - sujin[len][len] >= 3)
//			result = -1;
//		else
//			result = len - sujin[len][len];
//
//		fprintf(out, "%d\n", result);
//
//	}
//	fclose(inp);
//	fclose(out);
//	return 0;
//
//}