#include <iostream>
#include <string>
using namespace std;

int result, digit[8], output[3];
string tmp;
int checking, cnt;

// 자리에 해당하는 숫자 만들기
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
// 부호와 비트
void sign_beat(string binary_number) {

	cout << endl << "부호와 비트" << endl;
	// 맨 앞자리가 0이면
	if (binary_number[0] -'0' == 0)
		cout << "부호 비트 : 0 " << endl << "크기 비트 : ";
	// 맨 앞자리가 1이면
	else
		cout << "부호 비트 : 1 " << endl << "크기 비트 : ";

	// 10진수 계산
	result = 0;
	for (int i = 1; i < binary_number.length(); i++) {
		cout << binary_number[i] << " ";
		// 음수 이면
		if (binary_number[i] - '0' == 1) {
			result += digit[i];
		}
	}
	cout << endl;
	// 음수이면
	if (binary_number[0] - '0' == 1) result *= -1;
	// 배열크기 확인용
	cnt++;
	output[0] = result;
}
// 1의 보수
void one_complement(string binary_number) {

	cout << endl;
	tmp = binary_number;
	// 0은 1로, 1은 0으로
	for (int i = 0; i < 8; i++) {
		if (tmp[i] -'0' == 0) tmp[i] = 1 + '0';
		else tmp[i] = 0 + '0';
	}
	// 10진수 계산
	result = 0;

	cout << "기존 2진수 : ";
	for (int i = 0; i < binary_number.length(); i++)
		cout << binary_number[i] << " ";
	for (int i = 0; i < tmp.length(); i++) {
		// 1 이면
		if (tmp[i] - '0' == 1) {
			result += digit[i];
		}
	}
	cout << endl << "1의 보수를 한 2진수 : ";
	for (int i = 0; i < binary_number.length(); i++)
		cout << tmp[i] << " ";

	cout << endl;
	// 배열크기 확인용
	cnt++;
	// 음수이면
	result *= -1;
	output[1] = result;
}
//2의 보수
void two_complement(string binary_number) {

	cout << endl;
	// 올림수
	int carry = 1;
	// 자리수 계산
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
	// 10진수로 계산
	result = 0;
	cout << "기존 2진수 : ";
	for (int i = 0; i < binary_number.length(); i++)
		cout << binary_number[i] << " ";
	cout << endl << "2의 보수를 한 2진수 : ";
	for (int i = 0; i < tmp.length(); i++) {
		cout << tmp[i] << " ";
		// 1 이면
		if (tmp[i] - '0' == 1) {
			result += digit[i];
		}
	}
	cout << endl << endl;
	// 배열크기 확인용
	cnt++;
	// 음수이면
	result *= -1;
	output[2] = result;
}
// 입력숫자 확인하기
int checking_number(string binary_number) {
	
	for (int i = 0; i < 8; i++) {
		// 0과 1이외의 수를 넣었을 때
		if (binary_number[i]-'0' != 0 && binary_number[i]-'0' != 1) {
			return checking = 1;
		}
	}
	// 0과 1만 있을 때
	return checking = 0;
}

int main() {

	string binary_number;
	int test_case;
	cout << "몇개를 확인하시겠습니까? ";
	cin >> test_case;

	while (test_case--) {

		cnt = 0;
		cout << endl << "2진수 입력 : ";
		cin >> binary_number;

		// 8자리 넘었을 때
		if (binary_number.length() != 8) {
			cout << "8bit 이진수를 입력해주세요." << endl << endl;
			continue;
		}
		// 0과 1 이외의 숫자를 넣었을 때
		checking_number(binary_number);
		if (checking == 1) {
			cout << "0과 1을 입력해 주세요." << endl << endl;
			continue;
		}
		// 예외 없을 때
		else{
			// 자리수 설정
			Digit(8);
			// 부호와 비트
			sign_beat(binary_number);
			//음수이면 보수 실행
			if (binary_number[0] - '0' == 1) {
				// 1의 보수
				one_complement(binary_number);
				// 2의 보수
				two_complement(binary_number);
			}
			// 3개의 결과 출력
			cout << "10진수 표현 : ";
			for (int i = 0; i < cnt; i++) {
				cout << output[i] << " ";
			}
			cout << endl << endl;
		}
	}
	

	return 0;
}