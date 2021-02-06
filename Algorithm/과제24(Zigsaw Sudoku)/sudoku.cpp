#include<bits/stdc++.h>
#define len 10
using namespace std;

ifstream fcin("sudoku.inp");
ofstream fcout("sudoku.out");

typedef struct pos {
	int x, y;
};
class Sudoku {
public:
	int testcase;
	void Init();
	void Input();
	void Sol(int blank_num, int t);
	int sudoku[len][len], row[len][len], col[len][len], visited[len][len]; // sudoku : result sudoku, row, col : �ش� ���ڸ� ����ߴ��� Ȯ��, visited : zigsaw ������ ���ڸ� ����ߴ��� Ȯ��
	char zigsaw[len][len];// ������ �����ϴ� vector
	vector< pos > blank; // ��ĭ(����0)�� ��ġ�� ����
private:
	int num; char ch; // �Է¿�
};
void Sudoku::Init() {
	memset(sudoku, 0, sizeof(sudoku));
	memset(row, 0, sizeof(row));
	memset(col, 0, sizeof(col));
	memset(zigsaw, NULL, sizeof(zigsaw));
	memset(visited, 0, sizeof(visited));
	blank.clear();
}
void Sudoku::Input() {
	for (int i = 1; i < len; i++) {
		for (int j = 1; j < len; j++) {
			fcin >> num;
			if (num == 0) blank.push_back({ i,j }); // ������� ����
			else {
				sudoku[i][j] = num;
				row[i][num] = 1; // �࿡�� ���ڸ� ���
				col[j][num] = 1; // ������ ���ڸ� ���
			}
		}
	}
	for (int i = 1; i < len; i++) {
		for (int j = 1; j < len; j++) {
			fcin >> ch;
			zigsaw[i][j] = ch; // zigsaw ����
			if (sudoku[i][j] != 0) {
				visited[ch - 'a'][sudoku[i][j]] = 1; // �ش� zigsaw�� ���� ��뿩��, a�� 0���� ����
			}
		}
	}
}
void Sudoku::Sol(int blank_num, int t) {
	if (blank_num == blank.size()) {
		fcout << "Test Case No: " << t << '\n';
		for (int i = 1; i < len; i++) {
			for (int j = 1; j < len; j++) {
				fcout << sudoku[i][j] << ' ';
			}
			fcout << '\n';
		}
		fcout << '\n';
		return;
	}
	int x = blank[blank_num].x;
	int y = blank[blank_num].y;
	for (int i = 1; i < len; i++) {
		if (row[x][i] == 1 || col[y][i] == 1) continue;
		if (visited[zigsaw[x][y] - 'a'][i] == 0) {
			row[x][i] = 1;
			col[y][i] = 1;
			visited[zigsaw[x][y] - 'a'][i] = 1;
			sudoku[x][y] = i;

			Sol(blank_num + 1,t);

			sudoku[x][y] = 0;
			visited[zigsaw[x][y] - 'a'][i] = 0;
			col[y][i] = 0;
			row[x][i] = 0;
		}
	}
}
int main() {

	Sudoku su;
	fcin >> su.testcase;
	for (int t = 1; t <= su.testcase; t++) {
		su.Init();
		su.Input();
		su.Sol(0,t);
	}
	return 0;
}

/*
#include<bits/stdc++.h>
#define len 10
using namespace std;

ifstream fcin("sudoku.inp");
ofstream fcout("sudoku.out");

typedef struct pos {
   int x, y;
};
class Sudoku {
public:
   int testcase;
   void Init();
   void Input();
   void Sol(int blank_num, int t);
   int sudoku[len][len]; // sudoku : result sudoku
   bool row[len][len], col[len][len], visited[len][len]; // row, col : �ش� ���ڸ� ����ߴ��� Ȯ��, visited : zigsaw ������ ���ڸ� ����ߴ��� Ȯ��
   char zigsaw[len][len];// ������ �����ϴ� vector
   vector< pos > blank; // ��ĭ(����0)�� ��ġ�� ����
private:
   int num; char ch; // �Է¿�
};
void Sudoku::Init() {
   memset(sudoku, 0, sizeof(sudoku));
   memset(row, false, sizeof(row));
   memset(col, false, sizeof(col));
   memset(visited, false, sizeof(visited));
   memset(zigsaw, NULL, sizeof(zigsaw));
   blank.clear();
}
void Sudoku::Input() {
   for (int i = 1; i < len; i++) {
	  for (int j = 1; j < len; j++) {
		 fcin >> num;
		 if (num == 0) blank.push_back({ i,j }); // ������� ����
		 else {
			sudoku[i][j] = num;
			row[i][num] = true; // �࿡�� ���ڸ� ���
			col[j][num] = true; // ������ ���ڸ� ���
		 }
	  }
   }
   for (int i = 1; i < len; i++) {
	  for (int j = 1; j < len; j++) {
		 fcin >> ch;
		 zigsaw[i][j] = ch; // zigsaw ����
		 if (sudoku[i][j] != 0) {
			visited[ch - 'a'][sudoku[i][j]] = true; // �ش� zigsaw�� ���� ��뿩��, a�� 0���� ����
		 }
	  }
   }
}
void Sudoku::Sol(int blank_num, int t) {
   if (blank_num == blank.size()) {
	  fcout << "Test Case No: " << t << '\n';
	  for (int i = 1; i < len; i++) {
		 for (int j = 1; j < len; j++) {
			fcout << sudoku[i][j] << ' ';
		 }
		 fcout << '\n';
	  }
	  fcout << '\n';
	  return;
   }
   int x = blank[blank_num].x;
   int y = blank[blank_num].y;
   for (int i = 1; i < len; i++) {
	  if (row[x][i] || col[y][i]) continue;
	  if (!visited[zigsaw[x][y] - 'a'][i]) {
		 row[x][i] = true;
		 col[y][i] = true;
		 visited[zigsaw[x][y] - 'a'][i] = true;
		 sudoku[x][y] = i;

		 Sol(blank_num + 1,t);

		 sudoku[x][y] = 0;
		 visited[zigsaw[x][y] - 'a'][i] = false;
		 col[y][i] = false;
		 row[x][i] = false;
	  }
   }
}
int main() {

   Sudoku su;
   fcin >> su.testcase;
   for (int t = 1; t <= su.testcase; t++) {
	  su.Init();
	  su.Input();
	  su.Sol(0,t);
   }
   return 0;
}
*/