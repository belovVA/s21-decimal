#include "../s21_decimal.h"

int s21_is_equal(s21_decimal num1, s21_decimal num2) {
  return s21_dec_compare(num1, num2) ? 0 : 1;
}