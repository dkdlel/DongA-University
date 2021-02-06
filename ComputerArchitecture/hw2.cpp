#include <iostream>
#define MAX 10000
using namespace std;

int binary_n1[8], binary_n2[8], digit[15], result, result_decimal;
int booth_multiplier_binary_num[9], booth_multiplicand_binary_num[16]; // multiplier : �¼� multiplicand : �ǽ¼�
int shift_binary_n1[16], result_shift_binary_num[16], Cumulative_mul_binary_num[16];
// �ڸ��� �ش��ϴ� ���� �����
int Digit(int n) {
	if (n == 1) {
		digit[14] = 1;
		return 1;
	}

	result = 1;
	for (int i = n - 1; i > 0; i--)
		result *= 2;
	digit[15 - n] = result;

	return Digit(n - 1);

}
//����
void complement(int *binary_num, int n) {
	int carry = 1;
	// 1�� ����
	for (int i = n; i > 0; i--) {
		if (binary_num[i] == 0) binary_num[i] = 1;
		else binary_num[i] = 0;
	}
	// 2�� ����
	for (int i = n; i > 0; i--) {
		
		if (binary_num[i] + carry == 2) {
			carry = 1;
			binary_num[i] = 0;
		}
		else {
			binary_num[i] += carry;
			break;
		}
	}
}
// 10������ 2������
void decimal_to_binary(int n1, int n2) {

	bool n1_check = false, n2_check = false;
	// �ʱ�ȭ
	for (int i = 0; i < 8; i++) {
		binary_n1[i] = 0;
		binary_n2[i] = 0;
	}
	// ������ �����
	if (n1 < 0) {
		binary_n1[0] = 1;
		n1 *= -1;
		n1_check = true;
	}
	if (n2 < 0) {
		binary_n2[0] = 1;
		n2 *= -1;
		n2_check = true;
	}

	// n1 ���� ��ȯ
	for (int i = 7; n1 > 0; i--) {
		binary_n1[i] = n1 % 2;
		n1 /= 2;
	}
	// n2 ���� ��ȯ
	for (int i = 7; n2 > 0; i--) {
		binary_n2[i] = n2 % 2;
		n2 /= 2;
	}
}
// ���� ����Ʈ
void left_shift(int *binary_num, int n) {

	for (int i = 1; i < n; i++) {
		if (binary_num[i] == 0) continue;
		// �� �ڿ� ���� �Ѿ�� ���� ������
		if (binary_num[i + 1] == MAX) {
			binary_num[i - 1] = binary_num[i];
			binary_num[i] = 0;
			break;
		}
		// �տ� ���� �Ѿ�� �͵� ������
		else if (binary_num[i - 1] == MAX) {
			binary_num[i] = binary_num[i + 1];
			continue;
		}
		else {
			binary_num[i - 1] = binary_num[i];
			binary_num[i] = binary_num[i + 1];
		}
	}

}
// ������ ����Ʈ
void right_shift(int *binary_num) {

	for (int i = 14; i >= 0; i--) {
		if (binary_num[i] == 0) continue;
		// �� �ڿ� ���� �Ѿ�� ���� ������
		if (binary_num[i + 1] == MAX) {
			binary_num[i] = binary_num[i - 1];
			break;
		}
		// �տ� ���� �Ѿ�� �͵� ������
		else if (binary_num[i - 1] == MAX) {
			binary_num[i + 1] = binary_num[i];
			binary_num[i] = 0;
			continue;
		}
		else {
			binary_num[i + 1] = binary_num[i];
			binary_num[i] = binary_num[i - 1];
		}
	}
}
// ����Ʈ ����
void shift_add(int n1, int n2) {

	result_decimal = 0;
	int tmp_binary[16] = { 0, };
	// 0 ���� �ʱ�ȭ
	for (int i = 0; i < 16; i++) {
		shift_binary_n1[i] = 0;
		result_shift_binary_num[i] = 0;
	}

	// 7�ڸ��� 14�ڸ��� �ø���
	for (int i = 1; i <= 7; i++)
		shift_binary_n1[i] = binary_n1[i];
	int shift_binary_n2[8] = { 0, };
	for (int i = 0; i < 8; i++) shift_binary_n2[i] = binary_n2[i];
	// ó���� ���� MAX������ �ʱ�ȭ
	shift_binary_n1[15] = MAX; shift_binary_n1[0] = MAX; 
	//result_shift_binary_num[15] = MAX; result_shift_binary_num[0] = MAX; 
	tmp_binary[15] = MAX; tmp_binary[0] = MAX;
	// ����Ʈ ���� ���
	for(int j =7 ; j > 0 ; j--){
		int carry = 0;
		// 1�� ���ϸ�
		if (shift_binary_n2[j] == 1) {
			// ���Ҽ� ���
			for (int i = 14; i >= 0; i--)
				tmp_binary[i] = shift_binary_n1[i] * shift_binary_n2[j];
			// ���� �κа��� ���ϱ�
			for (int i = 14; i >= 0; i--) {
				// �ø����� ����� ( ���� 2 or 3 )
				if ((tmp_binary[i] + result_shift_binary_num[i] + carry) >= 2) {
					result_shift_binary_num[i] = (tmp_binary[i] + result_shift_binary_num[i] + carry) % 2;
					carry = 1;
				}
				// �ø����� �Ȼ���� ( ���� 0 or 1 )
				else {
					result_shift_binary_num[i] = tmp_binary[i] + result_shift_binary_num[i] + carry;
					carry = 0;
				}
			}
			right_shift(result_shift_binary_num);
		}
		// 0�� ���ϸ�
		else right_shift(result_shift_binary_num);
	}
	// ���� ��� ǥ���� ���Ͽ� ��ȣ��Ʈ ����
	result_shift_binary_num[0] = (binary_n1[0] + binary_n2[0]) % 2;
	// 2������ 10������
	for (int i = 0; i <= 14; i++)
		result_decimal += result_shift_binary_num[i] * digit[i];
	// �����̸�
	if (result_shift_binary_num[0] == 1) result_decimal *= -1;
}
// �¼��� 0 1 �̸�
void Zero_one() {

	int carry = 0;
	for (int i = 14; i >= 1; i--) {
		// �ø����� ����� ( ���� 2 or 3 )
		if (Cumulative_mul_binary_num[i] + booth_multiplicand_binary_num[i] + carry >= 2) {
			Cumulative_mul_binary_num[i] = (Cumulative_mul_binary_num[i] + booth_multiplicand_binary_num[i] + carry) % 2;
			carry = 1;
		}
		// �ø����� �Ȼ���� ( ���� 0 or 1 )
		else {
			Cumulative_mul_binary_num[i] = Cumulative_mul_binary_num[i] + booth_multiplicand_binary_num[i] + carry;
			carry = 0;
		}
	}
}
 // �¼��� 1 0 �̸�
void One_zero() {
	
	// �������� �ǽ¼� ��
	int carry = 0;
	
	// �ǽ¼� ����
	complement(booth_multiplicand_binary_num, 14);
		
	for (int i = 14; i >= 1; i--) {
		// �ø����� ����� ( ���� 2 or 3 )
		if (Cumulative_mul_binary_num[i] + booth_multiplicand_binary_num[i] + carry >= 2) {
			Cumulative_mul_binary_num[i] = (Cumulative_mul_binary_num[i] + booth_multiplicand_binary_num[i] + carry) % 2;
			carry = 1;
		}
		// �ø����� �Ȼ���� ( ���� 0 or 1 )
		else {
			Cumulative_mul_binary_num[i] = Cumulative_mul_binary_num[i] + booth_multiplicand_binary_num[i] + carry;
			carry = 0;
		}
	}
	complement(booth_multiplicand_binary_num, 14);
}
// �ν� ����
void Booth(int n1, int n2) { // multiplier : �¼� multiplicand : �ǽ¼�

	// �ǽ¼� �ʱ�ȭ
	for (int i = 1; i < 15; i++) booth_multiplicand_binary_num[i] = 0;

	int i = 14;
	for (int j = 7; j >= 1; j--) {
		booth_multiplicand_binary_num[i] = binary_n1[j];
		i--;
	}
	booth_multiplicand_binary_num[0] = MAX; booth_multiplicand_binary_num[15] = MAX;
	// �¼� �ʱ�ȭ
	for (int i = 7; i >= 1; i--)
		booth_multiplier_binary_num[i+1] = binary_n2[i];

	if(n1 < 0)complement(booth_multiplier_binary_num, 8);
	if(n2 < 0)complement(booth_multiplicand_binary_num, 14);

	// �߰� ��Ʈ ����
	left_shift(booth_multiplier_binary_num,9);
	
	// ������ �ʱ�ȭ
	for (int i = 1; i < 15; i++) Cumulative_mul_binary_num[i] = 0;
	Cumulative_mul_binary_num[0] = MAX; Cumulative_mul_binary_num[15] = MAX;

	for (int i = 8; i >= 1; i--) {
		// �¼��� 0 1 �̸� < ������ + �ǽ¼� >
		if (booth_multiplier_binary_num[i - 1] == 0 && booth_multiplier_binary_num[i] == 1)
			Zero_one();
		// �¼��� 1 0 �̸� < ������ - �ǽ¼� >
		else if (booth_multiplier_binary_num[i - 1] == 1 && booth_multiplier_binary_num[i] == 0)
			One_zero();
		// �ǽ¼� ���� shift
		left_shift(booth_multiplicand_binary_num,15);
	}

	// ���� ��� ǥ���� ���Ͽ� ��ȣ��Ʈ ����
	Cumulative_mul_binary_num[0] = (binary_n1[0] + binary_n2[0]) % 2;
}

int main() {

	int total_num; // ��ü ����� ��
	int n1, n2; // �Է¹��� �� ��
	Digit(14);
	cout << "�� �� ���� ��Ű�ðڽ��ϱ�? : ";
	cin >> total_num;

	while (total_num--) {
		cout << "�� ���� �Է� �ϼ���~ ex) 1 1 : ";
		cin >> n1 >> n2;
		// ���� ������ �ʰ� ���� ��
		if (n1 > 127 || n2 > 127 || n1 < -127 || n2 < -127) {
			cout << "���� ������ �ʰ� �Ͽ����ϴ�!\n\n";
			continue;
		}
		// 10������ 2������
		decimal_to_binary(n1,n2);
		// ����Ʈ-���� ���
		shift_add(n1,n2);
		Booth(n1,n2);

		cout << "\n����Ʈ-���� �˰���(2) : ";
		for (int i = 0; i <= 14; i++) cout << result_shift_binary_num[i] <<  " ";
		cout << "\n    Booth �˰���      : ";
		for (int i = 0; i <= 14; i++) cout << Cumulative_mul_binary_num[i] <<  " ";
		cout << "\n     ������ ǥ��        : " << result_decimal << "\n\n";
	}
	return 0;
}