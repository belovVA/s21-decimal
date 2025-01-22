#include "../s21_decimal.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int res = 1;
  if (s21_get_scale(src) > 28) {
    res = 1;
  } else {
    s21_decimal truncate = {0};
    s21_truncate(src, &truncate);
    s21_big_decimal tmp = {0};
    s21_from_dec_to_big(truncate, &tmp);
    while (s21_get_big_scale(tmp) != 0) {
      int flag = 0;
      s21_scale_downgrade(&tmp, &flag);
    }
    s21_from_big_to_dec(tmp, &truncate);
    unsigned a = truncate.bits[0];
    if (truncate.bits[1] == 0 && truncate.bits[2] == 0 &&
        s21_get_scale(truncate) == 0 &&
        ((a < 2147483648) || (a == 2147483648 && s21_get_sign(truncate)))) {
      *dst = a;
      if (s21_get_sign(truncate) || s21_get_bit(truncate, 31) == 1) {
        *dst *= -1;
      }
      res = 0;
    }
  }

  return res;
}