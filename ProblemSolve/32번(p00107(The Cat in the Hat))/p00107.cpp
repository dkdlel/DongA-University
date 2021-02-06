//
//  p00107.cpp
//  ProblemSolve
//
//  Created by  JeJn on 2020/05/27.
//  Copyright © 2020  JeJn. All rights reserved.
//

#include<fstream>
#include<cmath>
#include<cstdio>
using namespace std;
#pragma warning(disable:4996)
typedef long double ld;

ifstream fcin("/Users/jejn/Desktop/ProblemSolve/ProblemSolve/p00107.inp");
FILE *fcout = fopen("/Users/jejn/Desktop/ProblemSolve/ProblemSolve/p00107.out", "wt");

int Square(int n, int digit){
    int num = 1;
    for(int i = 0 ; i < n ; i++){
        num *= digit;
    }
    return num;
}
int main(){

    while(1){
        ld height, work_cat; // height : the height of the initial cat, work_cat : the number of workers cat
        fcin >> height >> work_cat;
        if(height == 0 && work_cat == 0) break; // input : 0 0 -> end

        // 밑 구하기
        ld n = 2.0; // n = 밑
        ld rightSide = log (height) / log (work_cat);
        while ( fabs (log (n + 1) / log (n) - rightSide) > 1e-12  ) n += 1;
        // 지수 구하기
        ld m, tmp = n; // m = 지수
        for(int i = 1;; i++){
            if(tmp == work_cat){
                m = i; break;
            }
            else tmp *= n;
        }
        ld not_working = 0, cat_height = 0; // not_working : cats that are not working, cat_height : height of the stack of cat
        for(int i = 0 ; i < m ; i++){
            int digit = Square(i, (int)n);
            not_working += digit;
        }
        for(int i = 0; i <= m ; i++){
            int n1 = Square(i, (int)n);
            int n2 = Square(m-i, (int)(n+1));
            cat_height += n1*n2;
        }
        fprintf(fcout, "%0.Lf %0.Lf\n", not_working, cat_height);
    }
    return 0;
}
