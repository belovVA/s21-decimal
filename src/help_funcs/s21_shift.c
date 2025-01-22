#include "../s21_decimal.h"

void s21_big_shift_left(s21_big_decimal *num, int count) {
  for (int j = 0; j < count; j++) {
    unsigned memory = 0;
    for (int i = 0; i < 7; ++i) {
      unsigned temp = num->bits[i];
      num->bits[i] <<= 1;
      num->bits[i] |= memory;
      memory = temp >> (32 - 1);
    }
  }
}
