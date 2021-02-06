#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ifstream inp("calendar.inp");
ofstream out("calendar.out");

int input_data[2][5]; // �⵵, ��, ��, ����, ����
int type_num, year, month, day, week, total_result, month_day[2][13];
int result_1, result_2, sum_1, sum_2;
char bar;
string day_of_week;



void pre_month()
{
	result_1 = 1;
	result_2 = 1;

	for (int i = 0; i < 2; i++)
	{
		month_day[i][1] = 31;
		month_day[i][2] = 28;
		month_day[i][3] = 31;
		month_day[i][4] = 30;
		month_day[i][5] = 31;
		month_day[i][6] = 30;
		month_day[i][7] = 31;
		month_day[i][8] = 31;
		month_day[i][9] = 30;
		month_day[i][10] = 31;
		month_day[i][11] = 30;
		month_day[i][12] = 31;
	}

	//�� �������� ���
	result_1 = (input_data[0][0] - 1) * 365 + (input_data[0][0] - 1) / 4 - (input_data[0][0] - 1) / 100 + (input_data[0][0] - 1) / 400;
	result_2 = (input_data[1][0] - 1) * 365 + (input_data[1][0] - 1) / 4 - (input_data[1][0] - 1) / 100 + (input_data[1][0] - 1) / 400;

	// �������� ���
	if ((input_data[0][0] % 4 == 0) && (input_data[0][0] % 100 != 0) || input_data[0][0] % 400 == 0) // �� �ش� �⵵�� �������� Ȯ��
		month_day[0][2] = 29;
	if ((input_data[1][0] % 4 == 0) && (input_data[1][0] % 100 != 0) || input_data[1][0] % 400 == 0) // �� �ش� �⵵�� �������� Ȯ��
		month_day[1][2] = 29;

	// �� ������ ���
	for (int i = 0; i < 2; i++)
	{
		for (int j = 1; j < input_data[i][1]; j++)
		{
			if (i == 0) // 1��° �Է°�
				result_1 += month_day[i][j];
			else // 2��° �Է°�
				result_2 += month_day[i][j];
		}
	}

	sum_1 = result_1;
	sum_2 = result_2;
}

int change_num(string s)
{
	if (s == "Mon") return 0;
	else if (s == "Tue") return 1;
	else if (s == "Wed") return 2;
	else if (s == "Thu") return 3;
	else if (s == "Fri") return 4;
	else if (s == "Sat") return 5;
	else if (s == "Sun") return 6;
}

void type_0()
{
	for (int i = 0; i < 2; i++) {
		inp >> year >> bar >> month >> bar >> day;
		input_data[i][0] = year;
		input_data[i][1] = month;
		input_data[i][2] = day;
	}
	pre_month();

	if (input_data[0][2] > month_day[0][input_data[0][1]]) // ���� ���ڰ� �� �ش� ���� ���ں��� Ŭ ��
	{
		out << -1 << endl;
	}
	else if (input_data[1][2] > month_day[1][input_data[1][1]]) // ���� ���ڰ� �� �ش� ���� ���ں��� Ŭ ��
	{
		out << -1 << endl;
	}
	else
	{
		//�ش� ���� �ϼ� ���
		result_1 += input_data[0][2] - 1; // 1�Ϻ��� �����̴ϱ� -1
		result_2 += input_data[1][2] - 1;

		total_result = result_1 - result_2;
		if (total_result < 0) total_result *= -1;

		out << total_result << endl;
	}
}

void type_1()
{
	// ó�� �Է�
	inp >> year >> bar >> month >> bar >> day;
	input_data[0][0] = year;
	input_data[0][1] = month;
	input_data[0][2] = day;

	// �ι�° �Է�
	inp >> year >> bar >> month >> bar >> week >> bar >> day_of_week;
	input_data[1][0] = year;
	input_data[1][1] = month;
	input_data[1][3] = week;
	input_data[1][4] = change_num(day_of_week);

	pre_month();

	// ���� ó�� 1
	if (input_data[0][2] > month_day[0][input_data[0][1]]) // ���� ���ڰ� �� �ش� ���� ���ں��� Ŭ ��
	{
		out << -1 << endl;
	}
	else
	{
		//�ش� ���� �ϼ� ���
		result_1 += input_data[0][2] - 1;

		while (1)
		{
			if (input_data[1][4] == result_2 % 7) break;
			else result_2++;
		}
		result_2 += (input_data[1][3] - 1) * 7;

		if (result_2 <= sum_2 - 1 || result_2 >= sum_2 + month_day[1][input_data[1][1]])
			out << -1 << endl;
		else
		{
			total_result = result_1 - result_2;
			if (total_result < 0) total_result *= -1;

			out << total_result << endl;
		}
	}
}

void type_2()
{
	inp >> year >> bar >> month >> bar >> week >> bar >> day_of_week;
	input_data[0][0] = year;
	input_data[0][1] = month;
	input_data[0][3] = week;
	input_data[0][4] = change_num(day_of_week);

	inp >> year >> bar >> month >> bar >> day;
	input_data[1][0] = year;
	input_data[1][1] = month;
	input_data[1][2] = day;

	pre_month();

	// ���� ó�� 1
	if (input_data[1][2] > month_day[1][input_data[1][1]]) // ���� ���ڰ� �� �ش� ���� ���ں��� Ŭ ��
	{
		out << -1 << endl;
	}
	else
	{ 
		//�ش� ���� ���
		while (1)
		{
			if (input_data[0][4] == result_1 % 7) break;
			else result_1++;
		}
		result_1 += (input_data[0][3] - 1) * 7;
		
		if (result_1 <= sum_1 - 1 || result_1 >= sum_1 + month_day[0][input_data[0][1]])
			out << -1 << endl;
		else
		{
			result_2 += input_data[1][2] - 1;

			total_result = result_1 - result_2;
			if (total_result < 0) total_result *= -1;

			out << total_result << endl;
		}

	}
}

void type_3()
{
	inp >> year >> bar >> month >> bar >> week >> bar >> day_of_week;
	input_data[0][0] = year;
	input_data[0][1] = month;
	input_data[0][3] = week;
	input_data[0][4] = change_num(day_of_week);

	inp >> year >> bar >> month >> bar >> week >> bar >> day_of_week;
	input_data[1][0] = year;
	input_data[1][1] = month;
	input_data[1][3] = week;
	input_data[1][4] = change_num(day_of_week);

	pre_month();

	while (1)
	{
		if (input_data[0][4] == result_1 % 7) break;
		else result_1++;
	}
	result_1 += (input_data[0][3] - 1) * 7;

	if (result_1 <= sum_1 - 1 || result_1 >= sum_1 + month_day[0][input_data[0][1]])
		out << -1 << endl;
	else
	{
		while (1)
		{
			if (input_data[1][4] == result_2 % 7) break;
			else result_2++;
		}
		result_2 += (input_data[1][3] - 1) * 7; // ���ֿ��� ���� ���������� ���

		if (result_2 <= sum_2 - 1 || result_2 >= sum_2 + month_day[1][input_data[1][1]])
			out << -1 << endl;
		else
		{
			total_result = result_1 - result_2;
			if (total_result < 0) total_result *= -1;

			out << total_result << endl;
		}
	}
}

int main()
{
	while (1)
	{
		inp >> type_num;
		if (type_num == -1) break;
		else if (type_num == 0) type_0();
		else if (type_num == 1) type_1();
		else if (type_num == 2) type_2();
		else if (type_num == 3) type_3();

	}

	return 0;
}