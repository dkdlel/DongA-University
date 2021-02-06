//
//  p10205.cpp
//  ProblemSolve
//
//  Created by  JeJn on 2020/04/28.
//  Copyright © 2020  JeJn. All rights reserved.
//

#include<fstream>
#include<vector>
#include<string>
#include<cstdio>
using namespace std;
#pragma warning(disable:4996)

FILE *fcin = fopen("/Users/jejn/Desktop/ProblemSolve/ProblemSolve/p10205.inp","rt"); // C++ 입력으로 공백처리가 까다로움
ofstream fcout("/Users/jejn/Desktop/ProblemSolve/ProblemSolve/p10205.out");

int main(){

    int testcase, shuffle_num;
    fscanf(fcin,"%d",&testcase);
    for(int t = 0 ; t < testcase ; t++){
        fscanf(fcin, "%d", &shuffle_num);
        vector < vector < int > > shuffle(shuffle_num + 1, vector<int>(53,0));
        vector <int> card(53,0), old_card(53,0);
        
        for(int i = 1 ; i <= shuffle_num ; i++) for(int j = 1 ; j < 53; j++) fscanf(fcin, "%d", &shuffle[i][j]);
        for(int i = 1 ; i < 53; i++) card[i] = i;
         
        char line[101];
        
        fgets(line,101, fcin); // 공백을 받기 위함
        while(fgets(line,101,fcin)){
            if(line[0] == '\n') break; // 탈출조건: 입력이 아무것도 없을때
            int num;
            sscanf(line, "%d", &num); // fgets로 buffer에 받은걸 int형태로 저장
            
            for(int i = 1 ; i < 53 ; i++) old_card[i] = card[shuffle[num][i]];
            for(int i = 1 ; i < 53 ; i++) card[i] = old_card[i];
        }

        if(t>0) fcout << '\n'; // 각 testcase들 사이에 공백으로 구분
        string value[13] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace" };
        string suit[4] = { "Clubs", "Diamonds", "Hearts", "Spades" };
        for (int i = 1; i <= 52; i++) fcout << value[(card[i] - 1) % 13] << " of " << suit[(card[i] - 1) / 13] << '\n';
    }
    return 0;
}
