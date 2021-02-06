// dfs ���, stack �̻��
#include <fstream>
#include <vector>
#include <algorithm>
#include <string.h>
#define MAX 500000
using namespace std;

ifstream fcin("family.inp");
ofstream fcout("family.out");

int total_num, predecessor, successor;
long long int root, S_sum, check_num;
int result[MAX];
vector < vector <int> > graph;
bool visited[MAX] = { false, };
int cnt = 0;


bool desc(int a, int b) {
	return a > b;
}

void family(int root) {

	//�湮�ѰŴ� �湮���� ����
	if (visited[root]) return;
	// �湮
	visited[root] = true;

	// ������ ��带 �湮
	for (int i = 0; i < graph[root].size(); i++) {
		int x = graph[root][i];
		// �湮 ��������
		if (!visited[x]) {
			result[x] = result[root] + 1;
			family(x);
		}
	}
}

int main() {

	fcin >> total_num;
	
	for (int T = 0; T < total_num; T++) {
		S_sum = 0;
		fcin >> check_num;
		graph.resize(check_num+1);

		for (int i = 1; i < check_num; i++) {
			fcin >> predecessor >> successor;
			graph[predecessor].push_back(successor);
			S_sum += successor;
		}
		// ��Ʈ ���ϱ�
		root = ((check_num*(check_num + 1)) / 2 ) - S_sum;
		// ����
		family(root);
		// ������������ ����
		sort(result, result + check_num +1, desc);
		// ���ĵȰ��� ���� ū���� 1 ���ؼ� ���
		fcout << result[0] + 1 << endl;
		// �ʱ�ȭ
		memset(visited, false, sizeof(visited));
		memset(result, 0, sizeof(result));
		graph.clear();
	}

	fcin.close();
	fcout.close();
	return 0;
}





/* dfs ���, stack ���

#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <vector>
using namespace std;

FILE *inp = fopen("family.inp","rt");
FILE *out = fopen("family.out", "wt");

// 2���� ����(�迭) ����
vector < vector <int> > matrix;
// ���� ����
stack <int> Stack;
int T; // T : ��ü ����Ǽ�
int a,b, MAX; // a,b �� ������ ����
long long int root, sum, N; // N : ���� ������ ����
int Visit[500000] = { 0, };

void dfs(int root) {

// �湮 �ѰŸ� �湮 ���ҷ�
if (Visit[root])	return;

Visit[root] = 1;

// ������ ��带 �湮
for (int i = 0; i < matrix[root].size(); i++) {
int x = matrix[root][i];
// �湮 ��������
if (!Visit[x]) {
// ���ÿ� push
Stack.push(x);
// ���� ��� ���� �ְ� �� �ڽ��ΰ�?
if (MAX < Stack.size()) MAX = Stack.size();
dfs(x);
}
// �ƴϸ� �׼� pop
Stack.pop();
}
}

int main() {

fscanf(inp, "%d", &T);
while (T--) {
// �ʱ�ȭ
sum = 0; MAX = 0;
fscanf(inp, "%lld", &N);
// �̸�ŭ ���ڽ��ϴ�~
matrix.resize(N + 1);
// �Է�
for (int i = 1; i < N; i++) {
fscanf(inp, "%d %d", &a, &b);
// 2���� �迭 ����
matrix[a].push_back(b);
// ��Ʈ�� ���ϱ� ���� �����ʿ� �Էµ� ������ �� ���ϱ�
sum = sum + b;
}
// ��Ʈ ���ϱ� (�Էµ� ������ �������� ��  - ������ ���� ��)
root = ((N*(N + 1)) / 2) - sum;
// dfs�� Ž�� ����
dfs(root);
// +1 �ϴ� ������ ������ ���� ������ ������ 1�� Ŀ��
fprintf(out, "%d\n", MAX + 1);
// visited �迭 �ʱ�ȭ
for (int j = 0; j < N+1; j++)
Visit[j] = 0;

matrix.clear();
}

fclose(inp);
fclose(out);
return 0;
}


*/

/* dfs ���� ����
#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <vector>
using namespace std;

FILE *inp = fopen("family.inp","rt");
FILE *out = fopen("family.out", "wt");

// 2���� ����(�迭) ����
vector < vector <int> > matrix;
// ���� ����
stack <int> Stack;
int T; // T : ��ü ����Ǽ�
int a,b, MAX; // a,b �� ������ ����
long long int root, sum, N; // N : ���� ������ ����
int Visit[500000] = { 0, };

void dfs(int start, int n) {
int cnt = 0; int dir = 0; // dir : ������ ��������(0), �÷�����(1)
Visit[start] = 1, Stack.push(start); // ������ �湮�ϰ� ���ÿ� ����

for (int i = start, j = 0;; j++) {

if (matrix[i].size()) { // �ڽ��� ���� �ϸ�
if (Visit[matrix[i][j]] == 0) { // �湮���� �ʾҴٸ�
Visit[matrix[i][j]] = 1;      //���� �湮
Stack.push(matrix[i][j]);   //���ÿ� �湮�� ���� ����
i = matrix[i][j];
j = -1;
dir = 0;
cnt++;
// family ����Ǯ�� ����
if (MAX < Stack.size()) MAX = Stack.size();
}
// �ڽ��� ���ٸ�
else {
// �ڽ��� �Ѹ��� ��
if (j == matrix[i].size() - 1) {
Stack.pop();
i = Stack.top();
j = -1;
}
// ��������
if (dir = 1)
continue;
// �ö󰡳�
else
j--;
}
}
// �ڽ��� ������
else {
Stack.pop();
i = Stack.top();
j--;
dir = 1;
}

if (cnt == n - 1) 	break;
}
}


int main() {

fscanf(inp, "%d", &T);
while (T--) {
// �ʱ�ȭ
sum = 0; MAX = 0;
fscanf(inp, "%lld", &N);
// �̸�ŭ ���ڽ��ϴ�~
matrix.resize(N + 1);
// �Է�
for (int i = 1; i < N; i++) {
fscanf(inp, "%d %d", &a, &b);
// 2���� �迭 ����
matrix[a].push_back(b);
// ��Ʈ�� ���ϱ� ���� �����ʿ� �Էµ� ������ �� ���ϱ�
sum = sum + b;
}
// ��Ʈ ���ϱ� (�Էµ� ������ �������� ��  - ������ ���� ��)
root = ((N*(N + 1)) / 2) - sum;
// dfs�� Ž�� ����
dfs(root, N);
// +1 �ϴ� ������ ������ ���� ������ ������ 1�� Ŀ��
fprintf(out, "%d\n", MAX);
// visited �迭 �ʱ�ȭ
for (int j = 0; j < N+1; j++)
Visit[j] = 0;
while (!Stack.empty()) Stack.pop();
matrix.clear();
}

fclose(inp);
fclose(out);
return 0;
}
*/