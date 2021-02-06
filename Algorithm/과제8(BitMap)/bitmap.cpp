//#include<bits/stdc++.h>
//#define MAX 201
//using namespace std;
//
//ifstream fcin("bitmap.inp");
//ofstream fcout("bitmap.out");
//
//class Bitmap {
//private:
//	int str_idx;
//public:
//	int row, col;
//	string str, result, input;
//	vector < vector <char> > bitmap;
//	void Input();
//	void Set_B();
//	void Sol_B(int srow, int scol, int erow, int ecol);
//	bool IsSame(int srow, int scol, int erow, int ecol);
//	void Set_D();
//	void Sol_D(int srow, int scol, int erow, int ecol);
//	void Fill(int srow, int scol, int erow, int ecol);
//};
//void Bitmap::Input() {
//	str = "";
//	fcin >> row >> col;
//	while (1) {
//		fcin >> input;
//		if (input[0] == 'B' || input[0] == 'D' || input[0] == '#') {
//			if(input.size() == 1) break; // B D하나만 있을때 D가 연속으로 들어오는 경우를 방지
//		}
//		str += input;
//	}
//}
//void Bitmap::Set_B() { // 입력 부분
//	bitmap.clear();
//	result = "";
//	str_idx = 0;
//	for (int i = 0; i < row; i++) {
//		bitmap.resize(row);
//		for (int j = 0; j < col; j++) {
//			bitmap[i].resize(col);
//			bitmap[i][j] = str[str_idx++];
//		}
//	}
//	Sol_B(0, 0, row, col);
//	fcout << "D " << row << ' ' << col;
//	for (int i = 0; i < result.size(); i++) {
//		if (i % 50 == 0) fcout << '\n';
//		fcout << result[i];
//	}
//	fcout << '\n';
//}
//bool Bitmap::IsSame(int srow, int scol, int erow, int ecol) { // 분할된 부분에 숫자들이 다 같으면
//	char symbol = bitmap[srow][scol];
//	for (int i = srow; i < erow; i++) {
//		for (int j = scol; j < ecol; j++) {
//			if (symbol != bitmap[i][j]) return false;
//		}
//	}
//	return true;
//}
//void Bitmap::Sol_B(int srow, int scol, int erow, int ecol) {
//	// srow : strat_row , erow : end_row
//	if (srow == erow || scol == ecol) // 끝인덱스를 만나면
//		return;
//	if (IsSame(srow, scol, erow, ecol)) {
//		result += bitmap[srow][scol];
//		return;
//	}
//	result += 'D';
//	int mrow = (srow + erow + 1) / 2; // mrow : mid_row
//	int mcol = (scol + ecol + 1) / 2;
//	Sol_B(srow, scol, mrow, mcol);
//	Sol_B(srow, mcol, mrow, ecol);
//	Sol_B(mrow, scol, erow, mcol);
//	Sol_B(mrow, mcol, erow, ecol);
//}
//void Bitmap::Set_D() {
//	bitmap.clear();
//	for (int i = 0; i < row; i++) {
//		bitmap.resize(row);
//		for (int j = 0; j < col; j++) {
//			bitmap[i].resize(col);
//		}
//	}
//	result = "";
//	str_idx = 0;
//	Sol_D(0, 0, row, col);
//	fcout << "B " << row << ' ' << col;
//	for (int i = 0; i < row; i++) {
//		for (int j = 0; j < col; j++) {
//			if (((i * col) + j) % 50 == 0) fcout << '\n';
//			fcout << bitmap[i][j];
//		}
//	}
//	fcout << '\n';
//}
//void Bitmap::Fill(int srow, int scol, int erow, int ecol) {
//	for (int i = srow; i < erow; i++) {
//		for (int j = scol; j < ecol; j++) {
//			bitmap[i][j] = str[str_idx];
//		}
//	}
//}
//void Bitmap::Sol_D(int srow, int scol, int erow, int ecol) {
//	if (srow == erow || scol == ecol) // 끝인덱스를 만나면
//		return;
//	int mrow = (srow + erow + 1) / 2; // mrow : mid_row
//	int mcol = (scol + ecol + 1) / 2;
//	if (str[str_idx] == 'D') {
//		str_idx++;
//		Sol_D(srow, scol, mrow, mcol);
//		Sol_D(srow, mcol, mrow, ecol);
//		Sol_D(mrow, scol, erow, mcol);
//		Sol_D(mrow, mcol, erow, ecol);
//	}
//	else {
//		Fill(srow, scol, erow, ecol);
//		str_idx++;
//	}
//}
//int main() {
//
//	Bitmap bit;
//	fcin >> bit.input;
//	while (1) {
//		if (bit.input[0] == '#') break;
//		char type = bit.input[0];
//		bit.Input();
//		if (type == 'B') bit.Set_B();
//		else if (type == 'D') bit.Set_D();
//	}
//
//	return 0;
//}

#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<fstream>
#pragma warning(disable:4996)
using namespace std;

ifstream inp("ladder.inp");
ofstream out("ladder.out");

int row, col, cnt;
char map[201][201];
char bit[40001];
string result;

void B_Set() {
	cnt = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			map[i][j] = bit[cnt++];
		}
	}
}
bool IsSame(int srow, int scol, int erow, int ecol) {
	char symbol = map[srow][scol];
	for (int i = srow; i < srow + erow; i++) {
		for (int j = scol; j < scol + ecol; j++) {
			if (symbol != map[i][j]) return false;
		}
	}
	return true;
}
void BtoD(int srow, int scol, int erow, int ecol) {
	if (srow == erow || scol == ecol)
		return;
	if (IsSame(srow, scol, erow, ecol)) {
		result.push_back(map[srow][scol]);
		return;
	}
	result.push_back('D');
	int mrow = (srow + erow + 1) / 2;
	int mcol = (scol + ecol + 1) / 2;
	BtoD(srow, scol, mrow, mcol);
	BtoD(srow, mcol, mrow, ecol);
	BtoD(mrow, scol, erow, mcol);
	BtoD(mrow, mcol, erow, ecol);
}
void printB() {
	for (int i = 0; i < result.size(); i++) {
		if (i % 50 == 0) out << '\n';
		out << result[i];
	}
}
void paint(int srow, int scol, int erow, int ecol) {
	for (int i = srow; i < srow + erow; i++) {
		for (int j = scol; j < scol + ecol; j++) {
			map[i][j] = bit[cnt];
		}
	}
	cnt++;
}
void DtoB(int srow, int scol, int erow, int ecol) {
	if (srow == erow || scol == ecol) // 끝인덱스를 만나면
		return;
	if (bit[cnt] != 'D') {
		paint(srow, scol, erow, ecol);
		cnt++;
		return;
	}
	int mrow = (srow + erow + 1) / 2; // mrow : mid_row
	int mcol = (scol + ecol + 1) / 2;
	cnt++;
	DtoB(srow, scol, mrow, mcol);
	DtoB(srow, mcol, mrow, ecol);
	DtoB(mrow, scol, erow, mcol);
	DtoB(mrow, mcol, erow, ecol);
}
void printD() {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (((i * col) + j) % 50 == 0) {
				out << '\n';
			}
			out << map[i][j];
		}
	}
}
int main() {

	while (1) {
		char type;
		inp >> type;
		if (type == '#') break;
		inp >> row >> col;
		if (type == 'B') {
			out << "D " << row << ' ' << col;
			for (int i = 0; i < row * col; i++) {
				inp >> bit[i];
			}
			B_Set();
			BtoD(0, 0, row, col);
			printB();
		}
		else {
			out << "B " << row << ' ' << col;
			string temp;
			for (int i = 0;; i++) {
				inp >> temp;
				for (int j = i * 50; j < i * 50 + temp.length(); j++) {
					bit[j] = temp[j % 50];
				}
				if (temp.length() != 50) {
					break;
				}
			}
			cnt = 0;
			DtoB(0, 0, row, col);
			printD();
		}

		out << '\n';
	}

	return 0;
}