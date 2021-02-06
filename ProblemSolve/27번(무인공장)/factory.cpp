//
//  factory.cpp
//  ProblemSolve
//
//  Created by  JeJn on 2020/05/17.
//  Copyright © 2020  JeJn. All rights reserved.
//

#include<fstream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

ifstream fcin("/Users/jejn/Desktop/ProblemSolve/ProblemSolve/factory.inp");
ofstream fcout("/Users/jejn/Desktop/ProblemSolve/ProblemSolve/factory.out");

typedef struct info{
    int mno, start, day; // mno : machine num, start : 시작 시간, day : 1일차 or 2일차
}info;
bool operator <(const info &A, const info &B){
    if(A.mno == B.mno) return A.start < B.start;
    return A.start < B.start;
}

int machine, checkup; // machine : 검사 기계의 수, checkup : 검사일
vector < vector <int> > graph,reverse_graph;
vector<info> running; // 기계가 돌아가는 시간들의 모음
vector <bool> visited;
stack <int> st;
vector<int> set; // scc의 집합 모음
int idx1,idx2;

void init(){
    running.clear(); graph.clear(); reverse_graph.clear(); visited.clear(); set.clear();
    fcin >> machine >> checkup;
    graph.resize(2 * (machine + 1)); reverse_graph.resize(2 * (machine + 1)); visited.resize(2 * (machine + 1)); set.resize(2 * (machine +1));
    
    for(int i = 1 ; i <= machine ; i++){
        int d1,d2;
        fcin >> d1 >> d2;
        if(d1 < d2) {running.push_back({i,d1,i}); running.push_back({i,d2,i+machine});}
        else{running.push_back({i,d1,i+machine}); running.push_back({i,d2,i});}
    }
    sort(running.begin(),running.end());
}
void Reverse(int i, int j){
    if(running[i].day > machine) {idx1 = running[i].day - machine;}
    else {idx1 = running[i].day + machine;}
    if(running[j].day > machine) {idx2 = running[j].day - machine;}
    else {idx2 = running[j].day + machine;}
}
void MakeGraph(){
    for(int i = 0 ; i < running.size() ; i++){
        for(int j = i + 1; j < running.size() ; j++){
            //if(running[i].mno == running[j].mno) continue; // 같은 기계는 들어갈수 없음
            if(running[i].start + checkup <= running[j].start) break; // 기계가 돌아가는 범위 안에 존재해야하기 때문에
            Reverse(i,j);
            graph[idx1].push_back(running[j].day);
            graph[idx2].push_back(running[i].day);
            reverse_graph[running[i].day].push_back(idx2);
            reverse_graph[running[j].day].push_back(idx1);
        }
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
string GetResult(){
    for(int i = 1 ; i <= machine ; i++){
        if(set[i] == set[i+machine]){
            return "Impossible";
        }
    }
    return "Possible";
}
int main(){
    int testcase;
    fcin >> testcase;
    for(int t = 1 ; t <= testcase ; t++){
        init();
        MakeGraph();
        for(int i = 1 ; i <= 2 * machine ; i++) if(!visited[i]) dfs(i);
        visited.assign(2 * (machine + 1), false);
        int set_num = 1;
        while(!st.empty()){
            int cur = st.top(); st.pop();
            if(visited[cur]) continue; // 이미 방문한 정점
            reverse_dfs(cur, set_num++);
        }
        fcout << "Test Case #" << t << ": " << GetResult() << '\n';
    }
    return 0;
}
