#include "../s21_decimal.h"

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_big_decimal big1 = {0}, big2 = {0};
  s21_null_decimal(result);

  s21_from_dec_to_big(value_1, &big1);
  s21_from_dec_to_big(value_2, &big2);

  int flag = s21_big_div(big1, big2, result);

  return flag;
}

int s21_big_div(s21_big_decimal big1, s21_big_decimal big2,
                s21_decimal *result) {
  s21_big_decimal rezBig = {0};
  int scale = s21_get_big_scale(big1) - s21_get_big_scale(big2);
  int s21_sign = s21_get_big_sign(big1) + s21_get_big_sign(big2) % 2;
  s21_null_scale_and_sign(&big1, &big2);
  int flag = 0;

  if (!s21_check_big_not_zero(big2)) {
    flag = 3;
  } else {
    while (s21_check_big_not_zero(big1) && scale <= 29 && !flag) {
      s21_big_div_processing(&big1, big2, &rezBig);
      flag = s21_upgrade_if_less(&big1, &big2, &rezBig, &scale);
    }

    if (!flag) {
      flag = s21_converting_result(rezBig, result, s21_sign, scale);
    }
  }

  return flag;
}

void s21_big_div_processing(s21_big_decimal *big1, s21_big_decimal big2,
                            s21_big_decimal *rezBig) {
  s21_big_decimal det = {0}, detCopy = {0}, tempRez = {0};
  while (s21_big_compare_module_no_scale(*big1, big2) >= 0) {
    int i = 0;
    det = big2;
    detCopy = det;
    s21_big_shift_left(&detCopy, 1);

    while (s21_big_compare_module_no_scale(*big1, detCopy) >= 0) {
      i++;
      s21_big_shift_left(&det, 1);
      s21_big_shift_left(&detCopy, 1);
    }
    s21_set_big_bit(&tempRez, i, 1);
    *big1 = s21_get_big_mod(*big1, det);
  }
  *rezBig = s21_sum_big(tempRez, *rezBig);
  s21_null_big_decimal(&tempRez);
}

s21_big_decimal s21_get_big_mod(s21_big_decimal x, s21_big_decimal y) {
  s21_big_decimal borrow = {0};
  while (s21_check_big_not_zero(y)) {
    for (int i = 0; i < 7; i++) {
      borrow.bits[i] = (~x.bits[i]) & y.bits[i];
    }

    for (int i = 0; i < 7; i++) {
      x.bits[i] = x.bits[i] ^ y.bits[i];
    }

    s21_big_shift_left(&borrow, 1);
    y = borrow;
  }
  return x;
}

int s21_converting_result(s21_big_decimal rezBig, s21_decimal *result,
                          int s21_sign, int scale) {
  int flag = 0;
  while (scale < 0) {
    flag = s21_scale_upgrade(&rezBig);
    scale++;
  }
  rezBig.bits[7] = 0;
  s21_set_big_sign(&rezBig, s21_sign);
  s21_set_big_scale(&rezBig, scale);
  flag = s21_from_big_to_dec(rezBig, result);
  if (!s21_check_dec_not_zero(*result)) {
    s21_set_scale(result, 0);
  }
  return flag;
}

int s21_upgrade_if_less(s21_big_decimal *big1, s21_big_decimal *big2,
                        s21_big_decimal *rezBig, int *scale) {
  int flag = 0;
  while (s21_big_compare_module_no_scale(*big1, *big2) == -1 &&
         s21_check_big_not_zero(*big1)) {
    flag = s21_scale_upgrade(big1);
    flag = s21_scale_upgrade(rezBig);
    (*scale)++;
  }
  return flag;
}
