#include "../s21_decimal.h"

// help funcs for converting

int s21_scale_downgrade(s21_big_decimal *n, int *flag) {
  s21_big_decimal one = {0};
  one.bits[0] = 1;
  int ost = 0;
  int ost2 = 0;
  if (s21_get_big_scale(*n)) {
    ost = s21_big_ost_10(*n);
    s21_big_div_10(*n, s21_get_big_scale(*n), n);
    s21_set_big_scale(n, s21_get_big_scale(*n) - 1);
    ost2 = s21_big_ost_10(*n);
  }

  if (s21_get_big_scale(*n) >= 1) {
    if ((ost > 5 || (ost == 5 && ost2 % 2 == 1))) {
      *n = s21_sum_big(*n, one);
      *flag = 2;
    }
    if (ost != 0 && *flag != 2) {
      *flag = 1;
    }

  } else {
    if (ost > 5 || (ost == 5 && ost2 % 2 == 1 && *flag == 0)) {
      *flag = 1;
      *n = s21_sum_big(*n, one);
    } else if (ost > 5 || (ost == 5 && *flag == 1)) {
      *flag = 1;
      *n = s21_sum_big(*n, one);
    }
  }

  return 0;
}

int s21_check_high_bits(s21_big_decimal value_1) {
  int flag = 0;
  if (value_1.bits[6] + value_1.bits[5] + value_1.bits[4] + value_1.bits[3] !=
      0) {
    flag = 1;
  }
  return flag;
}

void s21_convert_proccess(s21_big_decimal value_1, s21_decimal *value_2) {
  for (int i = 0; i < 3; i++) {
    value_2->bits[i] = value_1.bits[i];
  }
  value_2->bits[3] = value_1.bits[7];
}

int s21_scale_upgrade(s21_big_decimal *n) {
  int flag = 0;
  s21_big_decimal tmp = {0};
  tmp.bits[0] = 10;
  int scale = s21_get_big_scale(*n);
  // s21_set_big_scale(&tmp, s21_get_big_scale(*n));
  s21_big_mul(*n, tmp, n);
  s21_set_big_scale(n, scale + 1);

  return flag;
}
