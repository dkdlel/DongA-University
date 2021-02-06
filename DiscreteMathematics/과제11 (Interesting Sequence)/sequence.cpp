#include <stdio.h>

FILE *inp, *out;
long long int n1, n2, result,cnt;

int main() {

	inp = fopen("sequence.inp", "rt");
	out = fopen("sequence.out", "wt");

	for(int i = 0 ; ; i++) 
	{
		fscanf(inp, "%lld %lld", &n1, &n2);
		result = n1;
		cnt = 1;
		if (n1 < 0 && n2 < 0)
			break;
		while (1) {
			if (result % 2 == 0) // Â¦¼ö
			{
				result /= 2;
				if (result == 1) {
					fprintf(out, "Case %d: A = %lld, limit = %lld, number of terms = %lld\n", i + 1, n1, n2, cnt+1);
					break;
				}
				else if (result > n2) {
					fprintf(out, "Case %d: A = %lld, limit = %lld, number of terms = %lld\n", i + 1, n1, n2, cnt);
					break;
				}
				cnt++;
			}
			else if (result % 2 != 0) // È¦¼ö
			{
				result = 3 * result + 1;
				if (result == 1) {
					fprintf(out, "Case %d: A = %lld, limit = %lld, number of terms = %lld\n", i + 1, n1, n2, cnt+1);
					break;
				}
				else if (result > n2) {
					fprintf(out, "Case %d: A = %lld, limit = %lld, number of terms = %lld\n", i + 1, n1, n2, cnt);
					break;
				}
				cnt++;
			}
		}
	}
	
	fclose(inp);
	fclose(out);
	return 0;
}