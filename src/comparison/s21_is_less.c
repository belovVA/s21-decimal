#include "../s21_decimal.h"

int s21_is_less(s21_decimal num1, s21_decimal num2) {
  int rez;
  if (s21_dec_compare(num1, num2) < 0) {
    rez = 1;
  } else {
    rez = 0;
  }

  return rez;
}