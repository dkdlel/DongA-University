//
//  poker.cpp
//  ProblemSolve
//
//  Created by  JeJn on 2020/04/24.
//  Copyright © 2020  JeJn. All rights reserved.
//

#include <fstream>
#include <vector>
using namespace std;

ifstream fcin("/Users/jejn/Desktop/ProblemSolve/ProblemSolve/poker.inp");
ofstream fcout("/Users/jejn/Desktop/ProblemSolve/ProblemSolve/poker.out");

vector<int>spade, diamond, heart, clover, cnt;
int change(char ch2){
    switch(ch2){
        case'A':  return 1;
        case'T': return 10;
        case'J': return 11;
        case'Q': return 12;
        case'K': return 13;
        default: return ch2 - '0';
    }
}
bool StraightFlush(){
    int count;
    for(int i = 1 ; i <= 13 ; i++){
        count = 0; // straight count
        if(spade[i] != 0 && spade[i+1] != 0){
            for(int j = i ; j <= i + 4; j++){
                int n1 = j, n2 = j+1;
                if(n1 > 13) n1 %= 13;
                else if(n2 > 13) n2 %= 13;
                if(spade[n1] > 0 && spade[n2] > 0) count++;
            }
        }
        if(count == 4) return true;
    }
    
    for(int i = 1 ; i <= 13 ; i++){
        count = 0; // straight count
        if(diamond[i] != 0 && diamond[i+1] != 0){
            for(int j = i ; j <= i + 4; j++){
                int n1 = j, n2 = j+1;
                if(n1 > 13) n1 %= 13;
                else if(n2 > 13) n2 %= 13;
                if(diamond[n1] > 0 && diamond[n2] > 0) count++;
            }
        }
        if(count == 4) return true;
    }
    
    for(int i = 1 ; i <= 13 ; i++){
        count = 0; // straight count
        if(heart[i] != 0 && heart[i+1] != 0){
            for(int j = i ; j <= i + 4; j++){
                int n1 = j, n2 = j+1;
                if(n1 > 13) n1 %= 13;
                else if(n2 > 13) n2 %= 13;
                if(heart[n1] > 0 && heart[n2] > 0) count++;
            }
        }
        if(count == 4) return true;
    }
    
    for(int i = 1 ; i <= 13 ; i++){
        count = 0; // straight count
        if(clover[i] != 0 && clover[i+1] != 0){
            for(int j = i ; j <= i + 4; j++){
                int n1 = j, n2 = j+1;
                if(n1 > 13) n1 %= 13;
                else if(n2 > 13) n2 %= 13;
                if(clover[n1] > 0 && clover[n2] > 0) count++;
            }
        }
        if(count == 4) return true;
    }
    return false;
}
bool FourCard(){
    for(int i = 1 ; i <=13 ; i++) if(cnt[i] == 4) return true;
    return false;
}
bool FullHouse(){
    int triple_cnt = 0, pair_cnt = 0;
    for(int i = 1 ; i <= 13 ; i++){
        if(cnt[i] == 3) triple_cnt++;
        else if(cnt[i] == 2) pair_cnt++;
    }
    if(triple_cnt == 2 || (triple_cnt == 1 && pair_cnt >= 1)) return true;
    return false;
}
bool Flush(){
    int count;
    count = 0;
    for(int i = 1 ; i <= 13 ; i++) if(spade[i] > 0) count++;
    if(count >= 5) return true;
    
    count = 0;
    for(int i = 1 ; i <= 13 ; i++) if(diamond[i] > 0) count++;
    if(count >= 5) return true;
    
    count = 0;
    for(int i = 1 ; i <= 13 ; i++) if(heart[i] > 0) count++;
    if(count >= 5) return true;
    
    count = 0;
    for(int i = 1 ; i <= 13 ; i++) if(clover[i] > 0) count++;
    if(count >= 5) return true;
    
    return false;
}
bool Straight(){
    int count;
    for(int i = 1 ; i <= 13 ; i++){
        count = 0; // straight count
        if(cnt[i] != 0 && cnt[i+1] != 0){
            for(int j = i ; j <= i + 4; j++){
                int n1 = j, n2 = j+1;
                if(n1 > 13) n1 %= 13;
                else if(n2 > 13) n2 %= 13;
                if(cnt[n1] > 0 && cnt[n2] > 0) count++;
            }
        }
        if(count == 4) return true;
    }

    return false;
}
bool Triple(){
    int triple_cnt = 0;
    for(int i = 1 ; i <= 13 ; i++) if(cnt[i] == 3) triple_cnt++;
    if(triple_cnt >= 1) return true;
    return false;
}
bool TwoPair(){
    int twopair_cnt = 0;
    for(int i = 1 ; i <=13 ; i++) if(cnt[i] == 2) twopair_cnt++;
    if(twopair_cnt >= 2) return true;
    return false;
}
bool OnePair(){
    int onepair_cnt = 0;
    for(int i = 1 ; i <= 13 ; i++) if(cnt[i] == 2) onepair_cnt++;
    if(onepair_cnt == 1) return true;
    return false;
}
int main(){
    
    int testcase;
    fcin >> testcase;
    while(testcase--){
        spade.assign(14,0); diamond.assign(14,0); heart.assign(14,0); clover.assign(14,0); cnt.assign(14,0);
        for(int i = 0 ; i < 7 ; i++){
            char ch, ch2;
            fcin >> ch >> ch2;
            int num = change(ch2);
            switch (ch) {
                case 'S': spade[num]++; cnt[num]++; break;
                case 'D': diamond[num]++; cnt[num]++; break;
                case 'H': heart[num]++; cnt[num]++; break;
                case 'C': clover[num]++; cnt[num]++; break;
            }
        }
        bool flag = false;
        if(!flag && StraightFlush()){ fcout << "Straight Flush\n"; flag = true;}
        else if(!flag && FourCard()) { fcout << "Four Card\n"; flag = true;}
        else if(!flag && FullHouse()) { fcout << "Full House\n"; flag = true;}
        else if(!flag &&Flush()) { fcout << "Flush\n"; flag = true;}
        else if(!flag && Straight()) { fcout << "Straight\n"; flag = true;}
        else if(!flag && Triple()) { fcout << "Triple\n"; flag = true;}
        else if(!flag &&TwoPair()) { fcout << "Two Pair\n"; flag = true;}
        else if(!flag && OnePair()) { fcout << "One Pair\n"; flag = true;}
        else fcout << "Top\n";
    }
    return 0;
}
