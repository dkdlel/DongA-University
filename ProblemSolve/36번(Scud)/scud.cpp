//
//  scud.cpp
//  ProblemSolve
//
//  Created by  JeJn on 2020/06/08.
//  Copyright © 2020  JeJn. All rights reserved.
//

#include<fstream>
#include<algorithm>
#include<vector>
#include<stack>
#include<cmath>
using namespace std;

ifstream fcin("/Users/jejn/Desktop/ProblemSolve/ProblemSolve/scud.inp");
FILE* fcout = fopen("/Users/jejn/Desktop/ProblemSolve/ProblemSolve/scud.out", "wt");

struct Point {
    int x, y, dx, dy;
    
    bool operator<(const Point& P) const{
        if (dy * P.dx != dx * P.dy) return dy * P.dx < dx* P.dy;
        if (x != P.x) return x < P.x;
        return y < P.y;
    }
};
long long int ccw(const Point& A, const Point& B, const Point& C) {
    return A.x * B.y + B.x * C.y + C.x * A.y - B.x * A.y - C.x * B.y - A.x * C.y;
}

vector<Point> kingdom, kingdompoint;
vector<vector < Point > > kingdomwall;
vector<bool> attack;
void ConvexHull() {
    stack<int> s;
    s.push(0); s.push(1);
    int next = 2;
    while (next < kingdom.size()) {
        while (s.size() >= 2) {
            int second = s.top(); s.pop();
            int first = s.top();
            if (ccw(kingdom[first], kingdom[second], kingdom[next]) > 0) {
                s.push(second);
                break;
            }
        }
        s.push(next++);
    }
    kingdompoint.resize(s.size());
    for (long i = kingdompoint.size() - 1; i >= 0; i--) {
        kingdompoint[i] = kingdom[s.top()];
        s.pop();
    }
    kingdomwall.push_back(kingdompoint);
}
void Init(){
    while(1){
        kingdom.clear(); kingdompoint.clear();
        int N; fcin >> N;
        if(N == -1) break;
        for(int i = 0 ; i < N ; i++){
            int x,y; fcin >> x >> y;
            kingdom.push_back({x,y,0,1});
        }
        sort(kingdom.begin(), kingdom.end());
        for (int i = 1; i < N; i++) {
            kingdom[i].dx = kingdom[i].x - kingdom[0].x;
            kingdom[i].dy = kingdom[i].y - kingdom[0].y;
        }
        sort(kingdom.begin() + 1, kingdom.end());
        ConvexHull();
        attack.push_back(false);
    }
}
bool Between(Point cur, Point next, Point missile){
    if (ccw(cur, next, missile) != 0) return false;
    if (cur.x != next.x)  return ((cur.x <= missile.x && missile.x <= next.x) || (next.x <= missile.x && missile.x <= cur.x));
    else return ((cur.y <= missile.y && missile.y <= next.y) || (next.y <= missile.y && missile.y <= cur.y));
}
bool InnerKingdom(vector<Point> &kingdom, Point missile){ // point과제 참고
    int cross_cnt = 0;
    for(int i = 0 ; i < kingdom.size() ; i++){
        int next = (i+1) % kingdom.size();
        if(Between(kingdom[i], kingdom[next], missile)) return true; // 점이 사이에 있는지 확인
        if (((kingdom[i].y < missile.y) && (kingdom[next].y >= missile.y) && (ccw(kingdom[i], kingdom[next], missile)) > 0) // 교차하는지 확인
        || ((kingdom[next].y < missile.y) && (kingdom[i].y >= missile.y) && (ccw(kingdom[next], kingdom[i], missile)) > 0))
        cross_cnt++;
    }
    return cross_cnt % 2;
}
double GetArea(vector<Point> &kingdomwall){
    double area = 0;
    kingdomwall.push_back(kingdomwall[0]);
    for(int i = 0 ; i < kingdomwall.size() - 1 ; i++)
        area += (kingdomwall[i].x * kingdomwall[i + 1].y) - (kingdomwall[i].y * kingdomwall[i + 1].x);
    
    return area;
}
int main(){

    Init();
    int x,y;
    while(fcin >> x >> y){
        for (int i = 0; i < kingdomwall.size(); i++) {
            if(!attack[i]){ // 공격당하지 않았을 경우
                if (InnerKingdom(kingdomwall[i], {x, y})) { // 안에 있는지 없는지 확인
                   attack[i] = true;
                   break;
               }
            }
        }
        
    }
    double ans = 0;
    for(int i = 0 ; i < kingdomwall.size() ; i++){
        if(attack[i]) // 공격당한 왕국이면
            ans += GetArea(kingdomwall[i]);
    }
    fprintf(fcout, "%0.2lf\n", 0.5 * fabs(ans));
    return 0;
}
