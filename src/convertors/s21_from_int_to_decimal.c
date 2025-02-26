#include "../s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int res = 1;
  if (dst) {
    s21_null_decimal(dst);
    if (src < 0) {
      s21_set_sign(dst, 1);
      src *= -1;
    }
    dst->bits[0] = src;
    res = 0;
  }
  return res;
}