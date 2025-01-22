#include "../s21_decimal.h"

void s21_null_decimal(s21_decimal *dst) {
  for (int i = 0; i <= 3; i++) {
    dst->bits[i] = 0;
  }
}

void s21_null_big_decimal(s21_big_decimal *dst) {
  for (int i = 0; i <= 7; i++) {
    dst->bits[i] = 0;
  }
}

void s21_null_scale_and_sign(s21_big_decimal *big1, s21_big_decimal *big2) {
  s21_set_big_scale(big1, 0);
  s21_set_big_scale(big2, 0);

  s21_set_big_sign(big1, 0);
  s21_set_big_sign(big2, 0);
}
