#include "../s21_decimal.h"

int s21_big_ost_10(s21_big_decimal value) {
  s21_big_decimal ten = {0};
  s21_big_decimal det = {0};
  s21_big_decimal detCopy = {0};
  value.bits[7] = 0;
  ten.bits[0] = 10;
  while (s21_big_compare(value, ten) >= 0) {
    int i = 0;
    det = ten;
    detCopy = det;
    s21_big_shift_left(&detCopy, 1);

    while (s21_big_compare(value, detCopy) >= 0) {
      i++;
      s21_big_shift_left(&det, 1);
      s21_big_shift_left(&detCopy, 1);
    }
    value = s21_get_big_mod(value, det);
  }
  return value.bits[0];
}

int s21_big_div_10(s21_big_decimal value_1, int optionalScaleTen,
                   s21_big_decimal *result) {
  s21_big_decimal value_2 = {0};
  value_2.bits[0] = 10;
  s21_set_big_scale(&value_2, optionalScaleTen);

  s21_null_big_decimal(result);
  s21_big_align_scale(&value_1, &value_2);
  int scale = s21_get_big_scale(value_1);
  int s21_sign = s21_get_big_sign(value_1) + s21_get_big_sign(value_2) % 2;
  s21_set_big_sign(&value_1, 0);
  s21_set_big_sign(&value_2, 0);

  s21_big_decimal det = {0}, detCopy = {0};
  int flag = 0;

  if (!s21_check_big_not_zero(value_2)) {
    flag = 3;
  } else {
    while (s21_big_compare(value_1, value_2) >= 0) {
      int i = 0;
      det = value_2;
      detCopy = det;
      s21_big_shift_left(&detCopy, 1);

      while (s21_big_compare(value_1, detCopy) >= 0) {
        i++;
        s21_big_shift_left(&det, 1);
        s21_big_shift_left(&detCopy, 1);
      }
      s21_set_big_bit(result, i, 1);
      value_1 = s21_get_big_mod(value_1, det);
    }
  }
  s21_set_big_scale(result, scale);
  s21_set_big_sign(result, s21_sign);

  return flag;
}