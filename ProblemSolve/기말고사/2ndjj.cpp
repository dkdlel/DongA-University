//
//  2ndjj.cpp
//  ProblemSolve
//
//  Created by  JeJn on 2020/06/22.
//  Copyright © 2020  JeJn. All rights reserved.
//

#include<fstream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

ifstream fcin("/Users/jejn/Desktop/ProblemSolve/ProblemSolve/2ndjj.inp");
ofstream fcout("/Users/jejn/Desktop/ProblemSolve/ProblemSolve/2ndjj.out");

vector<int> vt, jolly;

int Sol(int size){
    for(int i = 0 ; i < size ; i++){
        jolly[vt[i]] = 1;
    }
    for(int i = 1 ; i < size ; i++){
        if(!jolly[i]) return 0;
    }
    return 1;
}
int main(){
    
    int k; fcin >> k;
    for(int t = 0 ; t < k ; t++){
        int size; fcin >> size;
        vt.clear(); jolly.clear(); jolly.assign(101, 0);
        for(int i = 0 ; i < size ; i++){
            int num; fcin >> num;
            vt.push_back(num);
        }
        for(int i = 0 ; i < size - 1; i++){
            vt[i] = abs(vt[i] - vt[i+1]);
        }
        for(int i = 0 ; i < size - 2; i++){
            vt[i] = abs(vt[i] - vt[i+1]);
        }
        int ans = Sol(size - 2);
        if(ans == 0) fcout << "No\n";
        else fcout << "Yes\n";
    }
    
    return 0;
}
