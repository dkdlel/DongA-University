#include <stdio.h>

FILE *inp, *out;
int total_num, team_num, round;
int X, Y, a, b; // X : 1ÆÀ, Y : 2ÆÀ, a : 1ÆÀµæÁ¡, b : 2ÆÀµæÁ¡
char bar;

typedef struct team{
	int rank; // µî¼ö
	int score; // ½ÂÁ¡
	int goal; // °ñµæ½Ç
	int home, away; // È¨ ¾î¿şÀÌ µæÁ¡
}TEAM;

int main() {

	inp = fopen("soccer.inp", "rt");
	out = fopen("soccer.out", "wt");

	TEAM team[42];


	fscanf(inp, "%d\n", &total_num);
	for (int i = 0; i < total_num; i++) 
	{
		for (int n = 1; n <= 40; n++) { // ±¸Á¶Ã¼ ÃÊ±âÈ­
			team[n].rank = 1; // µî¼ö
			team[n].score = 0; // ½ÂÁ¡
			team[n].goal = 0; // °ñ µæ½Ç
			team[n].home = 0; // È¨ °ñµæÁ¡
			team[n].away = 0; // ¾î¿şÀÌ °ñµæÁ¡
		}

		fscanf(inp, "%d %d", &team_num, &round);

		for (int r = 0; r < round; r++) // ¶ó¿îµå ¸¸Å­
		{ 
			for (int j = 0; j < team_num * team_num - team_num; j++) { // ÀÔ·Â
				fscanf(inp, "%d%c%d %d %d", &X, &bar, &Y, &a, &b);
				team[X].away += a; // ¾î¿şÀÌ °ñ
				team[X].goal += a - b; // °ñµæ½Ç
				team[Y].home += b; // È¨ °ñ
				team[Y].goal += b - a; // °ñµæ½Ç
				if (a > b)	team[X].score += 3;
				else if (b > a) team[Y].score += 3;
				else {
					team[X].score += 1;
					team[Y].score += 1;
				}
			}
		}
		

		for (int i = 1; i <= team_num; i++) // ¹®Á¦ Ç®±â
		{
			for (int j = i + 1; j <= team_num; j++) {
				if (team[i].score > team[j].score) { // ¾ÕÂÊ ÆÀ ½ÂÁ¡ÀÌ ³ôÀ» ¶§
					team[j].rank += 1;
				}
				else if (team[i].score < team[j].score) { // µÚÂÊ ÆÀ ½ÂÁ¡ÀÌ ³ôÀ» ¶§
					team[i].rank += 1;
				}
				else { // ½ÂÁ¡ÀÌ °°À» ¶§
					if (team[i].goal > team[j].goal) { //°ñ µæ½Ç ºñ±³
						team[j].rank += 1;
					}
					else if (team[i].goal < team[j].goal) {
						team[i].rank += 1;
					}
					else { // °ñ µæ½ÇÀÌ °°À» ¶§
						if (team[i].away > team[j].away) { // ¾î¿şÀÌ °ñ ºñ±³
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


		fprintf(out, "Test Case #%d:",i+1); // Ãâ·Â
		for (int t = 0; t < team_num; t++) {
			fprintf(out, " %d", team[t+1].rank);
		}
		fprintf(out, "\n");
	}
	

	fclose(inp);
	fclose(out);
	return 0;
}