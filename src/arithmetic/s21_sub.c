#include "../s21_decimal.h"

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_null_decimal(result);
  s21_big_decimal value1 = {0}, value2 = {0}, res = {0};
  int sign1 = s21_get_sign(value_1), sign2 = s21_get_sign(value_2), fail = 0;

  s21_from_dec_to_big(value_1, &value1);
  s21_from_dec_to_big(value_2, &value2);
  s21_big_align_scale(&value1, &value2);

  if (sign1 == 0 && sign2 == 0) {
    if (s21_is_greater_or_equal(value_1, value_2)) {
      res = minus(value1, value2);
    } else {
      res = minus(value2, value1);
      s21_set_big_sign(&res, 1);
    }
  } else if (sign1 == 0 && sign2 == 1) {
    res = s21_sum_big(value1, value2);
  } else if (sign1 == 1 && sign2 == 0) {
    res = s21_sum_big(value1, value2);
    s21_set_big_sign(&res, 1);
  } else if (sign1 == 1 && sign2 == 1) {
    if (s21_is_greater_or_equal(value_1, value_2)) {
      res = minus(value2, value1);
      if (s21_check_big_not_zero(res)) {
        s21_set_big_sign(&res, 0);
      }
    } else {
      res = minus(value1, value2);
      s21_set_big_sign(&res, 1);
    }
  }
  fail = s21_from_big_to_dec(res, result);
  return fail;
}

s21_big_decimal minus(s21_big_decimal num1, s21_big_decimal num2) {
  s21_big_decimal result = {0};
  s21_big_decimal sum = {0};
  sum.bits[0] = 1;
  s21_invert(&num2);
  sum = s21_sum_big(num2, sum);
  result = s21_sum_big(num1, sum);

  result.bits[7] = num1.bits[7];
  return result;
}

void s21_invert(s21_big_decimal *num) {
  for (int i = 6; i >= 0; i--) {
    num->bits[i] = ~num->bits[i];
  }
}