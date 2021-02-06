// dfs 재귀, stack 미사용
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

	//방문한거는 방문하지 말자
	if (visited[root]) return;
	// 방문
	visited[root] = true;

	// 인접한 노드를 방문
	for (int i = 0; i < graph[root].size(); i++) {
		int x = graph[root][i];
		// 방문 안했으면
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
		// 루트 구하기
		root = ((check_num*(check_num + 1)) / 2 ) - S_sum;
		// 연산
		family(root);
		// 오름차순으로 정렬
		sort(result, result + check_num +1, desc);
		// 정렬된것중 가장 큰값에 1 더해서 출력
		fcout << result[0] + 1 << endl;
		// 초기화
		memset(visited, false, sizeof(visited));
		memset(result, 0, sizeof(result));
		graph.clear();
	}

	fcin.close();
	fcout.close();
	return 0;
}





/* dfs 재귀, stack 사용

#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <vector>
using namespace std;

FILE *inp = fopen("family.inp","rt");
FILE *out = fopen("family.out", "wt");

// 2차원 벡터(배열) 선언
vector < vector <int> > matrix;
// 스택 선언
stack <int> Stack;
int T; // T : 전체 경우의수
int a,b, MAX; // a,b 는 들어오는 정점
long long int root, sum, N; // N : 들어올 정점의 갯수
int Visit[500000] = { 0, };

void dfs(int root) {

// 방문 한거면 방문 안할래
if (Visit[root])	return;

Visit[root] = 1;

// 인접한 노드를 방문
for (int i = 0; i < matrix[root].size(); i++) {
int x = matrix[root][i];
// 방문 안했으면
if (!Visit[x]) {
// 스택에 push
Stack.push(x);
// 새로 들어 오는 애가 더 자식인가?
if (MAX < Stack.size()) MAX = Stack.size();
dfs(x);
}
// 아니면 그수 pop
Stack.pop();
}
}

int main() {

fscanf(inp, "%d", &T);
while (T--) {
// 초기화
sum = 0; MAX = 0;
fscanf(inp, "%lld", &N);
// 이만큼 쓰겠습니다~
matrix.resize(N + 1);
// 입력
for (int i = 1; i < N; i++) {
fscanf(inp, "%d %d", &a, &b);
// 2차원 배열 구현
matrix[a].push_back(b);
// 루트를 구하기 위해 오른쪽에 입력된 수들의 합 구하기
sum = sum + b;
}
// 루트 구하기 (입력된 정점의 수까지의 합  - 오른쪽 수의 합)
root = ((N*(N + 1)) / 2) - sum;
// dfs로 탐색 시작
dfs(root);
// +1 하는 이유는 정점의 수는 간선의 수보다 1이 커서
fprintf(out, "%d\n", MAX + 1);
// visited 배열 초기화
for (int j = 0; j < N+1; j++)
Visit[j] = 0;

matrix.clear();
}

fclose(inp);
fclose(out);
return 0;
}


*/

/* dfs 스택 구현
#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <vector>
using namespace std;

FILE *inp = fopen("family.inp","rt");
FILE *out = fopen("family.out", "wt");

// 2차원 벡터(배열) 선언
vector < vector <int> > matrix;
// 스택 선언
stack <int> Stack;
int T; // T : 전체 경우의수
int a,b, MAX; // a,b 는 들어오는 정점
long long int root, sum, N; // N : 들어올 정점의 갯수
int Visit[500000] = { 0, };

void dfs(int start, int n) {
int cnt = 0; int dir = 0; // dir : 밑으로 내려가냐(0), 올러오냐(1)
Visit[start] = 1, Stack.push(start); // 시작점 방문하고 스택에 저장

for (int i = start, j = 0;; j++) {

if (matrix[i].size()) { // 자식이 존재 하면
if (Visit[matrix[i][j]] == 0) { // 방문하지 않았다면
Visit[matrix[i][j]] = 1;      //정점 방문
Stack.push(matrix[i][j]);   //스택에 방문한 정점 저장
i = matrix[i][j];
j = -1;
dir = 0;
cnt++;
// family 문제풀기 위함
if (MAX < Stack.size()) MAX = Stack.size();
}
// 자식이 없다면
else {
// 자식이 한명일 때
if (j == matrix[i].size() - 1) {
Stack.pop();
i = Stack.top();
j = -1;
}
// 내려가냐
if (dir = 1)
continue;
// 올라가냐
else
j--;
}
}
// 자식이 없으면
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
// 초기화
sum = 0; MAX = 0;
fscanf(inp, "%lld", &N);
// 이만큼 쓰겠습니다~
matrix.resize(N + 1);
// 입력
for (int i = 1; i < N; i++) {
fscanf(inp, "%d %d", &a, &b);
// 2차원 배열 구현
matrix[a].push_back(b);
// 루트를 구하기 위해 오른쪽에 입력된 수들의 합 구하기
sum = sum + b;
}
// 루트 구하기 (입력된 정점의 수까지의 합  - 오른쪽 수의 합)
root = ((N*(N + 1)) / 2) - sum;
// dfs로 탐색 시작
dfs(root, N);
// +1 하는 이유는 정점의 수는 간선의 수보다 1이 커서
fprintf(out, "%d\n", MAX);
// visited 배열 초기화
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