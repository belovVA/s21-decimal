#include "../s21_decimal.h"

int s21_check_big_not_zero(s21_big_decimal numb) {
  int flag = 0;
  for (int i = 0; i < 7 && !flag; i++) {
    if (numb.bits[i] != 0) {
      flag = 1;
    }
  }
  return flag;
}

int s21_check_dec_not_zero(s21_decimal numb) {
  int flag = 0;
  for (int i = 0; i < 3 && !flag; i++) {
    if (numb.bits[i] != 0) {
      flag = 1;
    }
  }
  return flag;
}