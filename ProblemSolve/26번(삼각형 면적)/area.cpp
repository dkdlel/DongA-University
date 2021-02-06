//
//  area.cpp
//  ProblemSolve
//
//  Created by  JeJn on 2020/05/16.
//  Copyright © 2020  JeJn. All rights reserved.
//
//
#include<fstream>
#include<vector>
#include<cmath>
#include<cstdio>
using namespace std;

ifstream fcin("/Users/jejn/Desktop/ProblemSolve/ProblemSolve/area.inp");
FILE *fcout = fopen("/Users/jejn/Desktop/ProblemSolve/ProblemSolve/area.out", "wt");

typedef struct Circle{
    int x,y,r;
}Circle;
typedef struct Point{
    double x,y;
}Point;

Circle circle[3]; // 원 3개
vector<Point> point; // 교점의 좌표

bool innercircle(Circle &C, double ix, double iy){
    if((C.x - ix) * (C.x - ix) + (C.y - iy) * (C.y - iy) > C.r * C.r) return false;
    return true;
}

void GetPoint(Circle &A, Circle &B, Circle &C){

    double dir = sqrt(((A.x - B.x) * (A.x - B.x)) + ((A.y - B.y) * (A.y - B.y))); // 두 원점사이의 거리
    double totangent = ((A.r * A.r) - (B.r * B.r) + (dir * dir)) / (2 * dir); // A원점과 접선 사이의 거리
    double height = sqrt((A.r * A.r) - (totangent * totangent)); // 접선에서 교점과 두 원점사이의 직선의 거리
    double ix = A.x + (totangent * (B.x - A.x) / dir) + (height * (B.y - A.y) / dir);// intersection x(두 원의 교점)
    double iy = A.y + (totangent * (B.y - A.y) / dir) - (height * (B.x - A.x) / dir);// intersection y(두 원의 교점)

    if(!innercircle(C, ix, iy)){
        ix = A.x + (totangent * (B.x - A.x) / dir) - (height * (B.y - A.y) / dir);
        iy = A.y + (totangent * (B.y - A.y) / dir) + (height * (B.x - A.x) / dir);
    }
    point.push_back({ix,iy});
}

double GetArea(){
    double result = ((point[0].x * point[1].y) + (point[1].x * point[2].y) + (point[2].x * point[0].y))
    - ((point[0].x * point[2].y) + (point[2].x * point[1].y) + (point[1].x * point[0].y));

    return fabs(result / 2);
}

int main() {

    int testcase;
    fcin >> testcase;

    while(testcase--){
        point.clear();
        for(int i = 0 ; i < 3 ; i++){
            int x,y,r;
            fcin >> x >> y >> r;
            circle[i].x = x; circle[i].y = y; circle[i].r = r;
        }
        GetPoint(circle[0],circle[1],circle[2]);
        GetPoint(circle[1],circle[2],circle[0]);
        GetPoint(circle[2],circle[0],circle[1]);
        
        fprintf(fcout, "%.2lf\n", GetArea()); // 좌표 3개로 면적 구하기
    }

    return 0;
}
