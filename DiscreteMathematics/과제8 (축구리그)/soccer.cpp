#include <stdio.h>

FILE *inp, *out;
int total_num, team_num, round;
int X, Y, a, b; // X : 1��, Y : 2��, a : 1������, b : 2������
char bar;

typedef struct team{
	int rank; // ���
	int score; // ����
	int goal; // ����
	int home, away; // Ȩ ����� ����
}TEAM;

int main() {

	inp = fopen("soccer.inp", "rt");
	out = fopen("soccer.out", "wt");

	TEAM team[42];


	fscanf(inp, "%d\n", &total_num);
	for (int i = 0; i < total_num; i++) 
	{
		for (int n = 1; n <= 40; n++) { // ����ü �ʱ�ȭ
			team[n].rank = 1; // ���
			team[n].score = 0; // ����
			team[n].goal = 0; // �� ���
			team[n].home = 0; // Ȩ �����
			team[n].away = 0; // ����� �����
		}

		fscanf(inp, "%d %d", &team_num, &round);

		for (int r = 0; r < round; r++) // ���� ��ŭ
		{ 
			for (int j = 0; j < team_num * team_num - team_num; j++) { // �Է�
				fscanf(inp, "%d%c%d %d %d", &X, &bar, &Y, &a, &b);
				team[X].away += a; // ����� ��
				team[X].goal += a - b; // ����
				team[Y].home += b; // Ȩ ��
				team[Y].goal += b - a; // ����
				if (a > b)	team[X].score += 3;
				else if (b > a) team[Y].score += 3;
				else {
					team[X].score += 1;
					team[Y].score += 1;
				}
			}
		}
		

		for (int i = 1; i <= team_num; i++) // ���� Ǯ��
		{
			for (int j = i + 1; j <= team_num; j++) {
				if (team[i].score > team[j].score) { // ���� �� ������ ���� ��
					team[j].rank += 1;
				}
				else if (team[i].score < team[j].score) { // ���� �� ������ ���� ��
					team[i].rank += 1;
				}
				else { // ������ ���� ��
					if (team[i].goal > team[j].goal) { //�� ��� ��
						team[j].rank += 1;
					}
					else if (team[i].goal < team[j].goal) {
						team[i].rank += 1;
					}
					else { // �� ����� ���� ��
						if (team[i].away > team[j].away) { // ����� �� ��
							team[j].rank += 1;
						}
						else if(team[i].away < team[j].away){
							team[i].rank += 1;
						}
						else {
							team[i].rank;
							team[j].rank;
						}
					}
				}
			}
		}


		fprintf(out, "Test Case #%d:",i+1); // ���
		for (int t = 0; t < team_num; t++) {
			fprintf(out, " %d", team[t+1].rank);
		}
		fprintf(out, "\n");
	}
	

	fclose(inp);
	fclose(out);
	return 0;
}