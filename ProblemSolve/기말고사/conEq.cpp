//
//  conEq.cpp
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

ifstream fcin("/Users/jejn/Desktop/ProblemSolve/ProblemSolve/conEq.inp");
ofstream fcout("/Users/jejn/Desktop/ProblemSolve/ProblemSolve/conEq.out");

typedef long long ll;
ll GCD(ll a, ll b) { return b ? GCD(b , a%b) : a;}

int main(){
    int k; fcin >> k;
    for(int t = 0 ; t < k ; t++){
        ll a, b, n; fcin >> a >> b >> n;
        while(b > n) b -= n; 
        int cnt = 0;
        for(int i = 0 ; i < 100000 ; i++){
            
            if(cnt == 2) break;
            
            else if(a * i % n == b){
                cnt++;
                fcout << i << " ";
            }
        }
        if(!cnt) fcout << "-1";
        fcout << "\n";
    }
    
    return 0;
}
