//
//  mult.cpp
//  ProblemSolve
//
//  Created by  JeJn on 2020/05/06.
//  Copyright © 2020  JeJn. All rights reserved.
//
#include<fstream>
#include<vector>
#include<cmath>
using namespace std;

ifstream fcin("/Users/jejn/Desktop/ProblemSolve/ProblemSolve/mult.inp");
ofstream fcout("/Users/jejn/Desktop/ProblemSolve/ProblemSolve/mult.out");

int num, ans; // 곱의 방법 수

void Sol(int div, int num){
    vector<int> divisor, divide; // divisor : 나누는 수, divide : 나누고 남는 수
    
    for(int i = div ; i <= sqrt(num) ; i++){ // 나누는 수보다는 크고, 중복수를 제거하기 위해 제곱근까지 돌림
        if(num % i == 0){
            divisor.push_back(i);
            divide.push_back(num/i);
        }
    }
    for(int i = 0 ; i < divisor.size() ; i++){
            ans++;
            Sol(divisor[i],divide[i]);
    }
}
int main(){
    
    int testcase;
    fcin >> testcase;
    while(testcase--){
        ans = 0;
        fcin >> num;
        Sol(2,num);
        fcout << num << ' ' << ans << '\n';
    }
    return 0;
}
