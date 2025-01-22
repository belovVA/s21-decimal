#include "../s21_decimal.h"

int s21_from_big_to_dec(s21_big_decimal value_1, s21_decimal *value_2) {
  int result = 0;
  int flag = 0;
  while ((s21_check_high_bits(value_1) && s21_get_big_scale(value_1) != 0) ||
         (!s21_check_high_bits(value_1) && s21_get_big_scale(value_1) > 28)) {
    s21_scale_downgrade(&value_1, &flag);
  }

  if (!s21_check_high_bits(value_1)) {
    s21_convert_proccess(value_1, value_2);
    result = 0;  // влезло

  } else {
    if (s21_get_big_sign(value_1) == 0)
      result = 1;  // не влезло велико
    else
      result = 2;  // не влезло мало
  }

  return result;
}
