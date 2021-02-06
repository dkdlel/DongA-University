//
//  ones.cpp
//  ProblemSolve
//
//  Created by  JeJn on 2020/05/22.
//  Copyright © 2020  JeJn. All rights reserved.
//

#include<fstream>
#include<vector>
using namespace std;

ifstream fcin("/Users/jejn/Desktop/ProblemSolve/ProblemSolve/ones.inp");
ofstream fcout("/Users/jejn/Desktop/ProblemSolve/ProblemSolve/ones.out");

int Ones(int n){
    
    int len = 1, div = 1; // len : 나누는 수의 길이, div : 나누는 수
    for(int i = 0 ; ; i++,len++){
        int rest = div % n; // rest : 나머지
        if(rest == 0) return len;
        div = (div % n) * (10 % n) + 1; // 각 자리 수가 mod n 헀을 때 1인지 아닌지
    }
}

int main(){
    
    int n;
    while(fcin >> n){
        fcout << Ones(n) << "\n";
    }
    return 0;
}
