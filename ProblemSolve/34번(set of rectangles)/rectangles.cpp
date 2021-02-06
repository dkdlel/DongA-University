//
//  rectangles.cpp
//  ProblemSolve
//
//  Created by  JeJn on 2020/06/07.
//  Copyright © 2020  JeJn. All rights reserved.
//

#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

ifstream fcin("/Users/jejn/Desktop/ProblemSolve/ProblemSolve/rectangles.inp");
ofstream fcout("/Users/jejn/Desktop/ProblemSolve/ProblemSolve/rectangles.out");

vector<int> dp;
int GCD(int a, int b) { return b ? GCD(b , a % b) : a;}
void Find_Pythagorean(){
    for(int i = 2 ; i < 1001 ; i++){
        for(int j = 1 ; j < i ; j++){ // w < h < d
            int w = 2 * i * j, h = i * i - j * j;
            if(GCD(w,h) == 1) // w와 h는 서로소
                dp.push_back(w+h);
        }
    }
    sort(dp.begin(), dp.end());
}

int main(){
    
    Find_Pythagorean();
    int testcase;
    fcin >> testcase;
    while(testcase--){
        int L; fcin >> L; L /= 2;
        int idx = 0, cnt = 0;
        for(; L - dp[idx] >= 0 ; idx++,cnt++) L -= dp[idx];
        fcout << cnt << "\n";
    }
    return 0;
}
