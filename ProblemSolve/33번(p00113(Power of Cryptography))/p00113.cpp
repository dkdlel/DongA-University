//
//  p00113.cpp
//  ProblemSolve
//
//  Created by  JeJn on 2020/05/27.
//  Copyright © 2020  JeJn. All rights reserved.
//

#include<fstream>
#include<cmath>
using namespace std;

ifstream fcin("/Users/jejn/Desktop/ProblemSolve/ProblemSolve/p00113.inp");
ofstream fcout("/Users/jejn/Desktop/ProblemSolve/ProblemSolve/p00113.out");

int main(){
    
    double n, p;
    while(fcin >> n >> p) fcout << pow(p,1/n) << "\n";
    return 0;
}
