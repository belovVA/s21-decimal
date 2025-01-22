#ifndef SRC_S21_BASE_FUNC_H
#define SRC_S21_BASE_FUNC_H

// SET_GET_BIT//
int s21_get_bit(s21_decimal value, int bit);
s21_big_decimal *s21_set_big_bit(s21_big_decimal *value, int pos, int bit);
int s21_get_big_bit(s21_big_decimal value, int bit);

// SET_GET_SIGN//
void s21_set_sign(s21_decimal *value, int s21_sign);
int s21_get_sign(s21_decimal value);
void s21_set_big_sign(s21_big_decimal *value, int s21_sign);
int s21_get_big_sign(s21_big_decimal value);

// SET_GET_SCALE//
void s21_set_scale(s21_decimal *value, int scale);
int s21_get_scale(s21_decimal value);
void s21_set_big_scale(s21_big_decimal *value, int scale);
int s21_get_big_scale(s21_big_decimal value);

// SHIFT//
void s21_big_shift_left(s21_big_decimal *num, int count);

// NULL_DECIMAL//
void s21_null_decimal(s21_decimal *dst);
void s21_null_big_decimal(s21_big_decimal *dst);
void s21_null_scale_and_sign(s21_big_decimal *big1, s21_big_decimal *big2);

// CHECK_ON_ZERO//
int s21_check_big_not_zero(s21_big_decimal numb);
int s21_check_dec_not_zero(s21_decimal numb);

#endif  // SRC_S21_BASE_FUNC_H
