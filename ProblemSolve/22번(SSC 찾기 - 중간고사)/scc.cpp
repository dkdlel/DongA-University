//
//  scc.cpp
//  ProblemSolve
//
//  Created by  JeJn on 2020/05/05.
//  Copyright © 2020  JeJn. All rights reserved.
//
//
#include <fstream>
#include <vector>
#include <stack>
using namespace std;

ifstream fcin("/Users/jejn/Desktop/ProblemSolve/ProblemSolve/scc.inp");
ofstream fcout("/Users/jejn/Desktop/ProblemSolve/ProblemSolve/scc.out");

int vertex_num, edge_num;
vector < vector <int> > graph, reverse_graph;
vector <bool> visited;
stack <int> st;
int ans;

void Init(){
    ans = 0;
    fcin >> vertex_num >> edge_num;
    graph.resize(vertex_num); reverse_graph.resize(vertex_num);
    visited.assign(vertex_num, false);

    for(int i = 0 ; i < edge_num ; i++){
        int x, y;
        fcin >> x >> y;
        graph[x].push_back(y);
        reverse_graph[y].push_back(x);
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
void reverse_dfs(int cur){
    visited[cur] = true;
    for(int i = 0 ; i < reverse_graph[cur].size() ; i++){
        int next = reverse_graph[cur][i];
        if(!visited[next]) reverse_dfs(next);
    }
}
int main(){

    Init();
    for(int i = 0 ; i < vertex_num ; i++) if(!visited[i]) dfs(i);
    visited.assign(vertex_num, false);

    while(!st.empty()){
        int cur = st.top(); st.pop();
        if(visited[cur]) continue; // 이미 방문한 정점
        reverse_dfs(cur);
        ans++;
    }
    fcout << ans << '\n';
    return 0;
}
