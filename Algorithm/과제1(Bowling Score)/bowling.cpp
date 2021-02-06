#include<bits/stdc++.h>
using namespace std;

ifstream fcin("bowling.inp");
ofstream fcout("bowling.out");

typedef struct score {
	int first, second, third;
}score;

class Bowling {
public:
	vector<score> board;
	int total_score;
	void reset();
	void Input();
	void Cal_Score();
};
void Bowling::reset() {
	board.resize(10);
	for (int i = 0; i < 10; i++) {
		board[i].first = board[i].second = board[i].third = -1;
	}
}
void Bowling::Input() {
	for (int i = 0; i < 10; i++) {
		int num;
		fcin >> num;
		board[i].first = num;
		if (num != 10) { // not strike
			fcin >> num;
			board[i].second = num;
		}
		if (board[9].first == 10) {
			fcin >> num;
			board[i].second = num;
			fcin >> num;
			board[i].third = num;
		}
		if (board[9].first + board[9].second == 10) { // last frame
			fcin >> num;
			board[i].third = num;
		}
	}
}
void Bowling::Cal_Score() {
	total_score = 0;
	for (int i = 0; i < 9; i++) {
		int cnt = 0, tmp = 0;
		if (board[i].first == 10) { // strike
			for (int j = i + 1; ; j++) {
				if (board[j].first != -1) {
					cnt++;
					tmp += board[j].first;
				}
				if (cnt == 2) break;
				if (board[j].second != -1) {
					cnt++;
					tmp += board[j].second;
				}
				if (cnt == 2) break;
			}
			total_score += tmp + 10;
		}
		else if (board[i].first + board[i].second == 10) { // spare
			total_score += board[i + 1].first + 10;
		}
		else { // etc
			total_score += board[i].first + board[i].second;
		}
	}
	total_score += board[9].first + board[9].second;
	if (board[9].third != -1) total_score += board[9].third;

	fcout << total_score << "\n";
}
int main() {
	Bowling bowling;
	int total;
	fcin >> total;
	for (int i = 0; i < total; i++) {
		bowling.reset();
		bowling.Input();
		bowling.Cal_Score();
	}
	return 0;
}