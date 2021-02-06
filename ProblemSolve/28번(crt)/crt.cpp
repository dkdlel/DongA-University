//
//  crt.cpp
//  ProblemSolve
//
//  Created by  JeJn on 2020/05/20.
//  Copyright © 2020  JeJn. All rights reserved.
//

#include<fstream>
#include<vector>
using namespace std;

ifstream fcin("/Users/jejn/Desktop/ProblemSolve/ProblemSolve/crt.inp");
ofstream fcout("/Users/jejn/Desktop/ProblemSolve/ProblemSolve/crt.out");

typedef long long ll;
struct info{ ll r, m; };// r : 나머지, m : 몫
struct qs{ ll q,s; }; // q : 몫, s : 역원
vector<info> input; // crt의 input

void Init(){
    input.clear();
    int k; // 식의 정수
    fcin >> k;
    input.resize(k);
    for(int i = 0 ; i < k ; i++){
        ll r, m;
        fcin >> r >> m;
        input[i].r = r; input[i].m = m;
    }
}
ll GCD(ll a, ll b) { return b ? GCD(b , a%b) : a;}
qs Extended_Euclid(ll a, ll b){
    ll q, r1 = a, r2 = b, r, s1 = 1, s2 = 0, s, t1 = 0, t2 = 1, t;
    while(1){
        q = r1/r2;
        r = r1 - q * r2;
        s = s1 - q * s2;
        t = t1 - q * t2;
        if(r == 0) break;
        r1 = r2;
        r2 = r;
        s1 = s2;
        s2 = s;
        t1 = t2;
        t2 = t;
    }
    return {r2,s2};
}
void Crt(){
    ll ans_r = input[0].r, ans_m = input[0].m;
    for(int i = 1 ; i < input.size() ; i++){
        ll cur_r = input[i].r, cur_m = input[i].m;
        cur_r -= ans_r;
        while(cur_r < 0) cur_r += cur_m; // 나머지가 음수가 나올경우 양수로 바꿈
        ll gcd = GCD(GCD(ans_m,cur_r),cur_m); // 현재 식에서 최대공약수가 있는지 확인
        cur_m /= gcd; cur_r /= gcd;
        qs inv = Extended_Euclid(ans_m / gcd, cur_m); // inv : inverse, ans_m이 변하면 안되기 때문에 매개변수로 넘겨줌
        if(inv.q != 1){ fcout << "-1\n"; return; }; // 곲의 역원은 1
        
        if(cur_r){ // 현재의 나머지가 자연수 일때 ex) 0(mod n)
            cur_r *= inv.s;
            cur_r %= cur_m;
            while(cur_r < 0) cur_r += cur_m;
        }
        ans_r += ans_m * cur_r;
        ans_m *= cur_m;
    }
    fcout << ans_r << '\n';
}
int main(){

    int testcase;
    fcin >> testcase;
    while(testcase--){
        Init();
        Crt();
    }
    return 0;
}
