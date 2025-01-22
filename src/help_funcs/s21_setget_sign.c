#include "../s21_decimal.h"

// SET_GET_SIGN//
void s21_set_sign(s21_decimal *value, int s21_sign) {
  value->bits[3] &= ~(1u << 31);
  value->bits[3] |= s21_sign << 31;
}

int s21_get_sign(s21_decimal value) {
  int result = !!(value.bits[3] & (1u << 31));
  return result;
}

// SET_GET_BIG_SIGN//
void s21_set_big_sign(s21_big_decimal *value, int s21_sign) {
  value->bits[7] &= ~(1u << 31);
  value->bits[7] |= s21_sign << 31;
}

int s21_get_big_sign(s21_big_decimal value) {
  int result = !!(value.bits[7] & (1u << 31));
  return result;
}