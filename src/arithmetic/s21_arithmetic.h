#ifndef S21_ARITHMETIC_H
#define S21_ARITHMETIC_H

// add
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_check_compare_for_add(s21_big_decimal big1, s21_big_decimal big2);

// sub
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
s21_big_decimal minus(s21_big_decimal num1, s21_big_decimal num2);
void s21_invert(s21_big_decimal *num);

// mull
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_big_mul(s21_big_decimal value_1, s21_big_decimal value_2,
                s21_big_decimal *result);

// div
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
s21_big_decimal s21_get_big_mod(s21_big_decimal x, s21_big_decimal y);
int s21_big_div(s21_big_decimal big1, s21_big_decimal big2,
                s21_decimal *result);
int s21_converting_result(s21_big_decimal rezBig, s21_decimal *result,
                          int s21_sign, int scale);
void s21_big_div_processing(s21_big_decimal *big1, s21_big_decimal big2,
                            s21_big_decimal *rezBig);

int s21_upgrade_if_less(s21_big_decimal *big1, s21_big_decimal *big2,
                        s21_big_decimal *rezBig, int *scale);

// s21_big_div_10
int s21_big_ost_10(s21_big_decimal value);
int s21_big_div_10(s21_big_decimal value_1, int optionalScaleTen,
                   s21_big_decimal *result);

#endif  // S21_ARITHMETIC_H