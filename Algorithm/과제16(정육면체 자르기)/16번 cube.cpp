#include<bits/stdc++.h>
#define MAX 201
#define INF 999999999
using namespace std;

ifstream fcin("cube.inp");
ofstream fcout("cube.out");
int wood[MAX][MAX][MAX];

class Cube {
public:
	int testcase, W, L, H; // W: ����, L: ����, H: ����
	void Sol();
};
void Cube::Sol() {
	//�ʱ�ȭ
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			for (int k = 0; k < MAX; k++) {
				wood[i][j][k] = INF;
			}
		}
	}

	for (int i = 1; i < MAX; i++) {
		for (int j = i; j < MAX; j++) {
			for (int k = j; k < MAX; k++) {
				if (i == j && j == k) wood[i][j][k] = 1; // ������ü �϶�
				else {
					for (int l = 1; l < i / 2 + 1; l++)  // �� �ɰ��� �ݴ��� �ݰ� ����� ���� ������ ex) 15 5 5�ΰ�� 7 5 5 �� 8 5 5�� ������ü ������ ����
						wood[i][j][k] = min(wood[i][j][k], wood[l][j][k] + wood[i - l][j][k]);
					for (int l = 1; l < j / 2 + 1; l++)
						wood[i][j][k] = min(wood[i][j][k], wood[i][l][k] + wood[i][j - l][k]);
					for (int l = 1; l < k / 2 + 1; l++)
						wood[i][j][k] = min(wood[i][j][k], wood[i][j][l] + wood[i][j][k - l]);			
				}
				wood[i][k][j] = wood[j][i][k] = wood[j][k][i] = wood[k][i][j] = wood[k][j][i] = wood[i][j][k]; // 1 1 2 ��갪�� 1 2 1, 2 1 1����� ���� ���� ������
			}
		}
	}

}
int main() {

	Cube cube;
	cube.Sol();
	fcin >> cube.testcase;
	while (cube.testcase--) {
		fcin >> cube.W >> cube.L >> cube.H;
		fcout << wood[cube.W][cube.L][cube.H] << '\n';
	}
	return 0;
}