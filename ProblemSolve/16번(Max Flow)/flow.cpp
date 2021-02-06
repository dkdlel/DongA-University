//
//  flow.cpp
//  ProblemSolve
//
//  Created by  JeJn on 2020/04/22.
//  Copyright © 2020  JeJn. All rights reserved.
//
//
#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
using namespace std;

ifstream fcin("/Users/jejn/Desktop/ProblemSolve/ProblemSolve/flow.inp");
ofstream fcout("/Users/jejn/Desktop/ProblemSolve/ProblemSolve/flow.out");

typedef struct info{
    int start,dest,flow; // start : edge1, dest : edge2, flow : 흐름
}info;

vector < vector < info > > graph;
vector<int> parent; // 경로를 찾기위한 부모들의 정보저장
int vertex_num, result; // 정점의 총 갯수

void Init(){
    fcin >> vertex_num;
    graph.resize(vertex_num); result = 0;
    while(1){
        int i,j,w;
        fcin >> i >> j >> w;
        if(i == -1 && j == -1 && w == -1) break;
        graph[i].push_back({i,j,w}); graph[j].push_back({j,i,w});
    }
}
void BFS(){
    
    while(1){
        queue<int> queue; queue.push(0);
        parent.assign(vertex_num,-1); parent[0] = 0;
        while(!queue.empty()){
            int cur = queue.front(); queue.pop(); bool flag = false;
            for(int i = 0 ; i < graph[cur].size() ; i++){
                int next = graph[cur][i].dest;
                if(graph[cur][i].flow > 0 && parent[next] == -1){
                    queue.push(next);
                    parent[next] = cur;
                    if(next == vertex_num -1) {
                        flag = true; break;
                    }
                }
            }
            if(flag) break;
        }
        
        if(parent[vertex_num-1] == -1) {
            fcout << result << '\n';
            break;
        }
        // n-1지점에 도착 / 경로중 최소값 찾기
        int min = 987654321, cur = vertex_num-1;
        for(int i = 0 ; i < vertex_num ; i++){
            int next = parent[cur];
            for(int j = 0 ; j < graph[cur].size(); j++){
                if(graph[cur][j].dest == next){ // 부모 찾음
                    if(graph[cur][j].flow < min) min = graph[cur][j].flow;
                }
            }
            if(!next) break; // source를 찾음
            cur = next;
        }
        // flow값 계산
        cur = vertex_num - 1;
        for(int i = 0 ; i < vertex_num ; i++){
            int next = parent[cur];
            for(int j = 0 ; j < graph[cur].size(); j++){
                if(graph[cur][j].dest == next){
                    graph[cur][j].flow -= min;
                }
            }
            for(int j = 0 ; j < graph[next].size(); j++){
                if(graph[next][j].dest == cur){
                    graph[next][j].flow -= min;
                }
            }
            if(!next) break;
            cur = next;
        }
        result += min;
    }
}
int main(){
    
    Init();
    BFS();
    return 0;
}
