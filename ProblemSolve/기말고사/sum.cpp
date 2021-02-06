//
//  sum.cpp
//  ProblemSolve
//
//  Created by  JeJn on 2020/06/22.
//  Copyright © 2020  JeJn. All rights reserved.
//

#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

ifstream fcin("/Users/jejn/Desktop/ProblemSolve/ProblemSolve/sum.inp");
ofstream fcout("/Users/jejn/Desktop/ProblemSolve/ProblemSolve/sum.out");

vector<int> vt;

int Sum(int num){
    for(int i = 2 ; ;i++){
        if(vt[1] == num) return 1;
        vt.push_back(vt[i-1] + vt[i-2] + 2);
        if(vt[i] >= num) return vt[i-1];
    }
}
int main(){
    
    int k; fcin >> k;
    for(int t = 0 ; t < k ; t++){
        vt.clear(); vt.push_back(1); vt.push_back(2);
        int num; fcin >> num;
        fcout << Sum(num) << "\n";
    }
    return 0;
}
