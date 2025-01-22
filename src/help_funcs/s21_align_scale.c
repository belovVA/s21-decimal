#include "../s21_decimal.h"

void s21_big_align_scale_procces(int razn, s21_big_decimal *num) {
  for (int i = 0; i < razn; i++) {
    s21_big_decimal tmp = *num;
    s21_big_shift_left(num, 3);
    s21_big_shift_left(&tmp, 1);
    *num = s21_sum_big(*num, tmp);
    s21_set_big_scale(num, s21_get_big_scale(*num) + 1);
  }
}

void s21_big_align_scale(s21_big_decimal *num1, s21_big_decimal *num2) {
  int sc1 = s21_get_big_scale(*num1);
  int sc2 = s21_get_big_scale(*num2);
  if (sc1 < sc2) {
    int razn = sc2 - sc1;
    s21_big_align_scale_procces(razn, num1);
  } else if (sc2 < sc1) {
    int razn = sc1 - sc2;
    s21_big_align_scale_procces(razn, num2);
  }
}

s21_big_decimal s21_sum_big(s21_big_decimal a, s21_big_decimal b) {
  s21_big_decimal temp = {0};
  int lastbit = a.bits[7];
  while (s21_check_big_not_zero(b)) {
    temp = s21_logical_and(a, b);
    s21_big_shift_left(&temp, 1);
    a = s21_logical_xor(a, b);
    b = temp;
  }
  a.bits[7] = lastbit;
  return a;
}

s21_big_decimal s21_logical_and(s21_big_decimal numb1, s21_big_decimal numb2) {
  s21_big_decimal rez = {0};
  for (int i = 0; i < 7; i++) {
    rez.bits[i] = numb1.bits[i] & numb2.bits[i];
  }
  return rez;
}

s21_big_decimal s21_logical_xor(s21_big_decimal numb1, s21_big_decimal numb2) {
  s21_big_decimal rez = {0};
  for (int i = 0; i < 7; i++) {
    rez.bits[i] = numb1.bits[i] ^ numb2.bits[i];
  }
  return rez;
}
