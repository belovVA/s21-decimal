#include "../s21_decimal.h"

// returns
// -1 if big1 < big2,
// 0 if big1 == big2,
// 1 if big1 > big2
int s21_big_compare(s21_big_decimal big1, s21_big_decimal big2) {
  int rez = 0;
  int flag_cicle = 1;

  // сравнение по знаку для ненулевых значений
  if ((s21_get_big_sign(big1) != s21_get_big_sign(big2)) &&
      s21_check_big_not_zero(big1) && s21_check_big_not_zero(big2)) {
    rez += s21_get_big_sign(big2);
    rez -= s21_get_big_sign(big1);
    flag_cicle = 0;
  }

  // сравнение числе по модулю
  for (int j = 223; j >= 0 && flag_cicle; j--) {
    if (s21_get_big_bit(big1, j) < s21_get_big_bit(big2, j)) {
      rez = -1;
      flag_cicle = 0;
    } else if (s21_get_big_bit(big1, j) > s21_get_big_bit(big2, j)) {
      rez = 1;
      flag_cicle = 0;
    }
  }

  // если числа отрицательные -> инверсируем результат сравнения по модулю
  if (s21_get_big_sign(big2) && s21_get_big_sign(big1) && !flag_cicle) {
    rez *= -1;
  }
  return rez;
}

int s21_dec_compare(s21_decimal num1, s21_decimal num2) {
  s21_big_decimal big1 = {0}, big2 = {0};
  s21_from_dec_to_big(num1, &big1);
  s21_from_dec_to_big(num2, &big2);
  s21_big_align_scale(&big1, &big2);
  return s21_big_compare(big1, big2);
}

int s21_big_compare_module_no_scale(s21_big_decimal big1,
                                    s21_big_decimal big2) {
  int rez = 0;
  int flag_cicle = 1;
  s21_set_big_sign(&big1, 0);
  s21_set_big_sign(&big2, 0);
  s21_set_big_scale(&big1, 0);
  s21_set_big_scale(&big2, 0);

  for (int j = 223; j >= 0 && flag_cicle; j--) {
    if (s21_get_big_bit(big1, j) < s21_get_big_bit(big2, j)) {
      rez = -1;
      flag_cicle = 0;
    } else if (s21_get_big_bit(big1, j) > s21_get_big_bit(big2, j)) {
      rez = 1;
      flag_cicle = 0;
    }
  }
  return rez;
}
