#include "../s21_decimal.h"

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int result = 1;
  double tmp = 0.0;
  for (int i = 0; i < 96; i++) {
    if (s21_get_bit(src, i)) {
      tmp += pow(2, i);
    }
  }

  for (int i = 0; i < s21_get_scale(src); i++) {
    tmp /= 10.0;
  }

  *dst = (float)tmp;
  if (s21_get_sign(src)) *dst *= -1;
  result = 0;
  return result;
}
