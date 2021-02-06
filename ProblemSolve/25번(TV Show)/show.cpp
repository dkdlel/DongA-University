//
//  show.cpp
//  ProblemSolve
//
//  Created by  JeJn on 2020/05/17.
//  Copyright © 2020  JeJn. All rights reserved.
//
//
#include<fstream>
#include<vector>
#include <stack>
#define BLUE 'B'
#define RED 'R'
using namespace std;

ifstream fcin("/Users/jejn/Desktop/ProblemSolve/ProblemSolve/show.inp");
ofstream fcout("/Users/jejn/Desktop/ProblemSolve/ProblemSolve/show.out");

typedef struct Show{
    int light;
    char color;
}Show;

vector< vector <int> > graph, reverse_graph; // graph 생성
Show choose[3]; // 참가자가 선택한 전구번호와 색
int k, n; // k : 전구의 수, n : 참가자의 수
vector <bool> visited;
stack <int> st;
vector<int> set; // scc의 집합 모음

int reverse_light(Show A){
    if(A.color == BLUE) return A.light + k;
    return A.light - k;
}
bool Check(int x, int y){ // 중복 확인
    for(int i = 0 ; i < graph[x].size() ; i++){
        if(graph[x][i] == y) return true;
    }
    return false;
}
void MakeGraph(Show A, Show B){
    int x, y, rx, ry;
    x = A.light; y = B.light; rx = reverse_light(A); ry = reverse_light(B);

    if(!Check(rx,y)){
        graph[rx].push_back(y);
        graph[ry].push_back(x);
        reverse_graph[x].push_back(ry);
        reverse_graph[y].push_back(rx);
    }
}
void Init(){
    graph.clear(); reverse_graph.clear(); visited.clear(); set.clear();
    graph.resize(2 * (k + 1)); reverse_graph.resize(2 * (k + 1)); visited.resize(2 * (k + 1)); set.resize(2 * (k + 1));
    for(int i = 0 ; i < n ; i++){
        for(int i = 0 ; i < 3 ; i++){
            int num; char ch;
            fcin >> num >> ch;
            if(ch == RED) num += k;
            choose[i].light = num; choose[i].color = ch;
        }
        MakeGraph(choose[0],choose[1]);
        MakeGraph(choose[1],choose[2]);
        MakeGraph(choose[2],choose[0]);
    }
}
void dfs(int cur){
    visited[cur] = true;
    for(int i = 0 ; i < graph[cur].size() ; i++){
        int next = graph[cur][i];
        if(!visited[next]) dfs(next);
    }
    st.push(cur);
}
void reverse_dfs(int cur, int set_num){
    visited[cur] = true;
    set[cur] = set_num;
    for(int i = 0 ; i < reverse_graph[cur].size() ; i++){
        int next = reverse_graph[cur][i];
        if(!visited[next]) reverse_dfs(next, set_num);
    }
}
void GetResult(){
    for(int i = 1 ; i <= k ; i++){
        if(set[i] == set[i+k]){
            fcout << "-1\n"; return;
        }
    }
    fcout << "1\n";
}
int main(){

    int testcase;
    fcin >> testcase;

    while(testcase--){
        fcin >> k >> n;
        Init();
        for(int i = 1 ; i <= 2 * k ; i++) if(!visited[i]) dfs(i);
        visited.assign(2 * (k + 1), false);
        int set_num = 1;
        while(!st.empty()){
            int cur = st.top(); st.pop();
            if(visited[cur]) continue; // 이미 방문한 정점
            reverse_dfs(cur, set_num++);
        }
        GetResult();
    }
    return 0;
}
