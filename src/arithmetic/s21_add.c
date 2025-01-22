#include "../s21_decimal.h"

int s21_check_compare_for_add(s21_big_decimal big1, s21_big_decimal big2) {
  int rez = 0;
  int flag_cicle = 1;
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

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_null_decimal(result);
  s21_big_decimal big1 = {0}, big2 = {0}, big3 = {0};
  s21_from_dec_to_big(value_1, &big1);
  s21_from_dec_to_big(value_2, &big2);
  s21_from_dec_to_big(*result, &big3);

  s21_big_align_scale(&big1, &big2);

  if (s21_check_compare_for_add(big1, big2) == 1) {
    if ((s21_get_sign(value_1) + s21_get_sign(value_2)) % 2 == 0) {
      big3 = s21_sum_big(big1, big2);
    } else {
      big3 = minus(big1, big2);
    }
    s21_set_big_sign(&big3, s21_get_big_sign(big1));

  } else if (s21_check_compare_for_add(big1, big2) == -1) {
    if ((s21_get_sign(value_1) + s21_get_sign(value_2)) % 2 == 0) {
      big3 = s21_sum_big(big1, big2);
    } else {
      big3 = minus(big2, big1);
    }

    s21_set_big_sign(&big3, s21_get_big_sign(big2));

  } else {
    if ((s21_get_sign(value_1) + s21_get_sign(value_2)) % 2 == 0) {
      big3 = s21_sum_big(big1, big2);
      s21_set_big_sign(&big3, s21_get_big_sign(big1));
    } else {
      s21_null_big_decimal(&big3);
      s21_set_big_scale(&big3, s21_get_big_scale(big1));
    }
  }
  int flag = s21_from_big_to_dec(big3, result);
  return flag;
}
