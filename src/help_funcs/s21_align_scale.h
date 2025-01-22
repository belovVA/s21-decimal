#ifndef S21_ALIGN_SCALE_H
#define S21_ALIGN_SCALE_H

// s21_sum_for_scale
s21_big_decimal s21_sum_big(s21_big_decimal a, s21_big_decimal b);
s21_big_decimal s21_logical_and(s21_big_decimal numb1, s21_big_decimal numb2);
s21_big_decimal s21_logical_xor(s21_big_decimal numb1, s21_big_decimal numb2);

// s21_align_scale
void s21_big_align_scale_procces(int razn, s21_big_decimal *num);
void s21_big_align_scale(s21_big_decimal *num1, s21_big_decimal *num2);

#endif  // S21_ALIGN_SCALE_H