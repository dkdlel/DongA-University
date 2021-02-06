#include <iostream>
#define MAX 10000
using namespace std;

int binary_n1[8], binary_n2[8], digit[15], result, result_decimal;
int booth_multiplier_binary_num[9], booth_multiplicand_binary_num[16]; // multiplier : 승수 multiplicand : 피승수
int shift_binary_n1[16], result_shift_binary_num[16], Cumulative_mul_binary_num[16];
// 자리에 해당하는 숫자 만들기
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
//보수
void complement(int *binary_num, int n) {
	int carry = 1;
	// 1의 보수
	for (int i = n; i > 0; i--) {
		if (binary_num[i] == 0) binary_num[i] = 1;
		else binary_num[i] = 0;
	}
	// 2의 보수
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
// 10진수를 2진수로
void decimal_to_binary(int n1, int n2) {

	bool n1_check = false, n2_check = false;
	// 초기화
	for (int i = 0; i < 8; i++) {
		binary_n1[i] = 0;
		binary_n2[i] = 0;
	}
	// 음수를 양수로
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

	// n1 진법 변환
	for (int i = 7; n1 > 0; i--) {
		binary_n1[i] = n1 % 2;
		n1 /= 2;
	}
	// n2 진법 변환
	for (int i = 7; n2 > 0; i--) {
		binary_n2[i] = n2 % 2;
		n2 /= 2;
	}
}
// 왼쪽 쉬프트
void left_shift(int *binary_num, int n) {

	for (int i = 1; i < n; i++) {
		if (binary_num[i] == 0) continue;
		// 맨 뒤에 범위 넘어가는 것은 버린다
		if (binary_num[i + 1] == MAX) {
			binary_num[i - 1] = binary_num[i];
			binary_num[i] = 0;
			break;
		}
		// 앞에 범위 넘어가는 것도 버린다
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
// 오른쪽 쉬프트
void right_shift(int *binary_num) {

	for (int i = 14; i >= 0; i--) {
		if (binary_num[i] == 0) continue;
		// 맨 뒤에 범위 넘어가는 것은 버린다
		if (binary_num[i + 1] == MAX) {
			binary_num[i] = binary_num[i - 1];
			break;
		}
		// 앞에 범위 넘어가는 것도 버린다
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
// 쉬프트 연산
void shift_add(int n1, int n2) {

	result_decimal = 0;
	int tmp_binary[16] = { 0, };
	// 0 으로 초기화
	for (int i = 0; i < 16; i++) {
		shift_binary_n1[i] = 0;
		result_shift_binary_num[i] = 0;
	}

	// 7자리를 14자리로 늘리기
	for (int i = 1; i <= 7; i++)
		shift_binary_n1[i] = binary_n1[i];
	int shift_binary_n2[8] = { 0, };
	for (int i = 0; i < 8; i++) shift_binary_n2[i] = binary_n2[i];
	// 처음과 끝에 MAX값으로 초기화
	shift_binary_n1[15] = MAX; shift_binary_n1[0] = MAX; 
	//result_shift_binary_num[15] = MAX; result_shift_binary_num[0] = MAX; 
	tmp_binary[15] = MAX; tmp_binary[0] = MAX;
	// 시프트 덧셈 계산
	for(int j =7 ; j > 0 ; j--){
		int carry = 0;
		// 1을 곱하면
		if (shift_binary_n2[j] == 1) {
			// 더할수 계산
			for (int i = 14; i >= 0; i--)
				tmp_binary[i] = shift_binary_n1[i] * shift_binary_n2[j];
			// 누적 부분곱에 더하기
			for (int i = 14; i >= 0; i--) {
				// 올림수가 생기면 ( 합이 2 or 3 )
				if ((tmp_binary[i] + result_shift_binary_num[i] + carry) >= 2) {
					result_shift_binary_num[i] = (tmp_binary[i] + result_shift_binary_num[i] + carry) % 2;
					carry = 1;
				}
				// 올림수가 안생기면 ( 합이 0 or 1 )
				else {
					result_shift_binary_num[i] = tmp_binary[i] + result_shift_binary_num[i] + carry;
					carry = 0;
				}
			}
			right_shift(result_shift_binary_num);
		}
		// 0을 곱하면
		else right_shift(result_shift_binary_num);
	}
	// 음수 양수 표현을 위하여 부호비트 지정
	result_shift_binary_num[0] = (binary_n1[0] + binary_n2[0]) % 2;
	// 2진수를 10진수로
	for (int i = 0; i <= 14; i++)
		result_decimal += result_shift_binary_num[i] * digit[i];
	// 음수이면
	if (result_shift_binary_num[0] == 1) result_decimal *= -1;
}
// 승수가 0 1 이면
void Zero_one() {

	int carry = 0;
	for (int i = 14; i >= 1; i--) {
		// 올림수가 생기면 ( 합이 2 or 3 )
		if (Cumulative_mul_binary_num[i] + booth_multiplicand_binary_num[i] + carry >= 2) {
			Cumulative_mul_binary_num[i] = (Cumulative_mul_binary_num[i] + booth_multiplicand_binary_num[i] + carry) % 2;
			carry = 1;
		}
		// 올림수가 안생기면 ( 합이 0 or 1 )
		else {
			Cumulative_mul_binary_num[i] = Cumulative_mul_binary_num[i] + booth_multiplicand_binary_num[i] + carry;
			carry = 0;
		}
	}
}
 // 승수가 1 0 이면
void One_zero() {
	
	// 누적곱과 피승수 비교
	int carry = 0;
	
	// 피승수 보수
	complement(booth_multiplicand_binary_num, 14);
		
	for (int i = 14; i >= 1; i--) {
		// 올림수가 생기면 ( 합이 2 or 3 )
		if (Cumulative_mul_binary_num[i] + booth_multiplicand_binary_num[i] + carry >= 2) {
			Cumulative_mul_binary_num[i] = (Cumulative_mul_binary_num[i] + booth_multiplicand_binary_num[i] + carry) % 2;
			carry = 1;
		}
		// 올림수가 안생기면 ( 합이 0 or 1 )
		else {
			Cumulative_mul_binary_num[i] = Cumulative_mul_binary_num[i] + booth_multiplicand_binary_num[i] + carry;
			carry = 0;
		}
	}
	complement(booth_multiplicand_binary_num, 14);
}
// 부스 연산
void Booth(int n1, int n2) { // multiplier : 승수 multiplicand : 피승수

	// 피승수 초기화
	for (int i = 1; i < 15; i++) booth_multiplicand_binary_num[i] = 0;

	int i = 14;
	for (int j = 7; j >= 1; j--) {
		booth_multiplicand_binary_num[i] = binary_n1[j];
		i--;
	}
	booth_multiplicand_binary_num[0] = MAX; booth_multiplicand_binary_num[15] = MAX;
	// 승수 초기화
	for (int i = 7; i >= 1; i--)
		booth_multiplier_binary_num[i+1] = binary_n2[i];

	if(n1 < 0)complement(booth_multiplier_binary_num, 8);
	if(n2 < 0)complement(booth_multiplicand_binary_num, 14);

	// 추가 비트 생성
	left_shift(booth_multiplier_binary_num,9);
	
	// 누적곱 초기화
	for (int i = 1; i < 15; i++) Cumulative_mul_binary_num[i] = 0;
	Cumulative_mul_binary_num[0] = MAX; Cumulative_mul_binary_num[15] = MAX;

	for (int i = 8; i >= 1; i--) {
		// 승수가 0 1 이면 < 누적곱 + 피승수 >
		if (booth_multiplier_binary_num[i - 1] == 0 && booth_multiplier_binary_num[i] == 1)
			Zero_one();
		// 승수가 1 0 이면 < 누적곱 - 피승수 >
		else if (booth_multiplier_binary_num[i - 1] == 1 && booth_multiplier_binary_num[i] == 0)
			One_zero();
		// 피승수 왼쪽 shift
		left_shift(booth_multiplicand_binary_num,15);
	}

	// 음수 양수 표현을 위하여 부호비트 지정
	Cumulative_mul_binary_num[0] = (binary_n1[0] + binary_n2[0]) % 2;
}

int main() {

	int total_num; // 전체 경우의 수
	int n1, n2; // 입력받을 두 수
	Digit(14);
	cout << "몇 번 실행 시키시겠습니까? : ";
	cin >> total_num;

	while (total_num--) {
		cout << "두 수를 입력 하세요~ ex) 1 1 : ";
		cin >> n1 >> n2;
		// 숫자 범위를 초과 했을 때
		if (n1 > 127 || n2 > 127 || n1 < -127 || n2 < -127) {
			cout << "숫자 범위를 초과 하였습니다!\n\n";
			continue;
		}
		// 10진수를 2진수로
		decimal_to_binary(n1,n2);
		// 시프트-덧셈 방식
		shift_add(n1,n2);
		Booth(n1,n2);

		cout << "\n시프트-덧셈 알고리즘(2) : ";
		for (int i = 0; i <= 14; i++) cout << result_shift_binary_num[i] <<  " ";
		cout << "\n    Booth 알고리즘      : ";
		for (int i = 0; i <= 14; i++) cout << Cumulative_mul_binary_num[i] <<  " ";
		cout << "\n     십진수 표현        : " << result_decimal << "\n\n";
	}
	return 0;
}