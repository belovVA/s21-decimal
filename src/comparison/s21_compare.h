#ifndef S21_COMPARE_H
#define S21_COMPARE_H

// main_func
int s21_big_compare(s21_big_decimal big1, s21_big_decimal big2);
int s21_dec_compare(s21_decimal big1, s21_decimal big2);
int s21_big_compare_module_no_scale(s21_big_decimal big1, s21_big_decimal big2);

// s21_compare
int s21_is_less(s21_decimal num1, s21_decimal num2);
int s21_is_less_or_equal(s21_decimal num1, s21_decimal num2);
int s21_is_greater(s21_decimal num1, s21_decimal num2);
int s21_is_greater_or_equal(s21_decimal num1, s21_decimal num2);
int s21_is_equal(s21_decimal num1, s21_decimal num2);
int s21_is_not_equal(s21_decimal num1, s21_decimal num2);

#endif  // S21_COMPARE_H