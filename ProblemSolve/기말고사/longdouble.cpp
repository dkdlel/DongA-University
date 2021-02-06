//
//  longdouble.cpp
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

ifstream fcin("/Users/jejn/Desktop/ProblemSolve/ProblemSolve/longdouble.inp");
ofstream fcout("/Users/jejn/Desktop/ProblemSolve/ProblemSolve/longdouble.out");

string A,B;
string front, back, reverse_front_A, reverse_front_B, reverse_back_A, reverse_back_B;
string front_A, front_B, back_A, back_B;
int carry = 0, A_dot, B_dot;

void Cal(){
    // reverse
    for(int i = front_A.size() - 1 ; i >= 0 ; i--) reverse_front_A += front_A[i];
    for(int i = front_B.size() - 1 ; i >= 0 ; i--) reverse_front_B += front_B[i];
    for(int i = back_A.size() - 1 ; i >= 0 ; i--) reverse_back_A += back_A[i];
    for(int i = back_B.size() -1 ; i >= 0 ; i--) reverse_back_B += back_B[i];
    // 자리수에 맞게 0 채우기
    if(front_A.size() > front_B.size()){
        for(int i = front_B.size() ; i < front_A.size() ; i++)
            reverse_front_B.push_back('0');
    }
    else if(front_B.size() > front_A.size()){
        for(int i = front_A.size() ; i < front_B.size() ; i++)
            reverse_front_A.push_back('0');
    }
    if(back_A.size() > back_B.size()){
        for(int i = back_B.size() ; i < back_A.size() ; i++)
            reverse_back_B.push_back('0');
    }
    else if(back_B.size() > back_A.size()){
        for(int i = back_A.size() ; i < back_B.size() ; i++)
            reverse_back_A.push_back('0');
    }
    
    for(int i = 0 ; i < reverse_back_A.size() ; i++){
        int num;
        num = carry + (reverse_back_A[i] - '0') + (reverse_back_B[i] - '0');
        carry = 0;
        if(num >= 10){
            carry = 1;
            num -= 10;
        }
        num += '0';
        back.push_back(num);
    }
    // 정수 덧셈
    for(int i = 0 ; i < reverse_front_A.size() ; i++){
        int num; // 결과값
        num =  carry + (reverse_front_A[i] - '0') + (reverse_front_B[i] - '0');
        carry = 0;
        if(num >= 10){
            carry = 1;
            num -= 10;
        }
        num += '0';
        front.push_back(num);
    }
    if(carry == 1) front.push_back('1');
    carry = 0;
    
    // 0제거
    for(int i = 0 ; i < front_A.size() ; i++){
        if(front_A[i] != '0') break;
        front_A.erase(i,i+1);
    }
    for(int i = back.size() - 1; i >= 0 ; i--){
        if(back[i] != '0') break;
        back.erase(i,i+1);
    }
    // 출력
    if(A[0] == '-' && B[0] == '-') fcout << '-';
    for(int i = front.size() - 1 ; i >= 0 ; i--) fcout << front[i];
    if(back.size() != 0) {fcout << '.'; fcout << back;}
    fcout << "\n";
}
void Same_Sum(){
    A_dot = A.find('.'); B_dot = B.find('.');
    if(A[0] == '-'){ // 둘다 음수일때
        if(A_dot == -1 && B_dot != -1){ // A소수 이하가 없을때
            front_A = A.substr(1, A.size());
            back_A = "";
            front_B = B.substr(1, B_dot-1);
            back_B = B.substr(B_dot + 1, B.size());
        }
        else if(B_dot == -1 && A_dot != -1){ // B소수 이하가 없을때
            front_A = A.substr(1, A_dot-1);
            back_A = A.substr(A_dot + 1, A.size());
            front_B = B.substr(1, B.size());
            back_B = "";
        }
        else if(A_dot != -1 && B_dot != -1){ // 둘다 소수 이하가 있을때
            front_A = A.substr(1, A_dot-1);
            back_A = A.substr(A_dot + 1, A.size());
            front_B = B.substr(1, B_dot-1);
            back_B = B.substr(B_dot + 1, B.size());
        }
        else{ // 둘다 소수 이하가 없을때
            front_A = A.substr(1, A.size());
            back_A = "";
            front_B = B.substr(1, B.size());
            back_B = "";
        }
    }
    
    else{ // 둘다 양수일때
        if(A_dot == -1 && B_dot != -1){ // A소수 이하가 없을때
            front_A = A.substr(0, A.size());
            back_A = "";
            front_B = B.substr(0, B_dot);
            back_B = B.substr(B_dot + 1, B.size());
        }
        else if(B_dot == -1 && A_dot != -1){ // B소수 이하가 없을때
            front_A = A.substr(0, A_dot);
            back_A = A.substr(A_dot + 1, A.size());
            front_B = B.substr(0, B.size());
            back_B = "";
        }
        else if(A_dot != -1 && B_dot != -1){ // 둘다 소수 이하가 있을때
            front_A = A.substr(0, A_dot);
            back_A = A.substr(A_dot + 1, A.size());
            front_B = B.substr(0, B_dot);
            back_B = B.substr(B_dot + 1, B.size());
        }
        else{ // 둘다 소수 이하가 없을때
            front_A = A.substr(0, A.size());
            back_A = "";
            front_B = B.substr(0, B.size());
            back_B = "";
        }
    }

    Cal();
}
void A_Cal(){
    
}
void A_Minus(){
    A_dot = A.find('.'); B_dot = B.find('.');
    if(A_dot == -1 && B_dot != -1){ // A소수 이하가 없을때
        front_A = A.substr(1, A.size());
        back_A = "";
        front_B = B.substr(0, B_dot);
        back_B = B.substr(B_dot + 1, B.size());
    }
    else if(B_dot == -1 && A_dot != -1){ // B소수 이하가 없을때
        front_A = A.substr(1, A_dot-1);
        back_A = A.substr(A_dot + 1, A.size());
        front_B = B.substr(0, B.size());
        back_B = "";
    }
    else if(A_dot != -1 && B_dot != -1){ // 둘다 소수 이하가 있을때
        front_A = A.substr(1, A_dot-1);
        back_A = A.substr(A_dot + 1, A.size());
        front_B = B.substr(0, B_dot);
        back_B = B.substr(B_dot + 1, B.size());
    }
    else{ // 둘다 소수 이하가 없을때
        front_A = A.substr(1, A.size());
        back_A = "";
        front_B = B.substr(0, B.size());
        back_B = "";
    }
    A_Cal();
}
int main(){
    int k; fcin >> k;
    for(int t = 0 ; t < k ; t++){
        front.clear(), back.clear(), reverse_front_A.clear(), reverse_front_B.clear(), reverse_back_A.clear(), reverse_back_B.clear();
        front_A.clear(), front_B.clear(), back_A.clear(), back_B.clear();
        fcin >> A >> B;
        // 같은부호
        if((A[0] == '-' && B[0] == '-') || ((A[0] >= '0' && A[0] <= '9') && (B[0] >= '0' && B[0] <= '9'))){
            Same_Sum();
        }
        // A만 음수
        else if((A[0] == '-') && (B[0] >= '0' && B[0] <= '9')){
            A_Minus();
        }
        // B만 음수
        else if((A[0] >= '0' && A[0] <= '9') && (B[0] == '-')){
            
        }
    }
    return 0;
}
