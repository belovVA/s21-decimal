#include "../s21_decimal.h"

int s21_round(s21_decimal value, s21_decimal *result) {
  s21_null_decimal(result);
  int flag = 0;

  if (s21_get_scale(value) > 28) {
    flag = 1;
  } else {
    int ost = 0;
    int scale = s21_get_scale(value);
    s21_big_decimal tmp = {0};
    s21_from_dec_to_big(value, &tmp);
    s21_set_big_scale(&tmp, 0);
    s21_big_decimal one = {0};
    one.bits[0] = 1;
    while (scale) {
      ost = s21_big_ost_10(tmp);
      s21_big_div_10(tmp, 0, &tmp);
      if (scale == 1 && ost >= 5) tmp = s21_sum_big(tmp, one);
      scale--;
    }
    flag = s21_from_big_to_dec(tmp, result);
  }

  return flag;
}
