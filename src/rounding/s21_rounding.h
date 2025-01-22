#ifndef S21_ROUNDING_H
#define S21_ROUNDING_H

int s21_negate(s21_decimal value, s21_decimal *result);
int s21_floor(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);

void s21_downgrade_without_round(s21_big_decimal *n);

#endif  // S21_ROUNDING_H