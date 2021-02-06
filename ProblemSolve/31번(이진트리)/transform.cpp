//
//  transform.cpp
//  ProblemSolve
//
//  Created by  JeJn on 2020/05/27.
//  Copyright © 2020  JeJn. All rights reserved.
//

#include<fstream>
#include<vector>
#include<stack>
#include<string>
using namespace std;

ifstream fcin("/Users/jejn/Desktop/ProblemSolve/ProblemSolve/transform.inp");
ofstream fcout("/Users/jejn/Desktop/ProblemSolve/ProblemSolve/transform.out");


int node;
int arr[20001];
//void BracketToInt(int num){
//    stack<int> st; int cnt = 1;
//    fcout << num << " ";
//    for(int i = 0 ; i < num * 2 ; i++){
//        char ch; fcin >> ch;
//        if(ch == '(') st.push(cnt++);
//        else if(ch == ')'){fcout << st.top() << " "; st.pop();}
//    }
//}
void BracketToInt(int num){
    int cnt = 1, idx = 0;
    fcout << num << " ";
    for(int i = 0 ; i < num * 2 ; i++){
        char ch; fcin >> ch;
        if(ch == '(') {arr[idx] = cnt; cnt++;idx++;}
        else {fcout << arr[idx-1] << " "; idx--;}
    }
}
string IntToBracket(int start, int end){
    for(int i = start ; i <=  end; i++){
        if(arr[i] == node){ // 현재 노드 번호
            node++; // 다음 노드를 확인
            string str = "(" + IntToBracket(start, i-1) + ")"; // 왼쪽에 있는 경우 괄호 안에
            str += IntToBracket(i, end); // 오른쪽에 있는 경우 새로운 괄호 생성
            return str;
        }
    }
    return "";
}
void IntToBracketInit(int num){
    node = 1;
    fcout << num << " ";
    for(int i = 0 ; i < num ; i++){fcin >> arr[i];}
    fcout << IntToBracket(0, num-1);
}
int main(){
    
    int testcase;
    fcin >> testcase;
    while(testcase--){
        int num, type;
        fcin >> num >> type;
        
        if(type) BracketToInt(num);// type : 1
        else IntToBracketInit(num); // type : 0
        fcout << "\n";
    }
    
    return 0;
}
