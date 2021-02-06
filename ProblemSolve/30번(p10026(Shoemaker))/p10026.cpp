//
//  p10026.cpp
//  ProblemSolve
//
//  Created by  JeJn on 2020/05/22.
//  Copyright © 2020  JeJn. All rights reserved.
//

#include<fstream>
#include<vector>
using namespace std;

ifstream fcin("/Users/jejn/Desktop/ProblemSolve/ProblemSolve/p10026.inp");
ofstream fcout("/Users/jejn/Desktop/ProblemSolve/ProblemSolve/p10026.out");

struct info{ int num, time, penalty;}; // num : 직장번호, time : 작업완료하는데 걸리는 시간, penalty : 벌금
vector<info> input;

void Init(){
    input.clear();
    int n; fcin >> n;
    
    for(int i = 1 ; i <= n ; i++){
        int t,p; // t : time, p : penalty
        fcin >> t >> p;
        input.push_back({i,t,p});
    }
}
bool isChange(int a, int b){
    if(input[a].time * input[b].penalty > input[a].penalty * input[b].time) return true;
    return false;
}
void Sol(){ // 완탐
    for(int i = 0 ; i < input.size() ; i++){
        for(int j = 0 ; j < input.size() -1 ; j++){
            if(isChange(j,j+1)){ // 바꾸지 않았을때 벌금이 더 큰 경우
                info temp = input[j];
                input[j] = input[j+1];
                input[j+1] = temp;
            }
        }
    }
}
int main(){
    
    int testcase;
    fcin >> testcase;
    
    while(testcase--){
        Init();
        Sol();
        for(int i = 0 ; i < input.size() ; i++) fcout << input[i].num << " ";
        fcout << "\n";
    }
    return 0;
}
