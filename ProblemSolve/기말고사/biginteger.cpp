//
//  biginteger.cpp
//  ProblemSolve
//
//  Created by  JeJn on 2020/06/19.
//  Copyright © 2020  JeJn. All rights reserved.
//

#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#define MAXDIGITS 1000 // 교수님은 보통 10000자리까지 두고 계산함
#define PLUS 1
#define MINUS -1
using namespace std;

struct BigNum {
   char digits[MAXDIGITS];
   int signbit, lastdigit;
};

void addBigNum(BigNum *a, BigNum *b, BigNum *result);
void zeroJustify(BigNum * n);
void initBigNum(BigNum *n);
void subtractBigNum(BigNum *a, BigNum *b, BigNum *result);
int compareBigNum(BigNum *a, BigNum * b);
void multiplyBigNum(BigNum *a, BigNum *b, BigNum *result);
void digitShift(BigNum *n, int d);
void divideBigNum(BigNum *a, BigNum *b, BigNum *result);
void setBigNum(BigNum *n, string num);
void printResult(BigNum *result);

int main() {
   BigNum a, b, result;
   string inA, inB;
   cin >> inA >> inB;
   setBigNum(&a, inA);
   setBigNum(&b, inB);
   divideBigNum(&a, &b, &result);
   printResult(&result);
   return 0;
}

void addBigNum(BigNum *a, BigNum *b, BigNum *result) {
   int carry;

   initBigNum(result);

   if (a->signbit == b->signbit) {
      result->signbit = a->signbit;
   }
   else {
      if (a->signbit == MINUS) {
         a->signbit = PLUS;
         subtractBigNum(b, a, result);
         a->signbit = MINUS;
      }
      else {
         b->signbit = PLUS;
         subtractBigNum(a, b, result);
         b->signbit = MINUS;
      }
      return;
   }
   result->lastdigit = max(a->lastdigit, b->lastdigit) + 1;
   carry = 0;
   for (int i = 0; i <= result->lastdigit; i++) {
      result->digits[i] = (char)(carry + (a->digits[i] + b->digits[i])) % 10;
      carry = (carry + a->digits[i] + b->digits[i]) / 10;
   }
   zeroJustify(result);
}
void zeroJustify(BigNum * n) {
   while (n->lastdigit > 0 && n->digits[n->lastdigit] == 0) {
      n->lastdigit--;
   }
   if (n->lastdigit == 0 && n->digits[0] == 0) {
      n->signbit = PLUS;
   }
}
void initBigNum(BigNum *n) {
   memset(n->digits, 0, sizeof(n->digits));
   n->lastdigit = 0;
   n->signbit = PLUS;
}
void subtractBigNum(BigNum *a, BigNum *b, BigNum *result) {
   int borrow, v;

   initBigNum(result);

   if (a->signbit == MINUS || b->signbit == MINUS) {
      b->signbit *= -1;
      addBigNum(a, b, result);
      b->signbit *= -1;
      return;
   }

   if (compareBigNum(a, b) == PLUS) {
      subtractBigNum(b, a, result);
      result->signbit = MINUS;
      return;
   }

   result->lastdigit = max(a->lastdigit, b->lastdigit);
   borrow = 0;
   for (int i = 0; i <= result->lastdigit; i++) {
      v = a->digits[i] - borrow - b->digits[i];
      if (a->digits[i] > 0) {
         borrow = 0;
      }
      if (v < 0) {
         v += 10;
         borrow = 1;
      }
      result->digits[i] = (char)v % 10;
   }
   zeroJustify(result);
}
int compareBigNum(BigNum *a, BigNum * b) {
   if (a->signbit == MINUS && b->signbit == PLUS) {
      return PLUS;
   }
   if (a->signbit == PLUS && b->signbit == MINUS) {
      return MINUS;
   }
   if (b->lastdigit > a->lastdigit) {
      return PLUS * a->signbit;
   }
   if (a->lastdigit > b->lastdigit) {
      return MINUS * a->signbit;
   }
   for (int i = a->lastdigit; i >= 0; i--) {
      if (a->digits[i] > b->digits[i]) {
         return MINUS * a->signbit;
      }
      if (b->digits[i] > a->digits[i]) {
         return PLUS * a->signbit;
      }
   }
   return 0;
}
void multiplyBigNum(BigNum *a, BigNum *b, BigNum *result) {
   BigNum row, temp;
   initBigNum(result);
   row = *a;
   for (int i = 0; i <= b->lastdigit; i++) {
      for (int j = 1; j <= b->digits[i]; j++) {
         addBigNum(result, &row, &temp);
         *result = temp;
      }
      digitShift(&row, 1);
   }
   result->signbit = a->signbit * b->signbit;
   zeroJustify(result);
}
void digitShift(BigNum *n, int d) {
   if (n->lastdigit == 0 && n->digits[0] == 0) {
      return;
   }
   for (int i = n->lastdigit; i >= 0; i--) {
      n->digits[i + d] = n->digits[i];
   }
   for (int i = 0; i < d; i++) {
      n->digits[i] = 0;
   }
   n->lastdigit = n->lastdigit + d;
}
void divideBigNum(BigNum *a, BigNum *b, BigNum *result) {
   BigNum row, temp;
   int asign, bsign;

   initBigNum(result);
   result->signbit = a->signbit * b->signbit;
   asign = a->signbit;
   bsign = b->signbit;
   a->signbit = PLUS;
   b->signbit = PLUS;
   initBigNum(&row);
   initBigNum(&temp);
   result->lastdigit = a->lastdigit;
   for (int i = a->lastdigit; i >= 0; i--) {
      digitShift(&row, 1);
      row.digits[0] = a->digits[i];
      result->digits[i] = 0;
      while (compareBigNum(&row, b) != PLUS) {
         result->digits[i]++;
         subtractBigNum(&row, b, &temp);
         row = temp;
      }
   }
   zeroJustify(result);
   a->signbit = asign;
   b->signbit = bsign;
}
void setBigNum(BigNum *n, string num) {
   initBigNum(n);
   if (num[0] == '-') {
      n->signbit = MINUS;
      num = num.substr(1, num.length() - 1);
   }
   else {
      n->signbit = PLUS;
   }
   n->lastdigit = num.length() - 1;
   for (int i = n->lastdigit, j = 0; i >= 0; i--, j++) {
      n->digits[i] = num[j] - 48;
   }
}
string setString(BigNum *n) {
   string str = "";
   for (int i = n->lastdigit; i >= 0; i--) {
      str += n->digits[i] + 48;
   }
   return str;
}
void printResult(BigNum *result) {
   if (result->signbit == MINUS) {
      cout << '-';
   }
   for (int i = result->lastdigit; i >= 0; i--) {
      cout << (int)result->digits[i];
   }
}
