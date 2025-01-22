#include "../s21_decimal.h"

void s21_from_dec_to_big(s21_decimal src, s21_big_decimal *dst) {
  s21_null_big_decimal(dst);
  dst->bits[7] = src.bits[3];
  for (int i = 0; i < 3; i++) {
    dst->bits[i] = src.bits[i];
  }
}