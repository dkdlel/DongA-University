#include <iostream>
#include <string>
using namespace std;

int result, digit[8], output[3];
string tmp;
int checking, cnt;

// �ڸ��� �ش��ϴ� ���� �����
int Digit(int n) {
	if (n == 1) {
		digit[7] = 1;
		return 1;
	}

	result = 1;
	for (int i = n-1; i > 0; i--)
		result *= 2;
	digit[8-n] = result;

	return Digit(n-1);

}
// ��ȣ�� ��Ʈ
void sign_beat(string binary_number) {

	cout << endl << "��ȣ�� ��Ʈ" << endl;
	// �� ���ڸ��� 0�̸�
	if (binary_number[0] -'0' == 0)
		cout << "��ȣ ��Ʈ : 0 " << endl << "ũ�� ��Ʈ : ";
	// �� ���ڸ��� 1�̸�
	else
		cout << "��ȣ ��Ʈ : 1 " << endl << "ũ�� ��Ʈ : ";

	// 10���� ���
	result = 0;
	for (int i = 1; i < binary_number.length(); i++) {
		cout << binary_number[i] << " ";
		// ���� �̸�
		if (binary_number[i] - '0' == 1) {
			result += digit[i];
		}
	}
	cout << endl;
	// �����̸�
	if (binary_number[0] - '0' == 1) result *= -1;
	// �迭ũ�� Ȯ�ο�
	cnt++;
	output[0] = result;
}
// 1�� ����
void one_complement(string binary_number) {

	cout << endl;
	tmp = binary_number;
	// 0�� 1��, 1�� 0����
	for (int i = 0; i < 8; i++) {
		if (tmp[i] -'0' == 0) tmp[i] = 1 + '0';
		else tmp[i] = 0 + '0';
	}
	// 10���� ���
	result = 0;

	cout << "���� 2���� : ";
	for (int i = 0; i < binary_number.length(); i++)
		cout << binary_number[i] << " ";
	for (int i = 0; i < tmp.length(); i++) {
		// 1 �̸�
		if (tmp[i] - '0' == 1) {
			result += digit[i];
		}
	}
	cout << endl << "1�� ������ �� 2���� : ";
	for (int i = 0; i < binary_number.length(); i++)
		cout << tmp[i] << " ";

	cout << endl;
	// �迭ũ�� Ȯ�ο�
	cnt++;
	// �����̸�
	result *= -1;
	output[1] = result;
}
//2�� ����
void two_complement(string binary_number) {

	cout << endl;
	// �ø���
	int carry = 1;
	// �ڸ��� ���
	for (int i = tmp.size() - 1; i >= 0; i--) {
		if ((tmp[i] + carry) - '0' == 2) {
			tmp[i] = 0 + '0';
			carry = 1;
		}
		else {
			tmp[i] = (tmp[i] + carry);
			carry = 0;
		}
	}
	// 10������ ���
	result = 0;
	cout << "���� 2���� : ";
	for (int i = 0; i < binary_number.length(); i++)
		cout << binary_number[i] << " ";
	cout << endl << "2�� ������ �� 2���� : ";
	for (int i = 0; i < tmp.length(); i++) {
		cout << tmp[i] << " ";
		// 1 �̸�
		if (tmp[i] - '0' == 1) {
			result += digit[i];
		}
	}
	cout << endl << endl;
	// �迭ũ�� Ȯ�ο�
	cnt++;
	// �����̸�
	result *= -1;
	output[2] = result;
}
// �Է¼��� Ȯ���ϱ�
int checking_number(string binary_number) {
	
	for (int i = 0; i < 8; i++) {
		// 0�� 1�̿��� ���� �־��� ��
		if (binary_number[i]-'0' != 0 && binary_number[i]-'0' != 1) {
			return checking = 1;
		}
	}
	// 0�� 1�� ���� ��
	return checking = 0;
}

int main() {

	string binary_number;
	int test_case;
	cout << "��� Ȯ���Ͻðڽ��ϱ�? ";
	cin >> test_case;

	while (test_case--) {

		cnt = 0;
		cout << endl << "2���� �Է� : ";
		cin >> binary_number;

		// 8�ڸ� �Ѿ��� ��
		if (binary_number.length() != 8) {
			cout << "8bit �������� �Է����ּ���." << endl << endl;
			continue;
		}
		// 0�� 1 �̿��� ���ڸ� �־��� ��
		checking_number(binary_number);
		if (checking == 1) {
			cout << "0�� 1�� �Է��� �ּ���." << endl << endl;
			continue;
		}
		// ���� ���� ��
		else{
			// �ڸ��� ����
			Digit(8);
			// ��ȣ�� ��Ʈ
			sign_beat(binary_number);
			//�����̸� ���� ����
			if (binary_number[0] - '0' == 1) {
				// 1�� ����
				one_complement(binary_number);
				// 2�� ����
				two_complement(binary_number);
			}
			// 3���� ��� ���
			cout << "10���� ǥ�� : ";
			for (int i = 0; i < cnt; i++) {
				cout << output[i] << " ";
			}
			cout << endl << endl;
		}
	}
	

	return 0;
}