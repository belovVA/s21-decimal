#include "../s21_decimal.h"

// SET_GET_SCALE//
void s21_set_scale(s21_decimal *value, int scale) {
  if (scale >= 0 && scale <= 28) {
    value->bits[3] &= ~(0xFF << 16);
    value->bits[3] |= scale << 16;
  }
}

int s21_get_scale(s21_decimal value) {
  int result = (char)(value.bits[3] >> 16);
  return result;
}

// SET_GET_BIG_SCALE//
void s21_set_big_scale(s21_big_decimal *value, int scale) {
  value->bits[7] &= ~(0xFF << 16);
  value->bits[7] |= scale << 16;
}

int s21_get_big_scale(s21_big_decimal value) {
  int result = (char)(value.bits[7] >> 16);
  return result;
}