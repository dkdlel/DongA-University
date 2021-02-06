//
//  contour.cpp
//  ProblemSolve
//
//  Created by  JeJn on 2020/06/03.
//  Copyright © 2020  JeJn. All rights reserved.
//

#include<fstream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
typedef long long ll;

ifstream fcin("/Users/jejn/Desktop/ProblemSolve/ProblemSolve/contour.inp");
ofstream fcout("/Users/jejn/Desktop/ProblemSolve/ProblemSolve/contour.out");

struct info{char dir; ll x, height;};
bool operator<(const info &A, const info &B){ return A.x < B.x; }
vector<info> vec;

void GetArea(){
    ll area = 0; multiset<ll, greater<ll>> mst;
    sort(vec.begin(),vec.end());
    for(int i = 0 ; i < vec.size() - 1 ; i++){
        if(vec[i].dir == 'L') mst.insert(vec[i].height);
        else mst.erase(mst.find(vec[i].height));
        if(mst.empty()){
            fcout << area << " ";
            area = 0;
            continue;
        }
        multiset<ll>::iterator iter = mst.begin();
        area += *iter * (vec[i+1].x - vec[i].x);
    }
    fcout << area << "\n";
    vec.clear();
}

int main(){
    
    int t = 1;
    while(1){
        int x = -1,y,z; fcin >> x >> y >> z; if(x == -1) break;
        if(!x && !y && !z){fcout << "Test Case #" << t << " : "; GetArea(); t++;}
        else { vec.push_back({'L',x,y}); vec.push_back({'R',z,y}); }
    }
    return 0;
}
