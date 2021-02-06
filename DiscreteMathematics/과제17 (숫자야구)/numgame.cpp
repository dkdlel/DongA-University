#include <iostream>
#include <fstream>
using namespace std;

ifstream inp("numgame.inp");
ofstream out("numgame.out");

int total_num, case_num, arr[3024], num, strike, ball, check_strike, check_ball;
int input_num, output[100],cnt=0;

void make_num() { // 1234 ~ 9876 까지의 배열 생성

	int i = 0, input_num=1233;

	while(1) {

		input_num++;
		// 0인지 확인
		if (input_num / 1000 == 0 || input_num / 1000 == (input_num / 100) % 10 || input_num / 1000 == (input_num / 10) % 10 || input_num / 1000 == input_num % 10) continue;
		else if ((input_num / 100) % 10 == 0 || (input_num / 100) % 10 == input_num / 1000 || (input_num / 100) % 10 == (input_num / 10) % 10 || (input_num / 100) % 10 == input_num % 10) continue;
		else if ((input_num / 10) % 10 == 0 || (input_num / 10) % 10 == input_num / 1000 || (input_num / 10) % 10 == (input_num / 100) % 10 || (input_num / 10) % 10 == input_num % 10) continue;
		else if (input_num % 10 == 0 || input_num % 10 == input_num / 1000 || input_num % 10 == (input_num / 100) % 10 || input_num % 10 ==(input_num / 10) % 10) continue;

		arr[i] = input_num;
		if (input_num == 9876) break;
		i++;
	}

}
void strike_check(int j) { // strike 확인
	check_strike = 0;
	// 각 자리수 확인
	if (arr[j] / 1000 == num / 1000) check_strike++;
	if ((arr[j] / 100)%10 == (num / 100)%10) check_strike++;
	if ((arr[j] / 10) % 10 == (num / 10) % 10) check_strike++;
	if (arr[j] % 10 == num % 10) check_strike++;

}
void ball_check(int j) { // ball 확인
	check_ball = 0;
	// 천의 자리수 확인
	if ( num / 1000 == (arr[j] / 100) % 10) check_ball++;
	if ( num / 1000 == (arr[j] / 10) % 10) check_ball++;
	if ( num / 1000 == arr[j] % 10) check_ball++;

	// 백의 자리수 확인
	if ((num / 100) % 10 == arr[j] / 1000) check_ball++;
	if ((num / 100) % 10 == (arr[j] / 10) % 10) check_ball++;
	if ((num / 100) % 10 == arr[j] % 10) check_ball++;

	// 십의 자리수 확인
	if ((num / 10) % 10 == arr[j] / 1000) check_ball++;
	if ((num / 10) % 10 == (arr[j] / 100) % 10) check_ball++;
	if ((num / 10) % 10 == arr[j] % 10) check_ball++;

	// 일의 자리수 확인
	if (num % 10 == arr[j] / 1000) check_ball++;
	if (num % 10 == (arr[j] / 100) % 10) check_ball++;
	if (num % 10 == (arr[j] / 10) % 10) check_ball++;

}
int main() {

	inp >> total_num; // 전체 case

	while (total_num--) {
		make_num();
		inp >> case_num; // 경우의수 case
		for (int i = 0; i < case_num; i++) {
			inp >> num >> strike >> ball;
			for (int j = 0; j < 3024; j++) {
				if (arr[j] == 0) continue;
				strike_check(j);
				ball_check(j);
				if (check_strike != strike || check_ball != ball) arr[j] = 0;
			}
		}
		cnt = 0;
		for (int i = 0; i < 3024; i++) if (arr[i] != 0) cnt++;

		out << cnt << endl;

		int j = 0;
		for(int i = 0 ; i < 3024; i++) {
			if (cnt <= 6) {
				if (arr[i] != 0)
					out << arr[i] << endl;
			}
			else {
				if (arr[i] != 0) {
					output[j] = arr[i];
					j++;
				}
			}
		}
		if (cnt > 6) {
			for (int i = 0; i < 3; i++) out << output[i] << endl;
			for (int i = cnt-3; i < cnt; i++) out << output[i] << endl;
		}
	}

	return 0;
}


/* 철현쓰
#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<string> bucket;

void Init(){
for(char i = '1'; i <= '9'; i++){
for(char j = '1'; j <= '9'; j++){
if(i == j) continue;
for(char k = '1'; k <= '9'; k++){
if(i == k||j == k) continue;
string s = "";
s += i;
s += j;
s += k;
bucket.push_back(s);
}
}
}
}

int StrikeCheck(string operend, string op){
int cnt = 0;
for(int i = 0; i < 3; i++)
if(operend[i] == op[i]) cnt++;
return cnt;
}

int BallCheck(string operend, string op){
int cnt = 0;
for(int i = 0; i < 3; i++)
for(int j = 0; j < 3; j++)
if(i != j && operend[j] == op[i]) cnt++;
return cnt;
}

void QuestionUpdate(string num, int strike, int ball){
vector<string> newBucket;
for(int i = 0; i < bucket.size(); i++){
if(StrikeCheck(bucket[i], num) == strike && BallCheck(bucket[i], num) == ball)
newBucket.push_back(bucket[i]);
}
bucket = newBucket;
}

int main(){
int Q;
cin >> Q;
Init();
while(Q—){
string num;
int strike, ball;
cin >> num >> strike >> ball;
QuestionUpdate(num, strike, ball);
}
cout << bucket.size();
return 0;
}
*/