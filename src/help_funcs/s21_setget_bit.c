#include "../s21_decimal.h"

// SET_GET_BIT//
int s21_get_bit(s21_decimal value, int bit) {
  return !!(value.bits[bit / 32] & (1u << (bit % 32)));
}

// SET_GET_BIG_BIT//
s21_big_decimal *s21_set_big_bit(s21_big_decimal *value, int pos, int bit) {
  if (pos / 32 < 8 && bit)
    value->bits[pos / 32] |= (1u << (pos % 32));
  else if (pos / 32 < 8 && !bit)
    value->bits[pos / 32] &= ~(1u << (pos % 32));
  return value;
}

int s21_get_big_bit(s21_big_decimal value, int bit) {
  return !!(value.bits[bit / 32] & (1u << (bit % 32)));
}