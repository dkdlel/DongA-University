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

ifstream fcin("service.inp");
ofstream fcout("service.out");
//FILE *fcout = fopen("/Users/jejn/Desktop/ProblemSolve/ProblemSolve/p00107.out","wt");

ld Square(ld n, ld digit) {
    ld num = 1;
    for (int i = 0; i < n; i++) {
        num *= digit;
    }
    return num;
}
int main() {

    while (1) {
        ld height, work_cat; // height : the height of the initial cat, work_cat : the number of workers cat
        fcin >> height >> work_cat;
        if (height == 0 && work_cat == 0) break; // input : 0 0 -> end

        ld n, m;
        for (ld i = 2;; i++) {
            ld tmp1 = powl(height, 1 / i); // lond double pow
            ld tmp2 = powl(work_cat, 1 / i);
             if (tmp1 == tmp2 + 1) { n = tmp2; m = i; break; }
        }

        ld not_working = 1, cat_height = 0, digit; // not_working : cats that are not working, cat_height : height of the stack of cat, digit : 제곱수
        for (ld i = 0; i < m; i++) {
            digit = Square(i, n);
            not_working += digit;
        }
        ld n1, n2;
        for (ld i = 0; i <= m; i++) {
            n1 = Square(i, n);
            n2 = Square(m - i, n + 1);
            cat_height += n1 * n2;
        }
        fcout << (int)not_working << " ";
        //fprintf(fcout, "%Lf ", not_working);
        fcout << (int)cat_height << "\n";
        //fprintf(fcout, "%Lf\n", cat_height);
    }
    return 0;
}