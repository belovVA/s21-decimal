#include "../s21_decimal.h"

int s21_floor(s21_decimal value, s21_decimal *result) {
  s21_null_decimal(result);
  int flag = 1;
  int null_flag = 0;
  s21_big_decimal tmp = {0};

  if (s21_get_scale(value) <= 28) {
    s21_from_dec_to_big(value, &tmp);
    if (s21_get_big_scale(tmp) != 0) {
      while (s21_get_big_scale(tmp) != 0) {
        if (s21_big_ost_10(tmp)) null_flag = 1;
        s21_downgrade_without_round(&tmp);
      }
      if (s21_get_big_sign(tmp) && null_flag) {
        s21_big_decimal tmp2 = {0};
        tmp2.bits[0] = 1;
        tmp = s21_sum_big(tmp, tmp2);
      }
    }

    if (s21_from_big_to_dec(tmp, result) == 0) {
      flag = 0;
    }
  }
  return flag;
}
