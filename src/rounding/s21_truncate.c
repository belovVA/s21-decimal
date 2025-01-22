#include "../s21_decimal.h"

int s21_truncate(s21_decimal value, s21_decimal *result) {
  s21_null_decimal(result);

  s21_big_decimal tmp = {0};
  int flag = 1;

  if (s21_get_scale(value) <= 28) {
    s21_from_dec_to_big(value, &tmp);

    while (s21_get_big_scale(tmp) != 0) {
      s21_downgrade_without_round(&tmp);
    }

    if (s21_from_big_to_dec(tmp, result) == 0) {
      flag = 0;
    }
  }

  return flag;
}

void s21_downgrade_without_round(s21_big_decimal *n) {
  if (s21_get_big_scale(*n)) {
    s21_big_div_10(*n, s21_get_big_scale(*n), n);
    s21_set_big_scale(n, s21_get_big_scale(*n) - 1);
  }
}