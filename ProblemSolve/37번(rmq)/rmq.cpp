//
//  rmq.cpp
//  ProblemSolve
//
//  Created by  JeJn on 2020/06/12.
//  Copyright © 2020  JeJn. All rights reserved.
//

#include<fstream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
#pragma warning(disable:4996)

ifstream fcin("/Users/jejn/Desktop/ProblemSolve/ProblemSolve/rmq.inp");
ofstream fcout("/Users/jejn/Desktop/ProblemSolve/ProblemSolve/rmq.out");
//FILE *fcin = fopen("/Users/jejn/Desktop/ProblemSolve/ProblemSolve/rmq.inp", "rt");
//FILE *fcout = fopen("/Users/jejn/Desktop/ProblemSolve/ProblemSolve/rmq.out", "wt");

//vector<int> vt, tree; // 입력 벡터, segment tree
int vt[1000001], tree[4050000];
int Init(int idx, int start, int end){
    if (start == end)
        return tree[idx] = start;
    
    int mid = (start + end) / 2;
    int left_side = Init(2 * idx, start, mid);
    int right_side = Init(2 * idx + 1, mid + 1, end);
    
    return tree[idx] = vt[left_side] <= vt[right_side] ? left_side : right_side;
}
int Qurey(int idx, int start, int end, int left, int right){
    /*
     case 1 : [left,right]와 [start,end]가 겹치지 않는 경우 => 더 이상 탐색할 필요 없음. 0을 리턴
     case 2 : [left,right]가 [start,end]를 완전히 포함하는 경우 => 더 이상 탐색할 필요 없음. 그 노드의 값을 리턴
     case 3 : [start,end]가 [left,right]를 완전히 포함하는 경우 => 자식 트리에서 탐색을 계속해야 함
     case 4 : [left,right]와 [start,end]가 겹쳐서 있는 경우(1,2,3을 제외한 나머지 경우) => 자식 트리에서 탐색을 계속해야 함
    */
    if( start > right || end < left ) // case 1
        return -1;
    else if( start >= left && end <= right ) //case 2
        return tree[idx];
    // other case
    int mid = ( start + end ) / 2;
    int left_side = Qurey(2 * idx, start, mid, left, right);
    int right_side = Qurey(2 * idx + 1, mid + 1, end, left, right);
    
    if(left_side == -1) return right_side;
    if(right_side == -1) return left_side;
    
    return vt[left_side] <= vt[right_side] ? left_side : right_side;
}
void Change(int idx, int start, int end, int id){
    
    if(start == end && start == id) return;
    
    if(start <= id && id <= end){
        int mid = (start + end) / 2;
        Change(2 * idx, start, mid, id);
        Change(2 * idx + 1, mid + 1, end, id);
        
        tree[idx] = vt[tree[2 * idx]] <= vt[tree[2 * idx + 1]] ? tree[2 * idx] : tree[2 * idx +1];
    }
}
int main(){
    ios_base::sync_with_stdio(0); fcin.tie(0); fcout.tie(0);
    
    int size; /*fscanf(fcin, "%d", &size);*/ fcin >> size; //vt.resize(size + 1); tree.resize(4 * size, -1); // 범위가 4배 안에서 해결이 가능
    for(int i = 0 ; i < size ; i++) /*{int num; fscanf(fcin, "%d", &num); vt[i] = num;} vt[size] = 987654321;*/ fcin >> vt[i]; vt[size] = 987654321;
    
    Init(1, 0, size - 1); tree[0] = size;
    int ans = 0;
    //fscanf(fcin,"\n");
    while(1){
        char ch; int n1, n2; /*fscanf(fcin,"%c %d %d",&ch, &n1, &n2);*/ fcin >> ch >> n1 >> n2;
        if(ch == 's') break;
        else if(ch == 'q'){
            ans += Qurey(1, 0, size - 1, n1, n2);
            ans %= 100000;
        }
        else{ // ch == 'c'
            vt[n1] = n2;
            Change(1, 0, size -1, n1);
        }
        //fscanf(fcin, "\n");
    }
    fcout << ans << "\n";
    fcin.close(); fcout.close();
    /*fprintf(fcout, "%d\n", ans);*/

    return 0;
}
