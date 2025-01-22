#include "../s21_decimal.h"

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_big_decimal big1 = {0}, big2 = {0}, bigRez = {0};
  s21_null_decimal(result);
  int signRez = (s21_get_sign(value_1) + s21_get_sign(value_2)) % 2;
  int scaleRez = s21_get_scale(value_1) + s21_get_scale(value_2);

  s21_from_dec_to_big(value_1, &big1);
  s21_from_dec_to_big(value_2, &big2);

  int i = 0;
  while (s21_check_big_not_zero(big2)) {
    if (s21_get_big_bit(big2, i) != 0) {
      bigRez = s21_sum_big(bigRez, big1);
      s21_set_big_bit(&big2, i, 0);
    }
    s21_big_shift_left(&big1, 1);
    i++;
  }

  bigRez.bits[7] = 0;
  s21_set_big_sign(&bigRez, signRez);
  s21_set_big_scale(&bigRez, scaleRez);
  int flag = s21_from_big_to_dec(bigRez, result);
  return flag;
}

int s21_big_mul(s21_big_decimal value_1, s21_big_decimal value_2,
                s21_big_decimal *result) {
  s21_null_big_decimal(result);
  int flag = 0;
  int signRez = (s21_get_big_sign(value_1) + s21_get_big_sign(value_2)) % 2;
  int scaleRez = s21_get_big_scale(value_1) + s21_get_big_scale(value_2);

  int i = 0;
  while (s21_check_big_not_zero(value_2)) {
    if (s21_get_big_bit(value_2, i) != 0) {
      *result = s21_sum_big(*result, value_1);
      s21_set_big_bit(&value_2, i, 0);
    }
    s21_big_shift_left(&value_1, 1);
    i++;
  }

  s21_set_big_sign(result, signRez);
  s21_set_big_scale(result, scaleRez);
  return flag;
}